#include<iostream>

using namespace std;

class Cola {
	int sizeactual;
	int size;
	int *pila;
public:
	Cola(int _size)
	{
		pila = new int [size];
		sizeactual =0;
		size = _size;
	}
	~Cola()	
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
			for(int i=0;i<size;i++)
            {
                pila[i]=pila[i+1];
            }
	}
    void mostrar()
    {
        for(int i=0;i<sizeactual;i++)
            cout<<pila[i]<<" ";
    }
};
int main()
{
	Cola l(5);
	l.push(4);
	l.push(5);
	l.push(6);
	l.mostrar();
    cout<<endl;
    l.pop();
    l.mostrar();
	system("pause");
	return 0;
}