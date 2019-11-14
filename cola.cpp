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
    Nodo<T> *raiz;
    Nodo<T> *fondo;
public:
    Cola();
    ~Cola();
    void insertar(T x);
    int extraer();
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
void Cola<T>::insertar(T x)
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
int Cola<T>::extraer()
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
    cola.insertar(8);
    cola.insertar(6);
    cola.insertar(5);
    cola.insertar(1);
    cola.insertar(-9);
    cola.insertar(7);
    cola.imprimir();
    cola.extraer();
    cola.imprimir();
    return 0;
}