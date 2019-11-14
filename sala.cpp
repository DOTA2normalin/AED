#include <iostream>

using namespace std;

int main()
{
    int cantidad;
    cout<<"cantidad de elementos ?";
    cin>>cantidad;
    int *a;
    a=new int[cantidad];
    for (int i=0;i<cantidad;i++)
    {
        cout<<"elemento ?";
        cin>>*(a+i);
    }
    for(int j=0;j<cantidad;j++)
    {
        cout<<*(a+j)<<" ";
    }
    return 0;
}