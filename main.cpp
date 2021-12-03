#include <iostream>
#include "myString.h"

#include <string>
#include "MySharePtr.h"
using namespace std;

#include "MyVector_iterator.h"
int main() {

        //cout<< "test for normal string" << endl;
        //myString_iterator l = "hello";
        //myString_iterator m(" world");
        //myString_iterator n = m;
        //n = l;
        //l.push_back(" world");
        //cout<< l <<endl;


        /** cstor is called 2 times for the first 2 initiation.
         * then copy cstor is called
         * followed by copy assignment
         * at last another cpy cstor called when passing by value for operator <<
         * which could be designed as passing by reference actually.


        cout<< "test for Move aware string"<<endl;

        myString_iteratorMvable s("hello");
        myString_iteratorMvable t = " mv semantics";
        //myString_iteratorMvable u(s+t);   /** why treat s+t as lvalue, no cstor called at all?? why??
        //cout<<"size of u is " << u.size()<<endl;

        myString_iteratorMvable p(move(s+t));
        // p = s+t; /** this line results in an error!

        int in(1000);
        cout<< in << endl;
        return 0;

        */

        /**
        int* T = new int(1000);
        MyShareP_iteratortr<int> shareint(T);
         */

        MyVector_iterator<int> height;

        for(int i = 0; i < 5; ++i) {
            height.push_back(i);
            std::cout<< height.length()<<std::endl;
        }
// MyVector_iterator<int> height2(height);
//        std::cout<< "len of height is " << height2.length()<< std::endl;
//
//        MyVector_iterator<int> height3;
//        height3 = height2;
//        std::cout<< "len of height3 is " << height3.length()<< std::endl;


        for(int i = 0; i < 5; ++i) {
            int input = i+7;
            height.push_back(input);
            std::cout<< "end is "<< *(height.end()-1)<<std::endl;
        }

        std::sort(height.begin(),height.end());

        for(int i = 0; i < 10; ++i) {
            int temp;
            temp = height[i];
            std::cout<< temp << " ";
        }

        std::unique(height.begin(),height.end());

        std::cout << "after unique" << std::endl;

        for(int i = 0; i < height.length(); ++i) {
            int temp;
            temp = height[i];
            std::cout<< temp << " ";
        }

        std::reverse(height.begin(),height.end());

        std::cout << "after reverse" << std::endl;

        for(int i = 0; i < height.length(); ++i) {
            int temp;
            temp = height[i];
            std::cout<< temp << " ";
        }

        MyVector_iterator<int>::iterator ite = height.begin();
        std::cout << " the first one is "<< *ite << std::endl;







}
