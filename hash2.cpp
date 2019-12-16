#include <iostream> 
#include <list> 
#include <math.h>
using namespace std; 

class Hash { 
    private:
        int tam; 
        list<char> *table;

    public: 
        Hash( int b );
        void insertItem( char A, char B ); 
        int hashFunction( char x ) { 
            return x - 64;  
        } 
        void displayHash();
        char searchItem( char key );
}; 

Hash::Hash( int b ) { 
	this -> tam = b; 
	table = new list<char>[ tam ];
} 

void Hash::insertItem( char key1, char val ) { 
	int index = hashFunction( key1 );
    
    for( auto x : table[ index ]) {
        if( x != val ) {
            std::cout << "Aren't Isomorphics" << std::endl;
            return;
        }
    }
	
    table[index].push_back( val ); 
} 

void Hash::displayHash() { 
    for( int i = 0; i < tam; i++ ) { 
        cout << i; 
        for( auto x : table[ i ]) 
            cout << " -> " << x << " "; 
        cout << endl; 
    } 
}

char Hash::searchItem( char key ) {
    for( auto x : table[ key - 64 ])
    return x;
}

int main() {
    Hash h( 27 );
    string A = "HCHR";
    string B = "ECAO";
    
    if( A.size() == B.size()) {
        for( int i = 0; i < A.size(); ++i )
            h.insertItem( A[ i ], B[ i ]);
    }


    // h.displayHash();
    char c;
    std::cin >> c;
    std::cout << h.searchItem( c ) << std::endl;
    
    return 0; 
} 
