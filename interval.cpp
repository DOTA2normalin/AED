//
//  intervalTree.cpp
//  
//
//  Created by edson on 11/4/19.
//

//#include "intervalTree.hpp"
//
// Created by edson on 11/4/19.
//

#include <iostream>
using namespace std;
// Estructura que representa un intervalo
struct Interval
{
    int low, high;
};
// estructura que representa un nodo de Interval Search Tree
struct ITNode
{
    Interval *i;
    int max;
    ITNode *left, *right;
};

// funcion que crea un nodo Interval Search Tree
ITNode * newNode(Interval i)
{
    ITNode *temp = new ITNode;
    temp->i = new Interval(i);
    temp->max = i.high;
    temp->left = temp->right = NULL;
};

// función que inserta un nodo
//  El valor low del intervalo
// es usado para mantener el orden BST
ITNode *insert(ITNode *root, Interval i)
{
    // caso base:
    if (root == NULL)
        return newNode(i);

    //  obtenemos low value del intervalo root
    int l = root->i->low;

    // Si el valor low es menor, entonces el nuevo intervalo va a
    // subarbol izquierdo
    if (i.low < l)
        root->left = insert(root->left, i);

        //
    else
        root->right = insert(root->right, i);

    // Actualice el valor máximo de este ancestro si es necesario
    if (root->max < i.high)
        root->max = i.high;

    return root;
}

// funcion que verifica si dados dos segmentos estos se sobreponen
bool doOVerlap(Interval i1, Interval i2)
{
    if (i1.low <= i2.high && i2.low <= i1.high)
        return true;
    return false;
}
// La función principal que busca un intervalo i en un Interval tree
Interval *overlapSearch(ITNode *root, Interval i)
{
    // caso base
    if (root == NULL) return NULL;

    // si el intervalo se sobrepone con root
    if (doOVerlap(*(root->i), i))
        return root->i;

    // complete
    if(root->left != NULL && root->left->max >= i.low) 
        return overlapSearch(root->left, i); 

    // caso contrario solo se podria ir al sub arbol derecho
    return overlapSearch(root->right, i);
}


Interval *superpone(ITNode *root, Interval i)
{
    // caso base
    if (root == NULL) return NULL;

    // si el intervalo se sobrepone con root
    if (doOVerlap(*(root->i), i) && root->left!=NULL)
        return root->i;   
    else
    {
         return NULL;
    }
    return superpone(root->left, i);
    
}

void inorder(ITNode *root)
{
    //implementar inorder
    if (root == NULL) return; 
  
    inorder(root->left); 
  
    cout << "[" << root->i->low << ", " << root->i->high << "]"
         << " max = " << root->max << endl; 
  
    inorder(root->right); 
}


int main()
{
    // .......
    // construir arbol del ejemplo de la figura 1
     Interval ints[] = {{15, 20}, {10, 30}, {17, 19}, 
        {5, 20}, {12, 15}, {30, 40}
    }; 
    int n = sizeof(ints)/sizeof(ints[0]); 
    ITNode *root = NULL; 
    for (int i = 0; i < n; i++) 
        root = insert(root, ints[i]); 
  
    cout << "Inorder traversal of constructed Interval Tree is\n"; 
    inorder(root); 
    
    Interval x = {16, 19}; 
    Interval *m=superpone(root,x);
    cout<<"\n buscando para el intervalo low minimo ["<<x.low << ","<< x.high <<"]";
    if (m == NULL) 
        cout << "\nNo Sobreponiendo  Interval"; 
    else
        cout << "\n Sobreponiendo con [" << m->low << ", " << m->high << "]";
    return 0;

}  