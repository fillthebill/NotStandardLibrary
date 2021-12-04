#include <iostream>
#include "MySharePtr.h"
#include "../MyVector/MyVector_iterator.h"

// no test, no shame.
int main () {
    using namespace std;

    cout<< " hello, world"<< endl;


        MySharePtr<int> null;
        MySharePtr<int> first(new int(5) );
        MySharePtr<int> second(first);
        null = second;
        cout << *null << endl;
        null.reset(new int(6));
        cout<< *null<< endl;

        MyVector_iterator<int> first_vec;
        for(int i = 0; i < 10; ++i) {
            first_vec.push_back(i);
        }

        MySharePtr<MyVector_iterator<int>> second_vec_ptr(new MyVector_iterator<int>(first_vec));

        for(int i = 0; i < 5; ++i) {
            second_vec_ptr->pop_back();
            cout << "length of vec pointed to by second_vec_ptr is " << second_vec_ptr->length() << endl;
        }

        MySharePtr<MyVector_iterator<int>> third_vec_ptr = second_vec_ptr;

        for(int i = 0; i < 5; ++i) {
            third_vec_ptr->pop_back();
            cout << "length of vec pointed to by third_vec_ptr is " << third_vec_ptr->length() << endl;
        }


        return 0;

}