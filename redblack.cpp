#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>

#define to_string( x ) static_cast< std::ostringstream & >(( std::ostringstream() << std::dec << x ) ).str()
using namespace std;
struct Node{
    int key;
    int color;
    Node*left,*right,*parent;
};
class RedBlack{
private:

public:
    Node*root;
    void left_rotate(Node * x);
    void right_rotate(Node * x);
    void Insert(int key);
    void Insert_fixup(Node* z);
    void Transplant(Node * u,Node * v);
    Node *Minimo(Node *tree);
    void Delete(int key);
    void Delete_fixup(Node* x);
    RedBlack(){root=nullptr;}
    void add(Node *p,Node *ph,ofstream&in){
        string a = to_string(p->key);
        string b = to_string(ph->key);


        //in<<a+"[label =\"<f0> "+a+"| <f1> "+c+"\" shape = "record" ];";
        //in<<"N_"+a+"_"+c+"->N_"+b+"_"+d+"\n";
        in<<a+"->"+b+"\n";
    }
    void recorrer(Node *p,ofstream&in){
        if (p == nullptr)return;
        string c;
        if(p->color==0)c="red";
        else c="black";
        in<<to_string(p->key)+"[color=\""+c+"\"];";
        if(p->left!=nullptr)
            add(p,p->left,in);
        if(p->right!=nullptr)
            add(p,p->right,in);
        recorrer(p->left,in);
        recorrer(p->right,in);
    }
    void graficar(string name){
        ofstream in("b.txt");
        in<<"digraph G{\n";
        in<<"node [fontname=Arial,fontsize=\"15\",style=filled,fontcolor=\"white\"];";
        recorrer(this->root,in);
        in<<"}";
        in.close();
        string out="dot -Tpng b.txt -o "+name+".png";
        char*a=&out[0];
        system(a);
        out="start "+name+".png";
        a=&out[0];
        system(a);
    }
};



