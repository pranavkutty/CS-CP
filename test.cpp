#include<iostream>
using namespace std;
void modify_by_value(int* );
void modify_by_refrence(int* &);
int a=4, b=5;
int main()
{

    int *ptr = NULL;
    ptr = &a;       
    cout << "*ptr before modifying by value: " << *ptr << endl; 
    modify_by_value(ptr);
    cout << "*ptr after modifying by value: " << *ptr << endl;
    cout << "*ptr before modifying by refrence: " << *ptr << endl;
    modify_by_refrence(ptr);
    cout << "*ptr after modifying by refrence: " << *ptr << endl;
    return 0;
}
void modify_by_value(int* ptr)      //this function can change *ptr but not the ptr(address contained) itself;
{
    ptr = &b;                       
}
void modify_by_refrence(int * &ptr) //this function has refrence and hence can modify the pointer;
{
    ptr = &b;
}