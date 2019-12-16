#include<iostream>
using namespace std;

template <class T>
class Node{

public:
    T valor;
    T row;
    T column;
    Node<T> *siguiente;
    //Node<T> *siguientefila;

    Node<T>(T dato){row = 0,column = 0,valor=dato,siguiente=NULL;}
    Node<T>(){row = 0,column = 0,valor=0,siguiente=NULL;}
    Node<T>(T dato,T row1 , T column1){row = row1,column = column1,valor=dato,siguiente=NULL;}

};


template <class T>
class lista
{

    Node<T> *head;
    Node<T> *actual;
public:
    lista(){head=NULL,actual=NULL;}

    void insertar(T v, T x, T y);
    void insertarpos(T valor,T pos);
    void eliminar(T pos);

    void mostrar();
    ///////////matriz dispersa////////////////
    void sumar_ma(lista<T> a,lista<T> b);
    void restar_ma(lista<T> a,lista<T> b);

    template<size_t rows, size_t cols>
    void compress(int (&a)[rows][cols])
    {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)

            // Pass only those values which are non - zero
                if (a[i][j] != 0)
                    this->insertar(a[i][j], i, j);

    }
    //////////////////////////////////////////
    void insertar_node(Node<T> *a)
    {
        if(head==NULL)
        {
            head=a;
            head->row = a->row;
            head->column = a->column;
        }
        else{
            actual->siguiente=a;
            

        }
        actual=a;
    }
};

template <class T>
void lista<T>::insertar(T v, T x, T y)
{
    Node<T> *nuevo=new Node<T>(v);
        if(head == NULL)
        {
            Node<T> *newHead = new Node<T>();
            newHead->valor=v;
            newHead->siguiente = head;
            head = newHead;
            head->row = x;
            head->column = y;
        }
        else
        {
            Node<T> *actual = head;
            while(actual->siguiente != NULL)
            {
                actual = actual->siguiente;
            }
            actual->siguiente = new Node<T>(v);
            actual->siguiente->row = x;
            actual->siguiente->column = y;
        }
    actual=nuevo;
}

template <class T>
void lista<T>::mostrar()
{
    Node<T> *tmp=head;
    while(tmp)
    {
        cout <<tmp->valor <<"|"<< tmp->row <<"|"<< tmp->column<<endl;
        tmp=tmp->siguiente;

    }
    cout<<endl;
}

template <class T>
void lista<T>::insertarpos(T v, T pos)
{
    Node<T> *nuevo=new Node<T>(v);
    Node<T> *tmp=head;
    if(pos==1)
    {
        nuevo->siguiente=head;
        head=nuevo;
    }
    else{
         for(int i=2;tmp!=NULL;i++){
            if(i==pos){
                nuevo->siguiente=tmp->siguiente;
                tmp->siguiente=nuevo;
            }
            tmp=tmp->siguiente;
        }
    }
}
////////////////////////////////////////////////////////////////////////
template <class T>
void lista<T>::sumar_ma(lista<T> a,lista<T> b){
   Node<T> *tmp1=a.head, *tmp2=b.head;

    while (tmp1 != NULL && tmp2 !=NULL) {
        if(tmp1->column ==tmp2->column){
            if (tmp1->row == tmp2->row){

                Node<T> *nuevo=new Node<T>(tmp1->valor+tmp2->valor,tmp1->row,tmp1->column);
                this->insertar_node(nuevo);
                tmp1=tmp1->siguiente;
                tmp2=tmp2->siguiente;
            }
            else if(tmp1->row < tmp2->row)
            {
                Node<T> *nuevo=new Node<T>(tmp1->valor,tmp1->row,tmp1->column);
                this->insertar_node(nuevo);
                tmp1=tmp1->siguiente;
            }
            else{
                Node<T> *nuevo=new Node<T>(tmp2->valor,tmp2->row,tmp2->column);
                this->insertar_node(nuevo);
                tmp2=tmp2->siguiente;
            }
        }
        else if(tmp1->column < tmp2->column)
        {
            Node<T> *nuevo=new Node<T>(tmp1->valor,tmp1->row,tmp1->column);
            this->insertar_node(nuevo);
            tmp1=tmp1->siguiente;
        }
        else
        {
            Node<T> *nuevo=new Node<T>(tmp2->valor,tmp2->row,tmp2->column);
            this->insertar_node(nuevo);
            tmp2=tmp2->siguiente;
        }

    }
    if(tmp1==NULL)
    {
        while(tmp2)
        {
            Node<T> *nuevo=new Node<T>(tmp2->valor,tmp2->row,tmp2->column);
            this->insertar_node(nuevo);
            tmp2=tmp2->siguiente;
        }
    }
    if(tmp2==NULL)
    {
        while(tmp1)
        {
            Node<T> *nuevo=new Node<T>(tmp1->valor,tmp1->row,tmp1->column);
            this->insertar_node(nuevo);
            tmp1=tmp1->siguiente;
        }
    }

}