void RedBlack::left_rotate(Node* x) {
    cout<<"izquierda"<<x->key<<endl;
    Node *y = x->right;
    x->right = y->left;

    if (y->left != nullptr)
        y->left->parent = x;

    y->parent =x->parent;


    if (x == this->root){
        this->root = y;

    }

    else if (x == x->parent->left){

        x->parent->left = y;
    }
    else{

        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;

}

void RedBlack::right_rotate(Node * x) {
    cout<<"derecha"<<x->key<<endl;
    Node *y = x->left;
    x->left = y->right;

    if (y->right != nullptr)
        y->right->parent = x;

    y->parent = x->parent;

    if (x->parent == nullptr)
        root = y;
    else if (x== x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->right = x;
    x->parent = y;
}

void RedBlack::Insert(int key) {

    Node *z=new Node;
    z->key=key;
    z->color=0;
    z->left=z->right=z->parent=nullptr;
    Node *y = nullptr;
    Node *x = this->root;

    while(x!=nullptr){
        y=x;
        if(z->key<x->key){
            x=x->left;
        }
        else
            x=x->right;
    }
    z->parent=y;
    if(y==nullptr){
        this->root=z;
    }
    else if(z->key<y->key)
        y->left=z;
    else
        y->right=z;
    z->left=nullptr;
    z->right=nullptr;
    z->color=0;
    //this->graficar("B");
    Insert_fixup(z);

}

void RedBlack::Insert_fixup(Node *z){

    Node*y;
    while(z->parent!=nullptr&&z->parent->color==0){
        if(z->parent==z->parent->parent->left){

            y=z->parent->parent->right;
            if(y!=nullptr&&y->color==0){
                z->parent->color=1;
                y->color=1;
                z->parent->parent->color=0;
                z=z->parent->parent;
            }
            else if(z==z->parent->right){
                z=z->parent;
                left_rotate(z);
            }
            else{
                z->parent->color=1;
                z->parent->parent->color=0;
                right_rotate(z->parent->parent);
            }
        }
        else {

            y=z->parent->parent->left;
            if(y!=nullptr&&y->color==0){
                z->parent->color=1;
                y->color=1;
                z->parent->parent->color=0;
                z=z->parent->parent;
            }
            else if(z==z->parent->left){
                z=z->parent;
                right_rotate(z);
            }
            else{

                z->parent->color=1;
                z->parent->parent->color=0;
                left_rotate(z->parent->parent);
            }
        }

    }
    this->root->color=1;
}

void RedBlack::Transplant(Node * u,Node * v){
    if(u->parent==nullptr)
        this->root=v;
    else if(u==u->parent->left)
        u->parent->left=v;
    else
        u->parent->right=v;
    if(v!=nullptr){
        v->parent=u->parent;
    }
}

Node *RedBlack::Minimo(Node *tree){
    while (tree->left!=nullptr){
      tree = tree->left;
    }
    return tree;

}
void RedBlack::Delete(int key){
    Node *z = this->root;
    while (z){
      if (z->key > key){
        z = z->left;
      }
      else if (z->key < key){
        z = z->right;
      }
      else
        break;
    }
    if (!z || z->key != key){
      return;
          }
    cout<<z->key<<endl;

    Node *x, *y,*w;
    int original=z->color;

    if (z->left==nullptr){
        x=z->right;
        w=z->parent;
        Transplant(z,z->right);
        if(x==nullptr)
            left_rotate(w);

    }
    else if (z->right==nullptr){
        x=z->left;
        w=z->parent;
        Transplant(z,z->left);
        if(x==nullptr)
            right_rotate(w);
    }
    else{
      y = Minimo(z->right);
      original = y->color;
      x = y->right;
      if (x!=nullptr && y->parent == z){
        x->parent = z;
      }
      else{
        Transplant(y, y->right);
        y->right = z->right;
        y->right->parent = y;
      }
     cout<<"2"<<x<<endl;
      Transplant(z, y);
      y->left = z->left;
      y->left->parent = y;
      y->color = z->color;x|
        cout<<"3"<<x<<endl;
    }

    cout<<"eliminado"<<endl;
    delete z;
    if(original==1 && x!=nullptr){
        Delete_fixup(x);
    }
  }
/*
 void RedBlack::Delete_fixup(Node* x){
    {
      bool side;
      Node *w;
      while (x != root && x->color == 1)
      {
        if ((side = (x == x->parent->left)))
        {
          w = x->parent->right;
        }
        else
        {
          w = x->parent->left;
        }

        if (w->color == 0)
        {
          w->color = 1;
          x->parent->color = 0;
          side ? left_rotate(x->parent) : right_rotate(x->parent);
          w = side ? x->parent->right : x->parent->left;
        }

        if (w->left->color == 1 && w->right->color == 0)
        {
          w->color = 0;
          x = x->parent;
        }
        else
        {
          if (1 == side ? w->right->color : w->left->color)
          {
            w->color = 0;
            if (side)
            {
              w->left->color = 1;
              right_rotate(w);
              w = x->parent->right;
            }
            else
            {
              w->right->color = 1;
              left_rotate(w);
              w = x->parent->left;
            }
          }

          w->color = x->parent->color;
          x->parent->color = 1;
          if (side)
          {
            w->left->color = 1;
            left_rotate(x->parent);
          }
          else
          {
            w->right->color = 1;
            right_rotate(x->parent);
          }

          x = root;
        }
      }
    }
  }

  */

void RedBlack::Delete_fixup(Node* x){
  cout<<"balanceando"<<endl;
  while (x!=nullptr&&x != this->root && x->color == 1){
    Node *w;
    cout<<"A";
    if(x->parent!=nullptr)
    if (x == x->parent->left){
        cout<<"B"<<endl;
        w = x->parent->right;
        if(w!=nullptr)
        if (w->color == 0){
            w->color = 1;
            x->parent->color = 0;
            left_rotate(x->parent);
            w = x->parent->right;
        }
        if(w!=nullptr)
        if(w->left!=nullptr)
        if(w->right!=nullptr)
        if (w->left->color == 1&& w->right->color == 0){
            w->color = 0;
            x = x->parent;
        }
        else if (w->right->color==1){
            w->left->color = 1;
            w->color=0;
            right_rotate(w);
            w=x->parent->right;
          }
        else{
            w->color = x->parent->color;
            x->parent->color = 1;
            w->right->color = 1;
            left_rotate(x->parent);
            x = root;
          }
    }
    else{
               cout<<"B"<<endl;
        w = x->parent->left;
        if(w!=nullptr)
        if (w->color == 0){
            w->color = 1;
            x->parent->color = 0;
            left_rotate(x->parent);
            w = x->parent->left;
        }
        if(w!=nullptr)
        if(w->left!=nullptr)
        if(w->left!=nullptr)
        if (w->left->color == 1&& w->left->color == 0){
            w->color = 0;
            x = x->parent;
        }
        else if (w->left->color==1){
            w->left->color = 1;
            w->color=0;
            left_rotate(w);
            w=x->parent->left;
          }
        else{
            w->color = x->parent->color;
            x->parent->color = 1;
            w->left->color = 1;
            left_rotate(x->parent);
            x = root;
          }
    }



    }
    x->color=1;
}

