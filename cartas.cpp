#include <iostream>
using namespace std;
void cartas(int);
void cartas1(int);
template <typename T>
class Nodo {
	T data;
	Nodo<T>* next;
	template<class U>
	friend class Cola;
};

template<typename T>
class Cola {
	Nodo<T>* raiz;
	Nodo<T>* fondo;
public:
	Cola();
	~Cola();
	void insertar(T x);
	void extraer();
	void imprimir();
	void mover() 
	{
		Nodo<T>* aux = raiz;
		Nodo<T> *aux2=fondo;
		if (raiz != NULL )
		{
			int valor=aux->data;
			raiz=aux->next;
			insertar(valor);
		}
	}
};
template<typename T>
Cola<T>::Cola() {
	raiz = NULL;
	fondo = NULL;
}
template<typename T>
Cola<T>::~Cola()
{
	Nodo<T>* rec = raiz;
	Nodo<T>* bor;
	while (raiz != NULL)
	{
		bor = rec;
		rec = rec->next;
    	delete bor;
	}
}

template<typename T>
void Cola<T>::insertar(T x)
{
	Nodo<T>* nuevo;
	nuevo = new Nodo<T>();
	nuevo->data = x;
	nuevo->next = NULL;
	if (raiz == NULL)
	{
		raiz = nuevo;
		fondo = nuevo;
	}
	else {
		fondo->next = nuevo;
		fondo = nuevo;
	}
}

template<typename T>
void Cola<T>::extraer()
{
	Nodo<T>* aux = raiz;
	if (raiz != NULL)
	{
		raiz = aux->next;
		delete aux;
	}
}
template<typename T>
void Cola<T>::imprimir()
{
	Nodo<T>* rec = raiz;
	while (rec != NULL)
	{
		cout << rec->data << "->";
		rec = rec->next;
	}
	cout << "NULL";
}

void cartas1(int n)
{
	Cola<int> l;
	for (int i = 1; i <= n; i++)
	{
		l.insertar(i);
	}
	l.imprimir();
	cout<<endl;
	while(n!=0)
	{
		l.extraer();
		l.mover();
		l.imprimir();
		cout<<endl;
		n--;
	}
	l.extraer();
	l.imprimir();
}
int main()
{
	
	int n;
	cout << "cantidad de cartas ? ";
	cin >> n;
	cartas1(n);
	return 0;
}