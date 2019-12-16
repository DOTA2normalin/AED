#include <iostream>
#include <vector>
using namespace std;
struct nodo{
    int dato;
    struct nodo *primero;
    struct nodo *segundo;
    struct nodo *tercero;
    nodo(const int _dato,nodo *p,nodo *s,nodo *t):dato{_dato},primero{p},segundo{s},tercero{t}{}
};

void insertar(nodo *&t,int x)
{

    if(t==nullptr)
        t=new nodo{x,nullptr,nullptr,nullptr};
    else if(t->dato < x)
        insertar(t->primero,x);
    else if(t->dato==x){
        insertar(t->segundo,x);
    }
    else if(t->dato > x)
        insertar(t->tercero,x);
}
int ancestro(nodo *t,int a,int b)
{
    if(t==nullptr)
        return -1;
    else if(t->dato < a && t->dato > b )
        return t->dato;
    else if(t->dato > a&& t->dato < b)
        return t->dato;
    else if(t->dato > a && t->dato > b)
        ancestro(t->primero,a,b);
    else if(t->dato < a && t->dato < b)
        ancestro(t->tercero,a,b);
    else if(t->dato == a && t->dato == b)
        ancestro(t->segundo,a,b);
}
void ancestro2(nodo *t,int a,int b)
{

}
void print(nodo *&t, int n)
{
    if(t==nullptr)
        return;
    print(t->primero,n+1);
    for(int i=0;i<n;i++)
        cout<<"    ";
    cout<<t->dato<<"   "<<endl;
    print(t->segundo,n+1);
    print(t->tercero,n+1);
}

int main()
{
    nodo *t=nullptr;
    insertar(t,10);
    insertar(t,15);
    insertar(t,7);
    insertar(t,10);
    insertar(t,20);
    print(t,0);
    cout<<ancestro(t,10,20);
    return 0;
}

