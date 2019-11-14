#include <iostream>
using namespace std;

template <typename T>
class Nodo{
    T data;
    Nodo<T> *next;
    template<class U>
    friend class Cola;
};

template<typename T>
class Cola{
    int count=0;
    Nodo<T> *raiz;
    Nodo<T> *fondo;
public:
    Cola();
    ~Cola();
    void push(T x);
    int pop();
    void inyectar(T x);
    int expulsar();
    void imprimir();
};
template<typename T>
Cola<T>::Cola(){
    raiz=NULL;
    fondo=NULL;
}
template<typename T>
Cola<T>::~Cola()
{
    Nodo<T> *rec=raiz;
    Nodo<T> *bor;
    while(raiz!=NULL)
    {
        bor=rec;
        rec=rec->next;
        delete bor;
    }
}

template<typename T>
void Cola<T>::push(T x)
{
    Nodo<T> *nuevo;
    nuevo=new Nodo<T>();
    nuevo->data=x;
    nuevo->next=NULL;
    if(raiz==NULL)
    {
        raiz=nuevo;
        fondo=nuevo;
    }
    else{
        fondo->next=nuevo;
        fondo=nuevo;
    }
}

template<typename T>
int Cola<T>::pop()
{
    if(raiz!=NULL)
    {
        T informacion=raiz->data;
        Nodo<T> *bor=raiz;
        if(raiz==fondo)
        {
            raiz=NULL;
            fondo=NULL;
        }
        else
        {
            raiz=raiz->next;
        }
        delete bor;
        return informacion;
    }
    else{
        return -1;
    }
}
template<typename T>
void Cola<T>::inyectar(T x)
{
    Nodo<T> *nuevo=new Nodo<T>();
    nuevo->data=x;
    if(raiz!=NULL)
    {   
        fondo->next=nuevo;
        fondo=nuevo;
    }
}


template<typename T>
void Cola<T>::imprimir()
{
    Nodo<T> *rec=raiz;
    while(rec!=NULL)
    {
        cout<<rec->data<<"->";
        rec=rec->next;
    }
    cout<<"NULL";
}
int main()
{
    Cola<int> cola;
    cola.push(8);
    cola.push(6);
    cola.push(5);
    cola.push(1);
    cola.push(-9);
    cola.push(7);
    cola.imprimir();
    cout<<endl;
    cola.pop();
    cola.imprimir();
    cout<<endl;
    cola.inyectar(90);
    cola.imprimir();
    cout<<endl;
    cola.expulsar();
    cola.imprimir();
    return 0;
}