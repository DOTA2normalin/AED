#include<iostream> 
#include<cmath>
#include <list> 
using namespace std; 
  
class Hash 
{ 
    int BUCKET;    // No. of buckets 
  
    // Pointer to an array containing buckets 
    list<int> *table; 
public: 
    Hash(int V);  // Constructor 
  
    // inserts a key into hash table 
    void insertItem(int x); 
  
    // deletes a key from hash table 
    void deleteItem(int key); 
  
    // hash function to map values to key 
    int hashFunction(int x) { 
        return (x % BUCKET); 
    } 
  
    void displayHash(); 
}; 
  
Hash::Hash(int b) 
{ 
    this->BUCKET = b; 
    table = new list<int>[BUCKET]; 
} 
  
void Hash::insertItem(int key) 
{ 
    int index = hashFunction(key); 
    table[index].push_back(key);
} 
  
void Hash::deleteItem(int key) 
{ 
  // get the hash index of key 
  int index = hashFunction(key); 
  
  // find the key in (inex)th list 
  list <int> :: iterator i; 
  for (i = table[index].begin(); 
           i != table[index].end(); i++) { 
    if (*i == key) 
      break; 
  } 
  
  // if key is found in hash table, remove it 
  if (i != table[index].end()) 
    table[index].erase(i); 
} 
  
// function to display hash table 
void Hash::displayHash() { 
  for (int i = 1; i <=BUCKET; i++) { 
    cout << i; 
    for (auto x : table[i]) 
      cout << " --> " << x; 
    cout << endl; 
  } 
} 
  
// Driver program  
int main() 
{ 
  // array that contains keys to be mapped 
    int NUMS=9;
    int cabeza = pow(NUMS   , 1.0 / 3.0); 
    int array[cabeza + 1]; 
    int matrix[cabeza+1];
    int k=0;
    if(0<NUMS<1000000)
    {
        
        for (int i = 1; i <= cabeza; i++) 
            array[i] = i*i*i; 
    
        int l = 1; 
        int r = cabeza; 
    
        while (l < r) 
        { 
            if (array[l] + array[r] < NUMS) 
                l++; 
            else if(array[l] + array[r] > NUMS) 
                r--; 
            else { 
                matrix[k]=l;
                k++;
                matrix[k]=r;
                k++;
                l++; r--;
                
            } 
        }
    }

      
      // insert the keys into the hash table 
    Hash h(NUMS);   // 7 is count of buckets in 
                   // hash table 
    for (int i = 0; i < k+1; i++)  
        h.insertItem(matrix[i]);   
    h.insertItem(2);
      // display the Hash table 
    h.displayHash(); 
  
  return 0; 
} 