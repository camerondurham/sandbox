template <typename T>
class UniquePtr
{
public:
 // This assumes we don't pass in the same pointer to multiple uniques!
 UniquePtr(T* data)
  :mData(data)
 {}

 ~UniquePtr()
 {
  delete mData;
 }

 // Disallow copy and copy assignment
 UniquePtr(const UniquePtr<T>& other) = delete;
 UniquePtr<T>& operator=(const UniquePtr<T>& other) = delete;

 // Allow moves for ownership transference
 UniquePtr(UniquePtr<T>&& other) noexcept
  :mData(std::move(other.mData))
 {
  other.mData = nullptr;
 }

 // Ditto for move assignment
 // ...

 // Overload * and -> so it's like a normal pointer
 T& operator*()
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
 // Strong references used for shared pointer counting
 unsigned mStrongRefs = 0;
 // Weak references used for weak pointer counting
 unsigned mWeakRefs = 0;
};

template <typename T> class WeakPtr;

template <typename T>
class SharedPtr
{
public:
 // This is an uninitialized shared ptr
 SharedPtr()
  :mData(nullptr)
  ,mBlock(nullptr)
 {
 }

 // Assume we are the first shared ptr to data
 SharedPtr(T* data)
  :mData(data)
  ,mBlock(new ControlBlock)
 {
  // We're the first shared ptr, so strong ref count is 1!
  mBlock->mStrongRefs = 1;
  mBlock->mWeakRefs = 0;
 }

 // Support for creating a shared pointer from a weak pointer
 friend class WeakPtr<T>;
 SharedPtr(const WeakPtr<T>& other);

 ~SharedPtr()
 {
  mBlock->mStrongRefs--;
  // Only delete if there are no more strong references
  if (mBlock->mStrongRefs == 0)
  {
   delete mData;
   // Only delete control block if weak references are also 0!
   if (mBlock->mWeakRefs == 0)
   {
    delete mBlock;
   }
  }
 }

 // Allow copies for shared ownership
 SharedPtr(const SharedPtr<T>& other)
  :mData(other.mData)
  ,mBlock(other.mBlock)
 {
  // Increase reference count since we're referring to an existing heap object
  mBlock->mStrongRefs++;
 }

 // Ditto for copy assignment
 // ...

 // Allow moves for reference transference
 SharedPtr(SharedPtr<T>&& other) noexcept
  :mData(std::move(other.mData))
  ,mBlock(std::move(other.mBlock))
 {
  other.mData = nullptr;
  other.mBlock = nullptr;
 }

 // Ditto for move assignment
 // ...

 // Overload * and -> so it's like a normal pointer
 T& operator*()
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

template <typename T>
class WeakPtr
{
public:
 friend class SharedPtr<T>;
 WeakPtr(const SharedPtr<T>& shared)
  :mData(shared.mData)
  ,mBlock(shared.mBlock)
 {
  mBlock->mWeakRefs++;
 }

 ~WeakPtr()
 {
  mBlock->mWeakRefs--;
  // Clean up control block if I'm the last pointer to the control block
  if (mBlock->mStrongRefs == 0 && mBlock->mWeakRefs == 0)
  {
   delete mBlock;
  }
 }

 WeakPtr(const WeakPtr<T>& other)
  :mData(other.mData)
  ,mBlock(other.mBlock)
 {
  mBlock->mWeakRefs++;
 }

 // Need to implement copy assignment, move, and move assignment too!
 // ...

 bool IsExpired() const
 {
  return mBlock->mStrongRefs == 0;
 }

 SharedPtr<T> Lock()
 {
  // If the observed object is dead, then create a null shared ptr
  if (IsExpired())
  {
   return SharedPtr<T>();
  }
  else
  {
   // Otherwise return a shared ptr to the object that we're observing
   return SharedPtr<T>(*this);
  }
 }
private:
 T* mData;
 ControlBlock* mBlock;
};

// This has to be declared down here because it relies on having a full definition
// of WeakPtr
template <typename T>
SharedPtr<T>::SharedPtr(const WeakPtr<T>& other)
 :mData(other.mData)
 ,mBlock(other.mBlock)
{
 mBlock->mStrongRefs++;
}