#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void listinter(list<int> &l1,list<int> &l2)
{
    list<int>:: iterator itl1=l1.begin();
    list<int>:: iterator itl2=l2.begin();
    list<int> aux;
    while(itl1!=l1.end() && itl2!=l2.end())
    {
        if(*itl2==*itl1)
        {
            aux.push_back(*itl1);
            itl2++;
            itl1++;
        }
        else if(*itl1<*itl2)
        {
            itl1++;
        }
        else
        {
            itl2++;
        }
        
    }
    list <int> :: iterator it; 
    for(it = aux.begin(); it != aux.end(); ++it) 
        cout << *it<<" "    ; 
    cout << '\n';
}
int main()
{
    list<int> l1={7,15,20,25};
    list<int> l2={7,15,24,50};
    listinter(l1,l2);
    return 0;

}