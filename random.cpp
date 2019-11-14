#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int numero=1+rand()%5;
    cout<<numero;
    return 0;
}