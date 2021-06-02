#include<iostream>
#include "../header/NumCpp.hpp"

int main()
{
    std::cout<<"Different ways to iterate:\n";
    Array2D<int> array1={
        {9,8,7},
        {6,5,4},
        {3,2,1}
    };

    for(int i=0;i<array1.getRows();i++)
    {
        for(int j=0;j<array1.getCols();j++)
            std::cout<<array1[i][j]<<" ";
        std::cout<<"\n";
    }

    for(Array2D<int>::Iterator it= array1.begin();
            it != array1.end() ; ++it)
    {
        std::cout<<*it<<" ";
    } 
    std::cout<<"\n";

    for(auto &x: array1)
        std::cout<<x<<" ";
    std::cout<<"\n";

    std::cout<<array1<<"\n";
    
    std::cout<<"\n\n\n";
    system("pause");

}