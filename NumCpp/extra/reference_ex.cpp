#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a=10;
    int b=20;
    reference_wrapper<int> x(a);
    x.get() = b;
    b=30;
    cout<< x << " "<< a << " " << b <<"\n" ;
}