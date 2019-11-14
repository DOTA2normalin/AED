#include<iostream>

using namespace std;

class Pila {
	int size;
	int next;
    int pre;
	int *pila;
public:
	Pila(int _size)
	{
		pila = new int [size];
		next =0;
        pre=size-1;
		size = _size;
        for(int i=0;i<size;i++)
        {
            pila[i]=0;
        }
	}
	~Pila()	
	{
		delete[] pila;
	}
	void push(int dato1,int dato2)
	{

		if (next>size)
		{
			cout<<"cantidad excedido ";
		}
		else{
			pila[next] = dato1;
            pila[pre] = dato2;
            pre--;
			next++;
		}
	}
	void pop()
	{
		if(next==0)
			cout<<"no hay elementos por retirar";
		else
			pila[next]=0;
			next--;
	}
    void mostrar()
    {
        for(int i=0;i<size;i++)
            cout<<pila[i]<<" ";
    }
};
int main()
{
	Pila l(10);
	l.push(4,8);
	l.push(5,9);
	l.push(6,7);
	l.mostrar();
	system("pause");
	return 0;
}