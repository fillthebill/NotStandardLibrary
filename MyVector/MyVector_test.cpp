#include "MyVector_iterator.h"




int main () {
    MyVector_iterator<int> height;

    for(int i = 0; i < 5; ++i) {
        height.push_back(i);
        std::cout<< height.length()<<std::endl;
    }

    MyVector_iterator<int> height2(height);
    std::cout<< "len of height is " << height2.length()<< std::endl;

    MyVector_iterator<int> height3;
    height3 = height2;
    std::cout<< "len of height3 is " << height3.length()<< std::endl;


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
    std::cout << " the third one is "<< *(ite+=2) << std::endl;
    std::cout << " the fourth one is "<< *(++ite) << std::endl;
    std::cout << " the fourth one is "<< *(ite++) << std::endl;
    std::cout << " the fifth one is "<< *(ite) << std::endl;

    const int x = 1;
    std::cout << " the sixth one is "<< *(ite+x) << std::endl;

}

