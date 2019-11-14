
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
    void insertar (T x);
    void imprimir ();
    void buscar (T x);
    void eliminar (T x);
    void interseccion (Lista<T> l1,Lista<T> l2)
    {
        Nodo<T> *aux1=l1.first;
        while(aux1!=NULL )
        { 
            Nodo<T> *aux2=l2.first;
            while(aux2!=NULL)
            {
                if(aux1->data==aux2->data)
                {
                    cout<<aux1->data<<" -> ";
                }
                aux2=aux2->next;
            }
            aux1=aux1->next;
        }
    }
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
    count++;
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

int main()
{
    Lista<int> L1,L2,l;
    int cantidad1,cantidad2;
    cout<<"cantidad de elementos para L1 ?";
    cin>>cantidad1;
    cout<<"cantidad de elementos para L2 ?";
    cin>>cantidad2;
    int x,y;
    for (int i=0;i<cantidad1;i++)
    {
        cout<<"ingrese un dato para L1: ";
        cin>>x;
        L1.insertar(x);
    }

    for(int j=0;j<cantidad2;j++)
    {
        cout<<"ingrese un dato para L2: ";
        cin>>y;
        L2.insertar(y);
    }
    L1.imprimir();
    cout<<endl;
    L2.imprimir();
    cout<<endl;
    l.interseccion(L1,L2);
}