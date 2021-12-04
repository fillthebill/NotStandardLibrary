//
// Created by 原显智 on 2021/11/25.
//

#ifndef UNTITLED_MYSHAREPTR_H
#define UNTITLED_MYSHAREPTR_H

template<typename T>
class MySharePtr {
public:

    MySharePtr() = delete;
    explicit MySharePtr(T* pointer): SharePtr(pointer),RefCount(new (std::nothrow)int(1)) {
      if(RefCount == nullptr) {
          delete SharePtr;
          delete RefCount;
          throw std::bad_alloc();
      }
    }
    /**
     * what if nullptr is passed as input??
     *
     * */
    MySharePtr(MySharePtr& other): SharePtr( other.SharePtr),RefCount(*other.RefCount + 1) {
        *other.RefCount +=1;
    }

    MySharePtr& operator=(MySharePtr& other){
        T* OldPtr = SharePtr;
        int * OldCount = RefCount;

        SharePtr = other.SharePtr;
        RefCount = other.RefCount;
        *other.RefCount += 1;

        *OldCount -= 1;
        if(*OldCount == 0) {
            delete OldPtr;
            delete OldCount;
        }
    }

    ~MySharePtr() {
        *RefCount -= 1;
        if(*RefCount == 0) {
            delete SharePtr;
            delete RefCount;
        }
    }

    T& operator *() const {return *SharePtr;}
    T* operator ->() const{return SharePtr;}

private:
    T* SharePtr;
    int* RefCount;

};



#endif //UNTITLED_MYSHAREPTR_H
