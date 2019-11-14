#include <iostream>
using namespace std;
void crearmatrizA(float A[20][20],int k,int m)
{
	for(int i=0; i<k; ++i){
        	for(int j=0; j<m; ++j)
        	{
            		cout<<"Ingrese valor para A["<<i<<"]["<<j<<"]: ";
            		cin>>A[i][j];
        	}
        	cout<<"\n";
	}
}
void mostrarmatricesA(float A[20][20],int k,int m)
{
 	cout<<"Matriz A: "<<endl;
    	for(int i=0; i<k; ++i)
    	{
        	for(int j=0; j<m; ++j)
        	{
            		cout<<A[i][j]<<" ";
        	}
        	cout<<endl;
    	}
}
void maxmin(float A[20][20],int k,int m,float *max,float *min)
{
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if( *max <= A[i][j])
                *max = A[i][j];
        }
    }
    for (int a = 0; a < k; a++)
    {
        for (int b = 0; b < m; b++)
        {
            if(*min>= A[a][b])
                *min = A[a][b];
        }
    }
    cout<<"max =";
    cout<<*max;
    cout<<"min =";
    cout<<*min;
    
}
int main()
{
    float A[20][20], B[20][20], C[20][20];
    int k, m;
    cout<<"Lectura de matriz A."<<endl;
    cout<<"Filas de A: "; cin>>k;
    cout<<"Columnas de A: "; cin>>m;
    crearmatrizA(A,k,m);
    mostrarmatricesA(A,k,m);
    float a=0;
    float b=A[0][0];
    float *pa=&a;
    float *pb=&b;
    maxmin(A,k,m,pa,pb);
    cout<<endl;
    system("pause");
    return 0;
}