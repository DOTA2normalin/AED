#include <iostream>

using namespace std;


int comb(int r,int n)
{
    int a=1;
    for(int i=1;i<=r;i++)
        a=a*i;
    int b=1;
    for(int j=1;j<=r;j++,n--)
        b=b*n;
    return b/a;
}
void combinacion(int r,int n)
{
    int S[r];

    for(int i=1;i<=r;i++)
    {
        S[i]=i;
        cout<<S[i];
    }
    cout<<" , ";
    for(int i=2;i<=comb(r,n);i++)
    {
        int m=r;
        int max_value=n;
        while(S[m]==max_value)
        {
            m=m-1;
            max_value=max_value-1;
        }
        S[m]=S[m]+1;
        for(int j=1;j<=r;j++)
        {
            cout<<S[j];
        }
        cout<<" , ";
    }
}

int main()
{
    combinacion(4,6);
    return 0;

}