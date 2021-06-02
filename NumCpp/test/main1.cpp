#include<iostream>
#include "../header/NumCpp.hpp"

int main()
{
    //test 1    
    Array1D<int> array1{2,4,6,8};
    Array1D<int> array2{1,3,5,7,9,11};
    Array1D<int> temp;
    
    std::cout<<"Before Swapping :\n";
    std:: cout << "array1 is: ";;
    for (int i{ 0 }; i<array1.getLength(); ++i)
        std::cout << array1[i] << ' ';
    std::cout << '\n';

    std:: cout << "array2 is: ";;
    for (int i{ 0 }; i<array2.getLength(); ++i)
        std::cout << array2[i] << ' ';
    std::cout << '\n';

    std::cout<<"\n\nAfter Swapping :\n";
    temp=array1;
    array1=array2;
    array2=temp;

    std:: cout << "array1 is: "<<array1<<"\n";
    std:: cout << "array2 is: "<<array2<<"\n";

    system("pause");    
}