#include<iostream>
#include "../header/NumCpp.hpp"

int main()
{
    //Array slicing
    Array1D<int> arr{0,1,2,3,4,5,6,7,8,9};
    Array1D<std::reference_wrapper<int>> slice1=arr(3,8);
    for(int i=0; i<slice1.getLength(); i++)
        std::cout<<slice1[i]<<" ";
    std::cout<<"\n"; 

    Array1D<std::reference_wrapper<int>> slice3=arr(0,arr.getLength(),2);
    std::cout<<slice3<<"\n";

    Array1D<std::reference_wrapper<int>> slice2=arr(3,6);
    std::cout<<slice2<<"\n";
    slice2 = { 0, 0, 0};
    std::cout<<slice2<<"\n";
    std::cout<<arr<<"\n";


    //casting
    Array1D<int> arr1{1,2,3,4,5,6,7,8,9};
    Array1D<int> res1(arr1(0,8,2));
    Array1D<std::reference_wrapper<int>> res2(arr1(1,8,2));
    Array1D<int> res3= res1 + res2;
    std::cout<<res1<<"\n";
    std::cout<<res2<<"\n";
    std::cout<<res3<<"\n";

    Array1D<int> res4(static_cast<Array1D<int>>(res2)); //Doesn't affect original array
    std::cout<<res4<<"\n";
    res4[0]=0;
    std::cout<<res4<<"\n";
    std::cout<<arr1<<"\n";

    std::cout<<"\n\n\n";
    system("pause");
}