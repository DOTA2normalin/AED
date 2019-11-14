#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

template<typename T>
class Cola
{
    private:
        vector<T> v;
        T tam;
        T head;
        T next;
    public:
        Cola(int _tam)
        {
            head=0;
            next=0;
            tam= _tam;
            v.resize(tam);
        }
        void insertar(T x)
        {
            if(tam==0)
            {
                v[next]=x;
                next++;
            }
            else
            {
                v[next]=x;
                next++;
            }
            
        }
        T quitar()
        {
            T temp=v[head];
            head++;
            return temp;
        }
        bool vacio()
        {
            return head==next;
        }
        void imprimir()
        {
            vector<int>:: iterator it=v.begin();
            for(int i=1;i<=head;i++)
                cout<<*it<<" ";
                it++;
        }

};
int main()
{
    Cola<int> l(14);
    l.insertar(5);
    l.insertar(7);
    l.insertar(8);

    l.imprimir();
    return 0;
}