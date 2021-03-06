//
// Created by 原显智 on 2021/11/25.
// forget to return in copy assginment.

#ifndef UNTITLED_MYSHAREPTR_H
#define UNTITLED_MYSHAREPTR_H

template<typename T>
class MySharePtr {
public:

    MySharePtr(void) {SharePtr = nullptr; RefCount = new int(0);};
    explicit MySharePtr(T* const pointer): SharePtr(pointer),RefCount(new int(1)) {}
    /**
     * what if nullptr is passed as input??
     *
     * */
    MySharePtr(const MySharePtr& other): SharePtr(other.SharePtr),RefCount(other.RefCount) {
        *other.RefCount +=1;
    }

    MySharePtr& operator=(MySharePtr& other){
        T* OldPtr = SharePtr;
        int* OldCount = RefCount;

        SharePtr = other.SharePtr;
        RefCount = other.RefCount;
        *other.RefCount += 1;

        *OldCount -= 1;
        if(*OldCount == 0) {
            delete OldPtr;
            delete OldCount;
        }
        return *this;
    }

    ~MySharePtr() {
        *RefCount -= 1;
        std::cout<< "dstor called" <<std::endl;
        if(*RefCount == 0) {
            std::cout<< "dstructed" <<std::endl;
            delete SharePtr;
            delete RefCount;
        }
    }

    MySharePtr& reset(T* const pointer) {
        int* old_count = RefCount;
        T* old_shareptr = SharePtr;
        if(*old_count == 1) {
            delete old_shareptr;
            delete old_count;
        }
        SharePtr = pointer; RefCount = new int(1);
        return *this;
    }

    bool operator !() {
        return (*RefCount == 0);
    }

    T& operator *() const {return *SharePtr;}
    T* operator ->() const{return SharePtr;}

private:
    T* SharePtr;
    int* RefCount;

};



#endif //UNTITLED_MYSHAREPTR_H
