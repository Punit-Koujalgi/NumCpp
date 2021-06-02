#include<iostream>
#include "../header/NumCpp.hpp"

int main()
{
    std::cout<<"Different ways to iterate:\n";

    Array1D<int> array{2,4,6,8,10,12,14,16};
    
    for (int i=0; i<array.getLength(); ++i)
        std::cout << array[i] << ' ';
    std::cout << '\n';
    
    for(Array1D<int>::Iterator it= array.begin(); //can also use "auto"
            it != array.end() ; it++)
    {
        std::cout<<*it<<" ";
    } 
    std::cout<<"\n";

    for(auto &x: array)
        std::cout<<x<<" ";
    std::cout<<"\n";

    std::cout<<array<<"\n";

    std::cout<<"\n\n\n";
    system("pause");

}