
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "grafy_macierz.h"
#include "grafy_lista.h"

using namespace std;


int main() 
{
    graf_macierz g(500);
    graf_lista h(500);

    g.LosowyGraf(100);

    g.wypisz();
    h.LosowyGraf(100);
    

    h.wypisz();

    g.DFS(0);
    h.DFS(0);
    g.BFS(0);
    h.BFS(0);
    return 0;
}
