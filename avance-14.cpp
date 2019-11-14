#include <iostream>
#include <list>
#include <vector>

using namespace std;
int & operator+(int dato)
{
    list<int> l={4,5,8,7,9,10};
    list<int>:: iterator it=l.begin();
    for(int i=0;i<l.size();i++)
    {
        if(*it==dato)
            break;
        it++;
    }
    return *it;
}

int main()
{
    
}