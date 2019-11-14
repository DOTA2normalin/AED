#include <iostream>

using namespace std;
int count=0;
void insertar(int *lista,int valor)
{
    *(lista+count)=valor;
    count++;
}
void deletepos(int *lista,int pos)
{
    for(int i=0;i<count;i++)
    {
        if(i==pos)
        {
            for(int i=pos;i<count;i++)
            {
                *(lista+i)=*(lista+i+1);
            }
        }
    }
    count--;
}
void mostrar(int *lista)
{
    for(int i=0;i<count;i++)
    {
        cout<<*(lista+i)<<"->";
    }
}

void deleteall(int *lista)
{
    delete [] lista;
}
int main()
{

    int *lista;
    lista=new int[count]();
    insertar(lista,4);
    insertar(lista,5);
    insertar(lista,6);
    insertar(lista,7);
    insertar(lista,8);
    mostrar(lista);
    deletepos(lista,2);
    cout<<endl;
    mostrar(lista);

    deleteall(lista);
    return 0;
}
