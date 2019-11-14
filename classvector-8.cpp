#include <iostream>
#include <vector>
using namespace std;

void insertar(vector<int> v,int dato)
{
    int *iter=&v[0];
    int tam=v.size();
    int sizetam=tam++;
    vector<int> nuevo;
    for(int i=1;i<=tam;i++)
    {
        nuevo.push_back(*iter);
        iter++;
    }
    v.clear();
    v[sizetam-1]=dato;
    for(int k=0;k<sizetam;k++)
    {
        cout<<v[k]<<" ";
    }

}
int main()
{

    vector<int> v={4,5,9,8,7,2};
    insertar(v,-5);
    return 0;
}