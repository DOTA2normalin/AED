
#include<stdlib.h>
#include<time.h>

#include <iostream>
using namespace std;

template<typename T>
class Nodo{
    T data;
    Nodo<T> *next;
    template<typename U>
    friend class Lista;
};

template<typename T>
class Lista{
public:
    T count;
    Nodo<T> *first;
    Nodo<T> *last;
public:
    Lista(){
        first=NULL;
        last=NULL;
    }
    ~Lista(){
        Nodo<T> *recor=first;
        Nodo<T> *bor;
        while(recor!=NULL)
        {
            bor=recor;
            recor=recor->next;
            delete bor;
        }
    }
    void insertar(T x);
    void imprimir();
    void buscar(T x);
    void eliminar(T x);
};



template<typename T>
void Lista<T>::insertar(T x)
{
    Nodo<T> *nuevo=new Nodo<T>();
    nuevo->data=x;
    if(first==NULL)
    {
        nuevo=first;
        nuevo->next=NULL;
        last=nuevo;
    }
    else{
        
    }
}

template<typename T>
void Lista<T>::imprimir()
{
    Nodo<T> *rec=first;
    while(rec!=NULL)
    {
        cout<<rec->data<<"->";
        rec=rec->next;
    }
    cout<<"NULL ";
}
template<typename T>
void Lista<T>::buscar(T x)
{
    Nodo<T>* actual=first;
    bool existe=false;
    while(actual!=NULL && actual->data<=x)
    {
        if(actual->data==x)
            existe=true;
        actual=actual->next;
    }
    if(existe==true)
    {
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}
template<typename T>
void Lista<T>::eliminar(T pos)
{
    Nodo<T> *temp = first;
    Nodo<T> *temp1 = temp->next;
 
    if(pos == 0) {
        first = temp->next;
    } else {

        for (int i = 1; i <= pos; i++) {
            if (i == pos) {
                Nodo<T> *aux= temp1;
                temp->next = temp1->next;
                delete aux;
                count--;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }
}
              
int main(){
    Lista<int> l;
    int n;
    cout<<"numero de jugadores: ";
    cin>>n;
    int velocidad;
    cout<<"velocidad? ";
    cin>>velocidad;
    for(int i=1;i<=n;i++)
    {
        l.insertar(i);
    }
    int count=n;
    l.imprimir();
    cout<<endl;
    int v=velocidad;
    l.eliminar(v);
    l.imprimir();
    cout<<endl;
    --count;
    while(count!=1)
    {
        v=v+velocidad;
        if(v>=count)
        {
            v=v-count;
        }
        l.eliminar(v);
        l.imprimir();
        cout<<endl;
        --count;
    }
    cout<<"------------------------"<<endl;
    cout<<"el ganador es ="<<endl;
    l.imprimir();
    return 0;
}
