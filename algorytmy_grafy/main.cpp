
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "grafy_macierz.h"
#include "grafy_lista.h"
#include "test.h"

using namespace std;


int main() 
{
int tab[5] {10,50,100,200,500};
for(int i=0;i<5;i++)
{
    for (int j=25;j<=100;j+=25)
    {
        TestLista(tab[i],j);
        TestMacierz(tab[i],j);
    }
}



}
