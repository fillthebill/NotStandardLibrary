#include <iostream>
#include "MySharePtr.h"

// no test, no shame.
int main () {
    using namespace std;

    cout<< " hello, world"<< endl;



        MySharePtr<int> local(new int(5) );



        MySharePtr<int>it(local);


}