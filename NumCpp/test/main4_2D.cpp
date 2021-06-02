#include<iostream>
#include "../header/NumCpp.hpp"

int main()
{
    Array2D<int> array1{{1,2,3},
                        {4,5,6},
                        {7,8,9}};
    Array2D<int> array2{{1,2,3},
                        {4,5,6},
                        {7,8,9}};
    std::cout<< array1 + array2 <<"\n";
    std::cout<< array1 + 10 <<"\n";
    std::cout<< array1 * 10 <<"\n";

    Array2D<int> array5{{1},{2},{3}};
    Array2D<int> array6{{1,2,3}};
    Array1D<int> array7{1,1,1};

    std::cout<<array5<<"\n"<<array6<<"\n";
    std::cout<<array5 + array6<<"\n";
    std::cout<<array5 + 4 <<"\n";
    std::cout<<array6 + array7<<"\n";
    std::cout<<array2 + array7<<"\n";
    std::cout<<array2 + array6<<"\n";

    std::cout<<array5 * array6<<"\n";
    std::cout<<array6 * array5<<"\n";
    std::cout<<array2 * array6<<"\n";

    std::cout<<array6.dot(array5)<<"\n";

    Array2D<int> mat1 = { { 1, 1, 1, 1 },
                          { 2, 2, 2, 2 },
                          { 3, 3, 3, 3 },
                          { 4, 4, 4, 4 } };
 
    Array2D<int> mat2 = { { 1, 1, 1, 1 },
                          { 2, 2, 2, 2 },
                          { 3, 3, 3, 3 },
                          { 4, 4, 4, 4 } };
    std::cout<< mat1.dot(mat2)<<"\n";

    std::cout<<"\n\n\n";
    system("pause");

}