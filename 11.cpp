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
    Nodo<T> *first;
public:
    Lista(){
        first=NULL;
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
    T sizelist()
    {
        Nodo<T> *aux=first;
        T count=0;
        while(aux!=NULL)
        {
            count++;
            aux=aux->next;
        }
    }
    void insertar (T x);
    void imprimir ();
    void buscar (T x);
    void eliminar (T x);
};



template<typename T>
void Lista<T>::insertar(T x)
{
    Nodo<T> *nuevo=new Nodo<T>();
    nuevo->data=x;

    Nodo<T> *aux1=first;
    Nodo<T> *aux2;

    while(aux1!=NULL &&  aux1->data< x)
    {
        aux2=aux1;
        aux1=aux1->next;
    }
    if(first==aux1)
    {
        first=nuevo;
    }
    else
    {
        aux2->next=nuevo;
    }
    nuevo->next=aux1;
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
void Lista<T>::eliminar(T x)
{
    if(first!=NULL){
        Nodo<T> *aux1=first;
        Nodo<T> *aux2=NULL;

        while((aux1!=NULL) && (aux1->data!=x))
        {
            aux2=aux1;
            aux1=aux1->next;
        }
        if(aux1==NULL)
        {
            cout<<"el elemento no ha sido encontrado";
        }
        else if(aux2==NULL)
        {
            first=first->next;
            delete aux1;
        }
        else{
            aux2->next=aux1->next;
            delete aux1;
        }
    }
}
int main()
{
    Lista<int> l;
    l.insertar(4);
    l.insertar(5);
    l.insertar(6);
    l.insertar(9);
    l.imprimir();
    l.eliminar(4); 
    l.imprimir();
    l.buscar(6);
    return 0;
}