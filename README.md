# NumCpp
  NumCpp is a C++ library that aims to emulate the Numpy library of Python. This library has functions to create 1-dimensional and 2-dimensional arrays that can be manipulated the way Numpy arrays can be. Generic approach is used to write the code with the help of C++ templates so that these arrays work with any data type(including user defined classes). These classes have been given proper copy initialization functions and assignment functions so that one can work with these as numpy arrays and normal C++ objects at the same time. Slicing functionality has been provided with the help of reference_wrapper object. Also Iterators are written for both type of arrays to easily access the objects.
  
  
To Use the NumCpp library : 
Download the NumCpp code from github
Include “NumCpp.hpp” header file in your code
Now you have access Array1D and Array2D to use, but it’s important to know that these are template functions


Some code-use snippets:

 Array1D<int> array1{1,3,5,7,9,11}; 
  
  std::cout<<array1<<"\n";
  
  Array1D<float> array2(10);

  for (int i{ 0 }; i<10; ++i)
  
      array2[i] = i+1.5;

  Array2D<int> array3 = { {9,8,7},
   {6,5,4},
   {3,2,1} };

  std::cout<<array3<<"\n";

Please read the full report to view many more examples, understand how to use the library in more complex setting and  to understand the implementation.