template <class T>
void lista<T>::restar_ma(lista<T> a,lista<T> b){
   Node<T> *tmp1=a.head, *tmp2=b.head;

    while (tmp1 != NULL && tmp2 !=NULL) {
        if(tmp1->column ==tmp2->column){
            if (tmp1->row == tmp2->row){

                Node<T> *nuevo=new Node<T>(tmp1->valor-tmp2->valor,tmp1->row,tmp1->column);
                this->insertar_node(nuevo);
                tmp1=tmp1->siguiente;
                tmp2=tmp2->siguiente;
            }
            else if(tmp1->row < tmp2->row)
            {
                Node<T> *nuevo=new Node<T>(tmp1->valor,tmp1->row,tmp1->column);
                this->insertar_node(nuevo);
                tmp1=tmp1->siguiente;
            }
            else{
                Node<T> *nuevo=new Node<T>(tmp2->valor,tmp2->row,tmp2->column);
                this->insertar_node(nuevo);
                tmp2=tmp2->siguiente;
            }
        }
        else if(tmp1->column < tmp2->column)
        {
            Node<T> *nuevo=new Node<T>(tmp1->valor,tmp1->row,tmp1->column);
            this->insertar_node(nuevo);
            tmp1=tmp1->siguiente;
        }
        else
        {
            Node<T> *nuevo=new Node<T>(tmp2->valor,tmp2->row,tmp2->column);
            this->insertar_node(nuevo);
            tmp2=tmp2->siguiente;
        }

    }
    if(tmp1==NULL)
    {
        while(tmp2)
        {
            Node<T> *nuevo=new Node<T>(tmp2->valor,tmp2->row,tmp2->column);
            this->insertar_node(nuevo);
            tmp2=tmp2->siguiente;
        }
    }
    if(tmp2==NULL)
    {
        while(tmp1)
        {
            Node<T> *nuevo=new Node<T>(tmp1->valor,tmp1->row,tmp1->column);
            this->insertar_node(nuevo);
            tmp1=tmp1->siguiente;
        }
    }

}


int main()
{

    int m[4][5] =
    {
        {1 , 10 , 3 },
        {0 , 0 , 5 },
        {0 , 0 , 0 },
        {0 , 2 , 6 }
    };
    int m1[4][5] =
    {
        {1 , 1 , 3 },
        {0 , 0 , 5 },
        {0 , 0 , 0 },
        {0 , 2 , 6 }
    };
    cout<<"\n Matriz 1 \n"<<endl;
    lista<int> b;
    b.compress(m1);
    b.mostrar();

    cout<<"\n Matriz 2 \n"<<endl;
    lista<int> a;
    a.compress(m);
    a.mostrar();

    cout<<"\n Suma: \n"<<endl;

    lista<int> c;
    c.sumar_ma(a,b);
    c.mostrar();
    cout<<endl;
    cout<<"\n Resta: \n"<<endl;
    lista<int> d;
    d.restar_ma(a,b);
    d.mostrar();

    int sparseMatrix[4][5] =
        {
            {0 , 0 , 3 , 0 , 4 },
            {0 , 0 , 5 , 7 , 0 },
            {0 , 0 , 0 , 0 , 0 },
            {0 , 2 , 6 , 0 , 0 }
        };

    int size = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (sparseMatrix[i][j] != 0)
                size++;

    // number of columns in compactMatrix (size) must be
    // equal to number of non - zero elements in
    // sparseMatrix
    int compactMatrix[3][size];

    // Making of new matrix
    int k = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (sparseMatrix[i][j] != 0)
            {
                compactMatrix[0][k] = i;
                compactMatrix[1][k] = j;
                compactMatrix[2][k] = sparseMatrix[i][j];
                k++;
            }

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<size; j++)
            cout<<compactMatrix[i][j]<<" ";
        cout<<endl;
    }
}