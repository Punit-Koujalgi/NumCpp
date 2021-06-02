#include "../src/reference_array2D.cpp"
#include<iostream>

int main()
{
    /*Array2D<int> array1(3,3);
    
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            array1[i][j]=1;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            std::cout<<array1[i][j]<<" ";
        std::cout<<"\n";
    }

    for(auto &x: array1)
        std::cout<<x<<" ";
    std::cout<<"\n";

    for(Array2D<int>::Iterator it= array1.begin();
            it != array1.end() ; ++it)
    {
        std::cout<<*it<<" ";
    } 
    std::cout<<"\n";
    
    std::cout<<array1<<"\n";*/

    /*Array2D<int> array2{
        {1,2,3},
        {4,5,6}, //{4,5}
        {7,8,9}
    };
    
    // std::cout<<array2<<"\n";

    // Array2D<int> array3(array2);
    // std::cout<<array3<<"\n";

    Array2D<int> array4;
    array4={
        {9,8,7},
        {6,5,4}, //4,5,6
        {3,2,1}
    };
    std::cout<<array4 + array2<<"\n";

    // Array2D<int> array5;
    // array5=array4;
    // array5.resize(4,4);
    // std::cout<<array5<<"\n";

    /*array5.resize(0,0);
    std::cout<<array5<<"\n";*/

//Broadcasting

    /*Array2D<int> array5{{1},{2},{3}};
    Array2D<int> array6{{1,2,3}};
    Array1D<int> array7{1,1,1};

    std::cout<<array5<<"\n"<<array6<<"\n";
    std::cout<<array5 + array6<<"\n";
    std::cout<<array5 + 4 <<"\n";
    std::cout<<array6 + array7<<"\n";
    std::cout<<array4 + array7<<"\n";*/

    Array2D<int> array{
        {1,2,3},
        {4,5,6}, //{4,5}
        {7,8,9}
    };

    // Array2D<std::reference_wrapper<int>> slice=array(0,2,0,2);
    //std::cout<<array<<"\n";
    //std::cout<<slice<<"\n";

    //slice[0][0]=-1;
    
    //slice=array(1,3,1,3);
    // std::cout<<array<<"\n";
    // std::cout<<slice<<"\n";

    //slice={{0,0},{0,0}};
    //std::cout<<array<<"\n";
    //std::cout<<slice<<"\n";
    
    Array2D<std::reference_wrapper<int>> slice=array(0,3,0,3);
    Array2D<int> res = array + slice;
    std::cout<<res<<"\n";

    Array2D<int> res1(static_cast<Array2D<int>>(slice)); // or just slice
    std::cout<<res1<<"\n";

    system("pause");
}
