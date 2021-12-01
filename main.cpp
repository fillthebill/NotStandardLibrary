#include <iostream>
#include "myStringMvable.h"
//#include "myString.h"
#include <string>
#include "MySharePtr.h"
using namespace std;

int main() {

        //cout<< "test for normal string" << endl;
        //myString l = "hello";
        //myString m(" world");
        //myString n = m;
        //n = l;
        //l.push_back(" world");
        //cout<< l <<endl;
        

        /** cstor is called 2 times for the first 2 initiation.
         * then copy cstor is called
         * followed by copy assignment
         * at last another cpy cstor called when passing by value for operator <<
         * which could be designed as passing by reference actually.


        cout<< "test for Move aware string"<<endl;

        myStringMvable s("hello");
        myStringMvable t = " mv semantics";
        //myStringMvable u(s+t);   /** why treat s+t as lvalue, no cstor called at all?? why??
        //cout<<"size of u is " << u.size()<<endl;

        myStringMvable p(move(s+t));
        // p = s+t; /** this line results in an error!

        int in(1000);
        cout<< in << endl;
        return 0;

        */

        /**
        int* T = new int(1000);
        MySharePtr<int> shareint(T);
         */



}
