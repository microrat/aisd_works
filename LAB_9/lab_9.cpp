#include <iostream>
#include <algorithm>
#include <cmath>
#include "header.h"

using namespace std;

int main()
{

    cout<<"Enter the size"<<endl;
    int size;
    cin>>size;
    cout<<"Enter the heap"<<endl;
    int *mas=new int[size];
    for (int i=0;i<size;i++)
    {
        cin>>mas[i];
    }
    Heap heap (mas,3,size);
    heap.out();
    cout<<"//--NEXT--//";
    heap.delete_min();
    cout<<endl;
    heap.out();
    cout<<endl;
    cout<<"Enter the element to insert"<<endl;
    int el;
    cin>>el;
    heap.insert(el);
    cout<<endl;
    heap.out();
    return 0;
}
