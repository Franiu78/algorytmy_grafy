#ifndef GRAFY_LISTA_H
#define GRAFY_LISTA_H

#include <vector>
using namespace std;


struct AdjNode {
    int v;       // numer wierzcholka docelowego
    int value;     // waga krawedzi
    AdjNode* next;  // wskaznik na kolejna krawedz

    AdjNode(int cel, int value) : v(cel), value(value), next(nullptr) {}
};


class graf_lista {
private:
    int V;
    vector<AdjNode*> lista; // wektror wskaŸników na dane listy s¹siedztwa (ka¿da wierzcho³ek ma w³asn¹ listê)

public:
    graf_lista(int wierzcholki);
    ~graf_lista();

    void dodajKrawedz(int u, int v, int value);
    void wypisz();
    void DFS(int start);
    void BFS(int start);
    void LosowyGraf(int gestosc, int minValue = 1, int maxValue = 10);

};


#endif
