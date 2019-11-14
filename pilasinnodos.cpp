#include<iostream>

using namespace std;

class Pila {
	int sizeactual;
	int size;
	int *pila;
public:
	Pila(int _size)
	{
		pila = new int [size];
		sizeactual =0;
		size = _size;
	}
	~Pila()	
	{
		delete[] pila;
	}
	void push(int dato)
	{
		if (sizeactual>size)
		{
			cout<<"cantidad excedido ";
		}
		else{
			pila[sizeactual] = dato;
			sizeactual++;
		}
	}
	void pop()
	{
		if(sizeactual==0)
			cout<<"no hay elementos por retirar";
		else
			pila[sizeactual]=0;
			sizeactual--;
	}
    void mostrar()
    {
        for(int i=0;i<sizeactual;i++)
            cout<<pila[i]<<" ";
    }
};
int main()
{
	Pila l(5);
	l.push(4);
	l.push(5);
	l.push(6);
	l.mostrar();
	system("pause");
	return 0;
}