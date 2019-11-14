#include <iostream>
using namespace std;
template<typename Objects,typename Comparator=less<Objects>>
class BinarySearchTree
{
    public:

    private:
        BinaryNode *root;
        Comparator isLessThan;
        bool contains(const Objects &x,BinaryNode *t)
        {
            if(t==nullptr)
                return false;
            else if(isLessThan(x,t->element))
                return contains(x,t->left);
            else if(isLessthan(t->element,x))
                return contains(t->right,x);
            else
                return true;
        }
};