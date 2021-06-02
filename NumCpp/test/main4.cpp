#include<iostream>
#include "../header/NumCpp.hpp"

int main()
{
    Array1D<int> array1{2,4,6,8};
    Array1D<int> array2{2,4,6,8};
    Array1D<int> array3{1,3,5,7};
    Array1D<int> array4(array2 + array3);
    std::cout<<array4<<"\n";

    array4 = array1 + 10;
    std::cout<<array4<<"\n";

    array4 = array1 - 8;
    std::cout<<array4<<"\n";

    array4 = array1 * 2;
    std::cout<<array4<<"\n";

    array4 = array1 / 2;
    std::cout<<array4<<"\n";

    std::cout<<std::boolalpha <<(array1==array2) << std::endl;    
    std::cout<< (array2==array3) << std::endl;


    std::cout<<"\n\n";

    Array1D<int> arr1{0,1,2,3,4,5,6,7,8,9};
    Array1D<bool> res1((arr1 == 4) | (arr1 == 6));
    std::cout<<res1<<"\n";

    Array1D<bool> res2( arr1 > 5); 
    std::cout<<res2<<"\n";

    Array1D<int> res3(arr1[ arr1 < 5]);
    std::cout<<res3<<"\n";

    Array1D<int> res4(arr1[ arr1 >= 5]);
    std::cout<<res4<<"\n";


    std::cout<<"\n\n\n";
    system("pause");
}