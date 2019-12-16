#include <iostream>
#include <cstdlib>
using namespace std;

struct nodo{
     int nro;
     struct nodo *izq, *der;
};

nodo *crearNodo(int x)
{
     nodo *nuevoNodo = new(struct nodo);
     nuevoNodo->nro = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;

     return nuevoNodo;
}
int EsHoja(nodo *&r)
{
   return !r->der && !r->izq;
}

void auxAltura(nodo *&nod, int a, int *altura)
{
   /* Recorrido postorden */
   if(nod->izq) auxAltura(nod->izq, a+1, altura);
   if(nod->der) auxAltura(nod->der, a+1, altura);
   /* Proceso, si es un nodo hoja, y su altura es mayor que la actual del
      árbol, actualizamos la altura actual del árbol */
   if(EsHoja(nod) && a > *altura) *altura = a;
}
int Vacio(nodo *&r)
{
   return r==NULL;
}
int AlturaArbol(nodo *&a, int *altura)
{
   *altura = 0;

   auxAltura(a, 0, altura); /* Función auxiliar */
   return *altura;
}
int Altura(nodo *& a, int dat)
{
   int altura = 0;
   nodo *actual = a;

   /* Todavía puede aparecer, ya que quedan nodos por mirar */
   while(!Vacio(actual)) {
      if(dat == actual->nro) return altura; /* encontrado: devolver altura */
      else {
         altura++; /* Incrementamos la altura, seguimos buscando */
         if(dat < actual->nro) actual = actual->izq;
         else if(dat > actual->nro) actual = actual->der;
      }
   }
   return -1; /* No está en árbol, devolver -1 */
}
void insertar(nodo *&arbol, int x)
{
     if(arbol==NULL)
     {
           arbol = crearNodo(x);
     }
     else if(x < arbol->nro)
          insertar(arbol->izq, x);
     else if(x > arbol->nro)
          insertar(arbol->der, x);
}

void verArbol(nodo *arbol, int n)
{
     if(arbol==NULL)
          return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->nro <<endl;

     verArbol(arbol->izq, n+1);
}

int main()
{
    nodo *arbol = NULL;   // creado Arbol
    int altura;

    int n;  // numero de nodos del arbol
    int x; // elemento a insertar en cada nodo

    cout << "\n\t\t  ..[ ARBOL BINARIO DE BUSQUEDA ]..  \n\n";

    cout << " Numero de nodos del arbol:  ";
    cin >> n;
    cout << endl;

    for(int i=0; i<n; i++)
    {
        cout << " Numero del nodo " << i+1 << ": ";
        cin >> x;
        insertar( arbol, x);

    }
     verArbol(arbol,0);
    return 0;     
}