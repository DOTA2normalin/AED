

#include <iostream>
using namespace std;



template <typename T>
class Nodo{
    
    T data;
    Nodo<T> *next;
    template<class U>
    friend class Pila;
};

template<typename T>
class Pila{
    int tam;
    Nodo<T> *raiz;
    Nodo<T> *fondo;
public:
    Pila();
    ~Pila();
    void insertar(T x);
    int extraer();
    void imprimir();
};
template<typename T>
Pila<T>::Pila(){
    raiz=NULL;
    fondo=NULL;
}
template<typename T>
Pila<T>::~Pila()
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
void Pila<T>::insertar(T x)
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
    tam++;
}

template<typename T>
int Pila<T>::extraer()
{
    if(raiz!=NULL)
    {
        T informacion=fondo->data;
        Nodo<T> *bor=fondo;
        if(raiz==fondo)
        {
            raiz=NULL;
            fondo=NULL;
        }
        else
        {
            Nodo<T> *rec=raiz;
            for(int i=1;i<=tam;i++)
            {
                if(i==tam-1)
                {
                    fondo=rec;
                }   
                rec=rec->next;
            }
        }   
        delete bor;
        return informacion;
    }
    else{
        return -1;
    }
}
template<typename T>
void Pila<T>::imprimir()
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
    Pila<int> p;
    int numero,fibo1,fibo2,i;
   do
   {
         cout << "Introduce numero mayor que 1: ";
         cin >> numero;
   }while(numero<=1);
   cout << endl;
    cout << "Los " << numero << " primeros numeros de la serie de Fibonacci son:" << endl;
   fibo1=1;
   fibo2=1;
   cout << fibo1 << " ";
   for(i=2;i<=numero;i++)
   {
       p.insertar(fibo2);
       fibo2 = fibo1 + fibo2;
       fibo1 = fibo2 - fibo1;
   }
   p.imprimir();
   cout << endl << endl;
    system("pause");
}