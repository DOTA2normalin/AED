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
            cout<<"NULL";
        }
        bool vacia()
        {
            if(first==NULL)
            {
                return true;
            }
            return false;
        }
        T extraer()
        {
            Nodo<T> *aux=first;
            int n;
            if(first!=NULL)
            {
                n=aux->dato;
                first=aux->next;
                delete aux;
            }
            return n;
        }
    friend class Semaforo;
};


int main()
{
    int n;
    cout<<"cantidad de semaforos ? ";
    cin>>n;
    ListaSimple<int> l;
    int tiempo;
    for(int i=1;i<=n;i++)
    {
        cout<<"tiempo para el semaforo " <<i<<"=";
        cin>>tiempo;
        l.insertar(tiempo); 
    }
    int *lista=new int[n]; 
    int tiempoactual=0;
    for(int j=0;j<n;j++)
    {
        lista[j]=l.extraer();
    }
    for(int k=0;k<n;k++)
    {
        cout<<lista[k]<<" ";
    }
    cout<< endl;
    int **aux[n][3];
    for(int a=0;a<n;a++)
    {
        int z=5;
        int *temp=&lista[a]-z;
        int *temp1=&z;
        int *temp2=&lista[a];
        for(int b=0;b<3;b++)
        {
            if(b==0)
            {
                aux[b][b]=&temp;
                aux[b][1]=&temp1;
                aux[b][2]=&temp2;
            }
            else if(b==1)
            {
                aux[b][b]=&temp;
                aux[b][1]=&temp1;
                aux[b][2]=&temp2;
            }
            else{
                aux[b][b]=&temp;
                aux[b][1]=&temp1;
                aux[b][2]=&temp2;
            }
        }
    }
    for(int q=0;q<n;q++)
    {
        
    }
    
    return 0;

}