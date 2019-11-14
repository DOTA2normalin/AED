#include <iostream>

using namespace std;

void imprimir(int *x,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<x[i];
    }
    cout<<" ";
}
void swap(int *x,int *y)
{
    int aux;
    aux=*x;
    *x=*y;
    *y=aux;
}
int p(int x)
{
    int a=1;
    for(int i=1;i<=x;i++)
    {
        a=a*i;
    }
    return a;
}
void permutacion(int n)
{
    int S[n];
    for(int i=1;i<=n;i++)
    {
        S[i]=i;
        cout<<S[i];
    }
    cout<<" ";
    for(int i=2;i<=p(n);i++)
    {
        int m=n-1;
        while(S[m]>S[m+1])
        {
            m--;
        }
        int k=n;
        while(S[m]>S[k])
        {
            k--;
        }
        swap(S[m],S[k]);
        int p=m+1;
        int q=n;
        while(p<q)
        {
            swap(S[p],S[q]);
            p++;
            q--;
        }
        imprimir(S,n);  
    }
}
int main()
{
    permutacion(4);
    return 0;
}