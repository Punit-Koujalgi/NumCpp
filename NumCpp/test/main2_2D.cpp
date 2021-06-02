#include<iostream>
#include "../header/NumCpp.hpp"
#include "../extra/Person.cpp"
#include<string>

int main()
{
    Array2D<float> array1(3,3);
    Array2D<std::string> array2{{"This","is"},
                                {"Array1D","object"},
                                {"for"," Strings"}};
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            array1[i][j]+=0.5;
    
    std::cout<<array1<<"\n";
    std::cout<<array2<<"\n";

    Array2D<int> array3={{1,2,3,-1},
                         {4,5,6,-1},
                         {7,8,9,-1}};
    std::cout<<array3<<"\n";
    array3.resize(3,3);
    std::cout<<array3<<"\n";

    std::cout<<array3.sum()<<"\n";
    std::cout<<array3.sum(0)<<"\n";
    std::cout<<array3.sum(1)<<"\n";

    std::cout<<array3.min()<<"\n";
    std::cout<<array3.min(0)<<"\n";
    std::cout<<array3.min(1)<<"\n";

    std::cout<<array3.max()<<"\n";
    std::cout<<array3.max(0)<<"\n";
    std::cout<<array3.max(1)<<"\n";



    
    std::cout<<"\n\n\n";
    system("pause");
}