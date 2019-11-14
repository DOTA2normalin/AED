
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
    void insertar(T x);
    void imprimir();
    void buscar(T x);
    void eliminar(T x);
    template<typename N>
    friend class Iterator;

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
    cout<<"NULL";
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
        cout<<"el numero si existe y es ="<<x;
    }
    else{
        cout<<"el numero no existe";
    }
}
template<typename T>
void Lista<T>::eliminar(T pos)
{
    Nodo<T> *temp = first;
    Nodo<T> *temp1 = temp->next;
 
    if (pos < 1 || pos > count) {
        cout << "Fuera de rango " << endl;
    } else if (pos == 1) {
        first = temp->next;
    } else {
        for (int i = 2; i <= pos; i++) {
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
    int count=0;
    int opc;
    do{
        cout<<endl;
        cout<<"1.Ingresar nodos. "<<endl;
        cout<<"2.mostrar lista."<<endl;
        cout<<"3.Jugar"<<endl;
        cout<<"4.terminar programa. "<<endl;
        cin>>opc;

        switch(opc)
        {
            case 1:
                int numero;
                cout<<"Ingrese un numero? :";
                cin>>numero;
                l.insertar(numero);
                count++;
                break;
            case 2:
                l.imprimir();
                cout<<endl;
                break;
            case 3:
                
                while(count!=1)
                {
                    srand(time(NULL));
                    int random=1+rand()%count;
                    l.eliminar(random);
                    count--;
                }
                break;
        }
        cout<<endl;
    }while(opc!=4);
    cout<<"---------------------"<<endl;
    cout<<"EL NUMERO GANADOR ES = "<<endl;
    l.imprimir();
    return 0;
}
