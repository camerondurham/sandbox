#include<memory>
#include<iostream>

class C
{
  public:
  C(int i, double d)
  : mI(i)
  ,mD(d)
  {}
  int GetI() const {return mI;}
  private:
  double mI;
  double mD;
};

template <typename T>
class UniquePtr
{
public:
// assumes we don't pass in the same pointer to multiple uniques!
  UniquePtr(T* data)
  :mData(data)
  {}

  ~UniquePtr()
  {
    delete mData;
  }

  // Disallow copy and copy assignment
  // = delete: don't want a copy constructor at all
  UniquePtr(const UniquePtr<T>& other) = delete;
  UniquePtr<T>& operator=(const UniquePtr<T>& other) = delete;

  // allow moves for ownership transferrence
  UniquePtr(UniquePtr<T>&& other)
  :mData(std::move(other.mData))
  {
    other.mData = nullptr;
  }

  // Ditto for move assignment
  // ...



  T* operator*()
  {
    return *mData;
  }
  T* operator->()
  {
    return mData;
  }

private:
  T* mData;

};

struct ControlBlock
{
  unsigned mStrongRefs = 0;
};


template <typename T>
class SharedPtr
{
public:
// assumes we don't pass in the same pointer to multiple uniques!
  SharedPtr(T* data)
  :mData(data)
  ,mBlock(new ControlBlock)
  {
    // We're the first shared ptr, so strong ref count is 1!
    mBlock->mStrongRefs = 1;
  }

  ~SharedPtr()
  {
    mBlock->mStrongRefs--;
    // Only delete if there are no more strong references
    if(mBlock->mStrongRefs == 0)
    {
      delete mData;
      delete mBlock;
    }
  }

  // Disallow copy and copy assignment
  // = delete: don't want a copy constructor at all
  SharedPtr(const SharedPtr<T>& other)
  :mData(other.mData)
  ,mBlock(other.mBlock)
  {
    // increase reference count since we're referring to an existing heap object
    other.mBlock->mStrongRefs++;
  }

  SharedPtr<T>& operator=(const SharedPtr<T>& other)
  {

  }

  // allow moves for reference transferrence
  SharedPtr(SharedPtr<T>&& other)
  :mData(std::move(other.mData))
  ,mBlock(std::move(other.mBlock))
  {
    other.mData = nullptr;
    other.mBlock = nullptr;
  }

  // Ditto for move assignment
  // ...



  T* operator*()
  {
    return *mData;
  }
  T* operator->()
  {
    return mData;
  }

private:
  T* mData;
  ControlBlock* mBlock;
};

// don't want to allow copy of this
// this function will copy a pointer and crash bc of a double free
// allowed if we **move** the object
void fm(UniquePtr<C> cptr)
{
}

void f(UniquePtr<C>&& cptr)
{

}


struct B
{
  B(std::shared_ptr<struct A> a);
  std::shared_ptr<struct A> ptrB;


};

// only needed if you're going to return a shared pointer to yourself
struct A : std::enable_shared_from_this<A>
{
  A()
  {
    // NOTE: why can't we just return a shared_ptr<A>(this)?
    // cannot return shared pointer to yourself
    // otherwise would be returning std::shared_ptr<A>(this),
    // which would break the shared pointer implementation

  }

  B CreateB()
  {
    return std::make_shared<B>(shared_from_this());
  }

  std::shared_ptr<struct B> ptrB;
};

B::B(std::shared_ptr<A> a)
:ptrA(a)
{}




int main(int argc, char** argv)
{
  // auto intPtr = std::make_unique<int>(40);
  // C* temp = new C(5, 10.0);

  // std::unique_ptr<C> cPtr = std::make_unique<C>(5, 10.0);
  // std::cout << cPtr->GetI() << std::endl;

  // nothing preventing from having another pointer passed in:
  // can have two references to same object, will crash
  // std::unique_ptr<C> cPtr = cPtr(temp);
  // std::unique_ptr<C> cPtr2(temp);

  // Moral: always use make_unique<>() constructor
  // TODO: learn how make_unique works as a cool template function

  UniquePtr<C> cPtr(new C(5, 10.0));

// transfers ownership from main to fm
// but no longer usable after this line
  fm(std::move(cPtr));

  // std::cout << cPtr->GetI() << std::endl;

  auto p1 = std::make_shared<int>(50);
  auto p2 = p1;
  {
    auto p3 = p2;
    {
      // strong reference count is 4
      auto p4 = p3;
      *p1 += 500;
    }
  }
  SharedPtr<int> pp1(new int(50));
  auto pp2 = pp1;
  {
    auto pp3 = pp2;
    {
      auto pp4 = pp3;
      // *pp1 += 500;
    }
  }

  return 0;
}