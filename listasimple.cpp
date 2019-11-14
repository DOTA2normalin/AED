#include <iostream>
using namespace std;


template<typename T>
class Nodo
{
    private:
        int dato;
        Nodo<T> *next;
    template<typename U>
    friend class ListaSimple;
};

template<typename T>
class ListaSimple
{
    private:
        Nodo<T> *first;
        Nodo<T> *last;
    public:
        ListaSimple()
        {
            first=NULL;
            last=NULL;
        }
        ~ListaSimple()
        {
            Nodo<T> *recor=first;
            Nodo<T> *bor;
            while(!recor)
            {
                bor=recor;
                recor=recor->next;
            }
        }
        void insertar(int x)
        {
            Nodo<T> *nuevo=new Nodo<T>();
            nuevo->dato=x;
            if(first==NULL)
            {
                first=nuevo;
                nuevo->next=NULL;
                last=nuevo;
            }
            else{
                last->next=nuevo;
                nuevo->next=NULL;
            }   last=nuevo;
        }
        void imprimir()
        {
            Nodo<T>* aux=first;
            while(aux!=NULL)
            {
                cout<<aux->dato<<"->";
                aux=aux->next;
            }
        }
        void cambiar(int x)
        {
            Nodo<T> *recor=first;
            while(recor!=NULL)
            {
                if(recor->dato==x)
                {
                    Nodo<T> *p,*afterp;
                    p=recor->next;
                    afterp=p->next;

                    p->next = afterp-> next;
                    recor ->next = afterp;
                    afterp->next = p;      
                }
                recor=recor->next;
            }   
        }      
};


int main()
{
    ListaSimple<int> l;
    l.insertar(4);
    l.insertar(5);
    l.insertar(8);
    l.insertar(10);
    l.insertar(22);
    l.insertar(30);
    l.insertar(40);
    l.imprimir();
    cout<<endl;
    l.cambiar(2);
    l.imprimir();
    return 0;
}