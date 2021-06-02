#include<iostream>
#include "../header/NumCpp.hpp"
#include "../extra/Person.cpp"
#include<string>

int main()
{
    // std::cout<<"Array1D for different types:\n";
    // Array1D<float> array1(10);
    // Array1D<std::string> array2{"This","is","Array1D","object","for Strings"};
    // Array1D<Person> arr{Person(std::string{"ABC"},10,std::string{"Coder"}),
    //                                 Person(std::string{"ABC"},10,std::string{"Coder"}),
    //                                         Person(std::string{"ABC"},10,std::string{"Coder"})};
    // for (int i{ 0 }; i<10; ++i)
    //    array1[i] = i+1.5;

    // std::cout<<array1<<"\n";
    // std::cout<<array2<<"\n";
    // std::cout<<arr<<"\n";

    std::cout<<"\n\nDifferent Functions:\n";
    
    Array1D<int> array3{2,4,6,8};
    array3 = { 1, 3, 5, 7, 9, 11 };
    std::cout<<array3<<"\n";
    
    // Resize the array to 8 elements
    array3.resize(8);
    std::cout<<array3<<"\n";
 
    // Insert the number 20 before element with index 5
    array3.insertBefore(20, 5);
    std::cout<<array3<<"\n";
 
    // Remove the element with index 3
    array3.remove(3);
    std::cout<<array3<<"\n";
 
    // Add 30 and 40 to the end and beginning
    array3.insertAtEnd(30);
    std::cout<<array3<<"\n";
    
    array3.insertAtBeginning(40);
    std::cout<<array3<<"\n";
    
    std::cout<<array3.sum()<<"\n";
    std::cout<<array3.min()<<"\n";
    std::cout<<array3.max()<<"\n";
    array3.sort();
    std::cout<<array3<<"\n";

    std::cout<<"\n\n\n";
    system("pause");
}