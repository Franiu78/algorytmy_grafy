
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "grafy_macierz.h"
#include "grafy_lista.h"

using namespace std;


int main() 
{
    graf_macierz g(10);
    graf_lista h(10);

g.dodajKrawedz(0, 1, 2);
g.dodajKrawedz(0, 2, 5);
g.dodajKrawedz(1, 3, 1);
g.dodajKrawedz(2, 3, 2);
g.dodajKrawedz(3, 4, 3);

g.Dijkstra(0);
g.BellmanFord(0);

h.dodajKrawedz(0, 1, 2);
h.dodajKrawedz(0, 2, 5);
h.dodajKrawedz(1, 3, 1);
h.dodajKrawedz(2, 3, 2);
h.dodajKrawedz(3, 4, 3);

h.Dijkstra(0);
h.BellmanFord(0);
}
