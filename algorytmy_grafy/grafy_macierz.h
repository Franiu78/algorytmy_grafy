#ifndef GRAFY_MACIERZ_H
#define GRAFY_MACIERZ_H

#include <vector>
using namespace std;

class graf_macierz {
private:
    int V;
    vector<int> Matrix;

public:
    graf_macierz(int wierzcholki);
  

    void dodajKrawedz(int u, int v, int value);
    void wypisz();
    void DFS(int start);
    void BFS(int start);
    void LosowyGraf(int gestosc, int minValue = 1, int maxValue = 10);
    void Dijkstra(int start);
    bool BellmanFord(int start);


    
};


#endif