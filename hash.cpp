#include <iostream> 
#include <list> 
#include <math.h>
using namespace std; 

class Hash { 
    private:
        int V;
        list<int> *table;

    public: 

        Hash(int V);
        void insertItem( int x ); 
        int hashFunction( int x ) { 
            return x%V; 
        } 
        void displayHash();
        void deleteItem(int key);
        void allNum( int L );
}; 

Hash::Hash(int b) 
{ 
	this->V=b;
    table = new list<int>[V];
} 

void Hash::insertItem( int key ) 
{ 
	int index = hashFunction( key ); 
	table[index].push_back( key ); 
} 
void Hash::deleteItem(int key) 
{ 
    int index = hashFunction(key); 
    
    list <int> :: iterator i; 
    for (i = table[index].begin();i != table[index].end(); i++) { 
        if (*i == key) 
        break; 
    } 
    
    // if key is found in hash table, remove it 
    if (i != table[index].end())
        table[index].erase(i); 

} 
    
void Hash::displayHash() { 
    for( int i = 0; i < V; i++ ) { 
        cout << i; 
        for (auto x : table[i]) 
            cout << " --> " << x; 
        cout << endl; 
    } 
}


bool isPrime( int n )
{
    if( n == 2 || n == 3 )
        return true;

    if( n == 1 || n % 2 == 0 )
        return false;

    for( int i = 3; i * i <= n; i += 2 )
        if( n % i == 0 )
            return false;

    return true;
}

/**
 * Internal method to return a prime number at least as large as n.
 * Assumes n > 0.
 */
int nextPrime( int n )
{
    if( n % 2 == 0 )
        ++n;

    for( ; !isPrime( n ); n += 2 )
        ;

    return n;
}

int main() {
    int a[] = {15, 11, 27, 8, 12}; 
    int n = sizeof(a)/sizeof(a[0]); 
    
    Hash h(7);    
    for (int i = 0; i < n; i++)  
        h.insertItem(a[i]);   
    
    h.deleteItem(12); 
    

    h.displayHash(); 
    
    return 0;
} 
