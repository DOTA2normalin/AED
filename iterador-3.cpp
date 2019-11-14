#include <iostream>
#include <list>
#include <iterator>

using namespace std;


int& find(list<int> l,const int &x)
{
    list<int>::iterator it=l.begin();
    for(int i=0;i<l.size();i++)
    {
        if(*it==x)
        {
            return *it;
            break;
        }
        it++;
    }
}
int main()
{
    list<int> l={5,8,7,9,1,3,5};
    int *valor=&find(l,9);
    cout<<*valor;
    return 0;
}