//
// Created by 原显智 on 2021/10/18.
// myStingMvable,


#ifndef UNTITLED_myStringMvable_h
#define UNTITLED_myStringMvable_h

class myStringMvable {
public:
    myStringMvable(void) {
        len = 0;
        s_data = new char[1];
        *s_data = '\0';
        std::cout << "default cstor called" << std::endl;
    }
    myStringMvable(const char* c);// constructor
    myStringMvable(const myStringMvable& str) { // has to pass reference to const, since copy constructor would be called
        // if pass by value, which would result in an infinite loop.
        len = str.len;
        s_data = new char[len+1];
        strcpy(s_data, str.s_data);
        std::cout << "cpy called"<<std::endl;
    }
    myStringMvable(myStringMvable&& str); // move copy constructor
    myStringMvable& operator=(const myStringMvable& str); // copy assginment
    myStringMvable& operator=(myStringMvable&& str);// move assginment
    ~myStringMvable() {
        delete [] s_data;
    }
    int size() {return len;}
    myStringMvable operator+(const myStringMvable& str);
private:
    int strlen(const char* c);
    void strcpy(char* dst, const char* src);
    int len;
    char * s_data;
};

int myStringMvable::strlen(const char* c) { // pointer to a const char.

    int l = 0;
    while(*c != '\0') {
        l++;
        c++;
    }
    return l;
};

void myStringMvable::strcpy(char* dst, const char* src) {
    while(*src != '\0') {
        *dst = *src;
        ++ dst;
        ++ src;
    }
    *dst = '\0';
}

myStringMvable::myStringMvable(const char *c) {
    std::cout<< "cstor called"<<std::endl;
    int l = strlen(c);
    s_data = new char[l + 1];
    strcpy(s_data, c);
    len = l;
}

myStringMvable::myStringMvable(myStringMvable &&str) {
    s_data = str.s_data;
    len = str.len;
    str.s_data = nullptr;
    std::cout<< "move cpy constructor called" <<std::endl;
}

myStringMvable& myStringMvable::operator=(const myStringMvable& str) {
    //self assignment check
    std::cout<< "copy assignment called"<<std::endl;
    if(&str == this) return *this;
    else{
        delete[] s_data;
        s_data = new char[str.len+1];
        strcpy(s_data, str.s_data);
        len = str.len;
    }
    return *this;
}

myStringMvable myStringMvable::operator+(const myStringMvable &str) {
    std::cout<< "operator + called" <<std::endl;
    myStringMvable ret; // string to be returned.
    ret.len = len + str.len;
    ret.s_data = new char[ret.len + 1];
    char* _ret = ret.s_data;
    char * _str = str.s_data;
    char * _s = s_data;
    while(* _s != '\0') {
        *_ret = *_s;
        _s ++;
        _ret ++;
    }
    while(*_str != '\0') {
        *_ret = *_str;
        _str ++;
        _ret ++;
    }
    *_ret = '\0';
    return ret;
}

myStringMvable& myStringMvable::operator=( myStringMvable &&str) {
    std::cout<< "move assignment called"<< std::endl;
    if(&str == this) return *this;
    delete [] s_data;
    s_data = str.s_data;
    len = str.len;
    str.s_data = nullptr;
    return *this;
}
#endif //UNTITLED_myStringMvable_h
