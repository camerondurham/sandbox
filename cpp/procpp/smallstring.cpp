#include<cstring>

class String {
public:
 String(const char* str)
 {
  size_t origSize = std::strlen(str);
  if (origSize <= 21)
  {
   // We want to do a small string
   mStr.Small.mIsSmallString = true;
   mStr.Small.mSize = static_cast<unsigned char>(origSize);
   std::memcpy(mStr.Small.mData, str, origSize + 1);
  }
  else
  {
   // We want to do a large string
   mStr.Large.mCapacity = origSize + 1;
   mStr.Large.mSize = origSize;
   mStr.Large.mData = new char[origSize + 1];
   std::memcpy(mStr.Large.mData, str, origSize + 1);
  }
 }

 ~String()
 {
  if (mStr.Small.mIsSmallString)
  {
   mStr.Small.mSize = 0;
  }
  else
  {
   mStr.Large.mCapacity = 0;
   mStr.Large.mSize = 0;
   delete[] mStr.Large.mData;
  }
 }

 const char* c_str() const
 {
  if (mStr.Small.mIsSmallString)
  {
   return mStr.Small.mData;
  }
  else
  {
   return mStr.Large.mData;
  }
 }

 size_t size() const
 {
  if (mStr.Small.mIsSmallString)
  {
   return mStr.Small.mSize;
  }
  else
  {
   return mStr.Large.mSize;
  }
 }
private:
 union
 {
  struct
  {
   char* mData;
   size_t mSize;
   size_t mCapacity;
  } Large;
  struct
  {
   char mData[22];
   unsigned char mSize;
   bool mIsSmallString;
  } Small;
 } mStr;
};