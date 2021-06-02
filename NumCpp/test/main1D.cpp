#include<iostream>
#include "../src/reference_array1D.cpp"

int main()
{
    /*
//test 1    
    Array1D<int> array1{2,4,6,8};
    Array1D<int> array2{1,3,5,7,9,11};
    Array1D<int> temp;
    temp=array1;
    array1=array2;
    for (int i{ 0 }; i<array1.getLength(); ++i)
        std::cout << array1[i] << ' ';
 
    std::cout << '\n';

    array2=temp;
    for (int i{ 0 }; i<array2.getLength(); ++i)
        std::cout << array2[i] << ' ';
 
    std::cout << '\n';

//Test 2
    Array1D<int> array{ 1, 3, 5, 7, 9, 11 };
    array = {2,4,6,8};
    for (int i{ 0 }; i<array.getLength(); ++i)
        std::cout << array[i] << ' ';
 
    std::cout << '\n';
    // Fill the array with numbers 1 through 10
    //for (int i{ 0 }; i<10; ++i)
    //    array[i] = i+1.5;
 
    // Resize the array to 8 elements
    array.resize(8);
 
 for (int i{ 0 }; i<array.getLength(); ++i)
        std::cout << array[i] << ' ';
 
    std::cout << '\n';
    // Insert the number 20 before element with index 5
    array.insertBefore(20, 5);
 
 for (int i{ 0 }; i<array.getLength(); ++i)
        std::cout << array[i] << ' ';
 
    std::cout << '\n';
    // Remove the element with index 3
    array.remove(3);
    
 for (int i{ 0 }; i<array.getLength(); ++i)
        std::cout << array[i] << ' ';
 
    std::cout << '\n';
    // Add 30 and 40 to the end and beginning
    array.insertAtEnd(30);
    for (int i{ 0 }; i<array.getLength(); ++i)
        std::cout << array[i] << ' ';
 
    std::cout << '\n';
    array.insertAtBeginning(40);
 
    // Print out all the numbers
    for (int i{ 0 }; i<array.getLength(); ++i)
        std::cout << array[i] << ' ';
 
    std::cout << '\n';*/
//Test 3
   /* Array1D<int> array{ 1, 3, 5, 7, 9, 11 };

    for(auto &x: array)
        std::cout<<x<<" ";
    std::cout<<"\n";

    for(Array1D<int>::Iterator it= array.begin();
            it != array.end() ; it++)
    {
        std::cout<<*it<<" ";
    } 
    std::cout<<"\n";*/

    /*Array1D<int> array1{2,4,6,8};
    Array1D<int> array2{2,4,6,8};
    Array1D<int> array3{1,3,5,7};
    Array1D<int> array4;
    std::cout<<array1<<array3;
    /*array4=array2 + array3;

    for(auto &x: array4)
        std::cout<<x<<" ";
    std::cout<<"\n";*/
    /*std::cout<<std::boolalpha <<(array1==array2) << std::endl;    
    std::cout<< (array2==array3) << std::endl;
    Array1D<int> sliced=array1(0,4,2);
    for(auto &x: sliced)
        std::cout<<x<<" ";
    std::cout<<"\n";*/
    /*Array1D<int> array5(array1 + 2);
    for(auto &x: array5)
        std::cout<<x<<" ";
    std::cout<<"\n";

    Array1D<int> array6(array1 - 2);
    for(auto &x: array6)
        std::cout<<x<<" ";
    std::cout<<"\n";

    Array1D<int> array7(array1 * 2);
    for(auto &x: array7)
        std::cout<<x<<" ";
    std::cout<<"\n";

    Array1D<int> array8(array1 / 2);
    for(auto &x: array8)
        std::cout<<x<<" ";
    std::cout<<"\n";*/
    /*Array1D<int> array9{2,4,6,8};
    Array1D<bool> array10(array9 == 4);
    for(auto &x: array10)
        std::cout<<x<<" ";
    std::cout<<"\n";

    Array1D<int> array11{2,4,6,8};
    Array1D<bool> array12(array9 > 5);
    for(auto &x: array12)
        std::cout<<x<<" ";
    std::cout<<"\n";

    Array1D<int> array13{2,4,6,8};
    Array1D<int> array14(array13[ array13 > 5]);
    for(auto &x: array14)
        std::cout<<x<<" ";
    std::cout<<"\n";

    //Array1D<int> array13{2,4,6,8};
    Array1D<int> array15(array13[ array13 < 5]);
    for(auto &x: array15)
        std::cout<<x<<" ";
    std::cout<<"\n";*/

    Array1D<int> arrSlice{0,1,2,3,4,5,6,7,8,9};
    Array1D<std::reference_wrapper<int>> slice=arrSlice(0,5,2);
    // std::cout<<slice<<"\n";
    // slice = {-1 , -1 , -1};
    // std::cout<<slice<<"\n";
    // std::cout<<arrSlice<<"\n";
    //for(auto  &x: slice)
    //    std::cout<<x.get()<<" ";
    Array1D<int> res(arrSlice + arrSlice(0,arrSlice.getLength()));
    std::cout<<res<<"\n";

    system("pause");
}