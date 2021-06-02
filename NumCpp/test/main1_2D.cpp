#include<iostream>
#include "../header/NumCpp.hpp"

int main()
{
    Array2D<int> array1(3,3);
    
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            array1[i][j]=1;
    
    for(int i=0;i<array1.getRows();i++)
    {
        for(int j=0;j<array1.getCols();j++)
            std::cout<<array1[i][j]<<" ";
        std::cout<<"\n";
    }

    Array2D<int> array2={
        {9,8,7},
        {6,5},
        {3,2,1}
    };
    std::cout<<array2<<"\n";

    Array2D<int> array3;
    array3=array2;
    std::cout<<array3<<"\n";
    array3={{1,2,3},
            {4,5,6},
            {7,8,9}};
    std::cout<<array3<<"\n";

    std::cout<<"\n\n\n";
    system("pause");

}