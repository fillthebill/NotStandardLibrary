//
// Created by 原显智 on 2021/10/18.
//

// why define the overloaded cout<< as friend, as member function?
//
#ifndef UNTITLED_myString_h
#define UNTITLED_myString_h


// in class myString, which resembles the class string, we would define:
// the constructors, copy constructor, copy assignment
// push_back, "==",

// helper functions include
class myString{
public:
    myString(void) {
        start = new char[1]; *start = '\0';
        len = 0;
        //start = nullptr;
        std::cout<< "cstor called"<<std::endl;
    }; // why err when nothing is done in the constructor??
    myString(const char* c);
    myString(const myString& String);
    myString& operator=(const myString& String);// copy assignment

    int length(void);
    ~myString(void);// what if this is private?
    // myString(const myString& s);
    myString& push_back(const char * c);
    char * getCharPtr(void) const;
    bool empty();


private:
    char* start;
    int len=0;
    int string_len(const char* s);
    void string_copy(char* dst, const char*src);
};

myString::myString(const myString &String) {
    std::cout<< "copy cstor called" <<std::endl;
    start = new char[String.len+1];
    string_copy(start,String.start);
    len = String.len;
}

myString::~myString() {
    std::cout<< "dtor called "<<std::endl;
    delete[] start;
}
int myString::string_len(const char *s) {
  int length = 0;
  while(*s != '\0') {
      ++length;
      ++s;
  }
  // std::cout<< "len() finished"<<std::endl;
  return length;
}

void myString::string_copy(char* dst, const char *src) { // the char pointed by dst would plausibly be changed
    // so no const before char*, that is, not making it a pointer to a const char.
    //char * tsrc;
    //tsrc = (char*)src;
    while(*src != '\0') {
        *dst = *src;
        ++dst;
        ++src;
    }
    *dst = '\0';
    //std::cout<< "copy() finished"<<std::endl;
}

myString::myString( const char *c) {
    std::cout<<"cstor called" <<std::endl;
  if(c) // if c is not a pointer to null;
  {
      int length = string_len(c);
      start = new char[length+1];
      len = length;
      string_copy(start,c);
  } else {
      start = new char[1];
      *start = '\0';
      len = 0;
  }
}

myString & myString::operator=(const myString &String) {
    // again copy cstor would be called here;
    // watch for self assignment here.
    std::cout<< "cpy assginment called"<< std::endl;
    if(&String == this) {
        return *this;
    }

    delete [] start;
    // this point forgotten
    start = new char[String.len + 1];
    string_copy(start,String.start);
    len = String.len;
    return *this;
}

int myString::length() {
    return len;
}

myString& myString::push_back(const char *c) {
    std::cout<< "push_back called"<<std::endl;
    int _len = string_len(c);
    // we have to allocate memory dynamically here.
    if(_len == 0) return *this;
    else {
        /* start used to traverse each char, _start points to the starting location, used to free the memory
         * originally pointed to by start*/
        char* _start = start;
        char* _string = new char[_len + len + 1];
        char* string = _string;

        /* similarly, string used to traverse the input char[] pointed to by c,
         * while the location pointed to by _string would be assigned to start;
         * */

        while(*start != '\0') {
            *string = *start;
            ++ start;
            ++ string;
        }
        delete [] _start;// decomposed into 2 substeps, dstor and operator delete/ free();

        while(*c !='\0') {
            * string = *c;
            ++c;
            ++ string;
        }
        * string = '\0';
        start = _string;
        len = len + _len;
        return *this;
    }
}

char* myString::getCharPtr() const{
    return start;
};

bool myString::empty() {
    if(len == 0) {
        return true;
    }
    else return false;
};

std::ostream & operator << (std::ostream & out, const myString _string) {
    out << _string.getCharPtr();
    return out;
};


#endif //UNTITLED_myString_h
