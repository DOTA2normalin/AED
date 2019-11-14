#include <iostream>
#include <vector>
#include <iterator>
#include <ctime> 
 
using namespace std;

void printLots(vector<int> &A, vector<int> &B)
{
    for (unsigned int i=0; i<B.size(); i++)
    {
        int  temp = B.at(i);

        for(unsigned int j=0;j<A.size();j++)
        {
            if(j==temp)
                cout<<A.at(j);  
        }
    }
}

int main()
{
    vector<int> A={5,8,7,3,6,5};
    vector<int> B={0,1,2};

    printLots(A, B);
    cout<<endl;
    A.push_back(7);
    cout<<A.back();
    cout<<endl;
    for( vector<int>::iterator itr = A.begin( ); itr != A.end( ); itr++ )
        cout << *itr <<" ";
    unsigned t0, t1;
    t0=clock();
    // Code to execute
    t1 = clock();
    
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;

    return 0;
}