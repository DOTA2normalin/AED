#include <iostream>

using namespace std;

template <typename T>
class Nodo
{
    Nodo<T> *next;
    Nodo<T> *previus;
    T dato;

    template <typename U>
    friend class ListaDoble;
};

template <typename T>
class ListaDoble{
private:
    T count=0;
    Nodo<T> *first;
    Nodo<T> *last;
public:
    ListaDoble()
    {
        first=NULL;
        last=NULL;
    }
    ~ListaDoble()
    {
        Nodo<T> *recor=first;
        Nodo<T> *bor;
        while(recor!=NULL)
        {
            bor=recor;
            recor=recor->next;
            delete bor;
        }
    }
    T tam()
    {
        T count=0;
        Nodo<T> *aux=first;
        while(aux!=NULL)
        {
            aux=aux->next;
            count++;
        }
        return count;
    }
    void insertar(T x);
    Nodo<T>* imprimir(){
        Nodo<T> *recor=first;
        while(recor!=NULL)
        {
            cout<<recor->dato<<" -> ";
            recor=recor->next;
        }
    }
    void adyacente(T x)
    {
        Nodo<T> *recor=first;
        while(recor!=NULL)
        {
            if(recor->dato==x)
            {
                Nodo<T> *p,*afterp;
                recor = p->previus;
                afterp = p->next;

                p->next = afterp->next;
                recor->next = afterp;
                afterp->next = p;
                p->next->previus = p;
                p->previus = afterp;
                afterp->previus = recor;     
            }
            recor=recor->next;
        }
    }
    void eliminar(T pos);
    
};

template<typename T>
void ListaDoble<T>::eliminar(T pos)
{
        Nodo<T> *aux=first;
        Nodo<T> *aux2=aux->next;
        Nodo<T> *aux3=aux2->next;
        if(pos==0)
        {
            first = aux->next;
        }
        else{
            for(int i=1;i<=pos;i++)
            {
                if(i==pos)
                {
                    Nodo<T> *tem=aux2;
                    aux->next=aux2->next;
                    aux3->previus=aux2->previus;
                    delete tem;
                }
                aux=aux->next;
                aux2=aux2->next;  
                aux3=aux3->next;
            }
        }
}

template<typename T>
void ListaDoble<T>::insertar(T x)
{
    Nodo<T> *nuevo=new Nodo<T>();
    nuevo->dato=x;
    if(first==NULL)
    {
        first=nuevo;
        nuevo->next=NULL;
        nuevo->previus=NULL;
        last=nuevo;
    }
    else
    {
        last->next=nuevo;
        nuevo->next=NULL;
        nuevo->previus=last;
        last=nuevo;

    }
    count++;
}
int main()
{
    ListaDoble<int> l;
    l.insertar(4);
    l.insertar(5);
    l.insertar(8);
    l.insertar(9);
    l.insertar(10);
    l.imprimir();
    //l.eliminar(1);
    l.adyacente(2);
    cout<<endl;
    l.imprimir();
    return 0;
}