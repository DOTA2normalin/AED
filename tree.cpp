#include <iostream>

using namespace std;

template <typename Comparable>
class BinarySearchTree
{
    public:
        BinarySearchTree();
        BinarySearchTree(const BinarySearchTree &rhs); //constructor copia
        BinarySearchTree(BinarySearchTree && rhs);
        ~BinarySearchTree()
        {
            makeEmpty();
        }
        const Comparable & findMin()const;
        const Comparable & findMax()const;
        bool contains(const Comparable & x)const; 
        bool isEmpty()const;
        void printTree(ostream &out=cout)const;

        void makeEmpty();
        void insert(const Comparable &x);
        void insert(Comparable &&x);
        void remove(const Comparable & x);

        BinarySearchTree &operator = (const BinarySearchTree &rhs);
        BinarySearchTree &operator =(BinarySearchTree &&rhs);

        private:
            struct BinaryNode
            {
                Comparable element;
                BinaryNode *left;
                BinaryNode *right;

                BinaryNode(const Comparable &theElement,BinaryNode *lf,BinaryNode *rt)
                :element{theElement}, left{lf},right{rt}{}
                BinaryNode(Comparable && theElement,BinaryNode *lf,BinaryNode*rt)
                :element{theElement},left{lf},right{rt}{}

                template<typename U>
                friend class BinarySearchNode;
            };
            
            BinaryNode *root;

            void insert(const Comparable &x,BinarySearchTree *& t);
            void insert(Comparable &&x,BinaryNode *&t);
            void remove(const Comparable &x,BinaryNode *&t);
            BinaryNode *findMin(BinaryNode *t)const;
            BinaryNode *findMax(BinaryNode *t)const;
            bool contains(const Comparable &x,BinaryNode *t)const;
            void makeEmpty(BinaryNode *&t);
            void printTree(BinaryNode *t,ostream& out)const;
            BinaryNode *clone(BinaryNode *t)const;

};


template<typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable &x)const
{
    return contains(x,root);
}
template<typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable &x)
{
    insert(x,root);
}
template<typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable &x)
{
    remove(x,root);
}
template<typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable &x,BinaryNode *t)const{
    if(t==nullptr)
        return false;
    else if(x <t->element)
        return contains(x,t->left);
    else if(t->element<x)
        return contains(x,t->right);
    else
        return true;
}

template<typename Comparable>
BinaryNode *BinarySearchTree<Comparable>::findMin(BinaryNode<Comparable> *t)const
{
    if(t==nullptr)
        return nullptr;
    if(t->left==nullptr)
        return t;
    return findMin(t->left);

}

template<typename Comparable>
BinaryNode *BinarySearchTree<Comparable>::findMax(BinaryNode<Comparable> *t)const
{
    if(t!=nullptr){
        while(t->right!=nullptr)
            t=t->right;
    }
    return t;
}

template<typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable& x,BinaryNode *&t)
{
    if(t==nullptr)
        t=new BinaryNode<T>(x,nullptr,nullptr);
    else if(x<t->element)
        insert(x,t->left);
    else if(t->element<x)
        insert(x,t->right);
    else
        ;
}

template<typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable&& x,BinaryNode *&t)
{
    if(t==nullptr)
        t=new BinaryNode<T>(std::move(x),nullptr,nullptr);
    else if(x<t->element)
        insert(std::move(x),t->left);
    else if(t->element<x)
        insert(std::move(x),t->right);
    else
        ;
}
template<typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable &x, BinaryNode *&t)
{
    if(t==nullptr)
        return ;
    if(x<t->element)
        remove(x,t->left);
    else if(t->element<x)
        remove(x,t->right);
    else if(t->left!=nullptr && t->right !=nullptr)
    {
        t->element =findMin(t->right)->element;
        remove(t->element,t->right);
    }
    else
    {
        BinaryNode<Comparable> *oldNode=t;
        t=(t->left!=nullptr)?t->left:t->right;
        delete oldNode;
    }
}


template<typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty(BinaryNode *&t)
{
    if(t!=nullptr)
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t=nullptr:
}
template<typename Comparable>
BinarySearchTree::BinarySearcTree(const BinarySearchTree):root{nullptr}
{
    root=clone(rhs.root);
}
template<typename Comparable>
BinaryNode* BinarySearchTree::clone(BinaryNode *t)
{
    if(t==nullptr)
        return nullptr;
    else
        return new BinaryNode<Comparable>(t->element,clone(t->left),clone(t->right));
}
