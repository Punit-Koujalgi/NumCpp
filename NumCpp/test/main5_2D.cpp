#include<iostream>
#include "../header/NumCpp.hpp"

int main()
{
    Array2D<int> array {{ 1, 1, 1, 1 },
                        { 2, 2, 2, 2 },
                        { 3, 3, 3, 3 },
                        { 4, 4, 4, 4 }};
    std::cout<<array<<"\n";

    Array2D<std::reference_wrapper<int>> slice1 = array(0,2,0,2);
    std::cout<<slice1<<"\n";

    Array2D<std::reference_wrapper<int>> slice2 = array(1,3,1,3);
    std::cout<<slice2<<"\n";

    slice2={{0,0},
            {0,0}};
    std::cout<<array<<"\n";
    slice2={{2,2},
            {3,3}};
    

    Array2D<std::reference_wrapper<int>> slice3 = 
                                        array(1,4,0,4,2,1);
    std::cout<<slice3<<"\n";
    
    Array2D<std::reference_wrapper<int>> slice4 = 
                                        array(0,4,1,4,1,2);
    Array2D<int> backup(slice4);
    
    std::cout<<slice4<<"\n";
    slice4 = {{0,0},{0,0},
              {0,0},{0,0}};
    std::cout<<array<<"\n";

    slice4 = backup;
    std::cout<<array<<"\n";


    Array2D<int> res1(static_cast<Array2D<int>>(slice1));
    res1 = res1 + slice2;
    std::cout<<res1<<"\n";

    std::cout<<"\n\n\n";
    system("pause");
}