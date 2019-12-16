#include <iostream> 
#include <list> 
#include <math.h>
using namespace std; 

class Hash { 
    private:
        int tam; 
        list<pair<int,int>> *table;

    public: 

        Hash(int V);
        void insertItem( pair<int,int> x ); 
        int hashFunction( pair<int,int> x ) { 
            return pow( x.first, 3 ) + pow( x.second, 3 ); 
        } 
        void displayHash();
        void allNum( int L );
}; 

Hash::Hash(int b) 
{ 
	this->tam = b; 
	table = new list<pair<int,int>>[tam];
} 

void Hash::insertItem( pair<int,int> key ) 
{ 
	int index = hashFunction( key ); 
	table[index].push_back( key ); 
} 

void Hash::displayHash() { 
    for( int i = 0; i < tam; i++ ) { 
        cout << i; 
        for (auto x : table[i]) 
            cout << " --> " << x.first << " " << x.second; 
        cout << endl; 
    } 
}

void Hash::allNum( int L ) {
    for( int i = L; i >= 0; --i ) {
        int c = 0;
        for( auto x : table[ i ])
            ++c;
        if( c == 2 ) {
            std::cout << i << " -> ";
            for( auto y : table[ i ]) {
                std::cout << "( " << y.first << " " << y.second << " ) ";
            }
            std::cout << std::endl;
        }   
    }
}

int main() {
    Hash h(1000000); 
    int c = 1;
    for( int i = 0; i < 100; ++i ) {
        for( int j = i + 1; j < 100; ++j ) {
            if( pow( i, 3 ) + pow( j, 3 ) < 1000000 ) {
                pair<int,int> x = make_pair( i, j );
                h.insertItem( x );
                ++c;
            }
        }
    }
    
    int num;
    std::cin >> num;
    h.allNum( num );


    return 0; 
} 
