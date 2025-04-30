#include "grafy_macierz.h"
#include <iostream>
#include <stack>
#include <queue>
#include <random>
#include <set>

using namespace std;

graf_macierz::graf_macierz(int wierzcholki) : V(wierzcholki), Matrix(wierzcholki* wierzcholki, 0) {}



void graf_macierz::dodajKrawedz(int u, int v, int value = 1)
{
    if(u<V && v<V)
    Matrix[u * V + v] = value;
}
void graf_macierz::wypisz() 
{
    cout << "Macierz sasiedztwa:\n";
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            cout << Matrix[i * V + j] << " ";
        }
        cout << endl;
    }
}

void graf_macierz::DFS(int start) //przeszukaj w glab
{
    vector<bool> odwiedzony(V, false);
    stack<int> s;

    s.push(start);

    cout << "DFS od wierzcholka " << start << ": ";

    while (!s.empty()) {
        int v = s.top();
        s.pop();

        if (!odwiedzony[v]) {
            odwiedzony[v] = true;
            cout << v << " ";

            for (int i = V - 1; i >= 0; --i) 
            {
                if (Matrix[v * V + i] && !odwiedzony[i]) s.push(i);
                
            }
        }
    }
    cout << endl;
}

void graf_macierz::BFS(int start) //przeszukaj w szerz
{
    vector<bool> odwiedzony(V, false);
    queue<int> q;

    odwiedzony[start] = true;
    q.push(start);

    cout << "BFS od wierzcholka " << start << ": ";

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        cout << v << " ";

        for (int i = 0; i < V; ++i) 
        {
            if (Matrix[v * V + i] && !odwiedzony[i])
            {
                odwiedzony[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

void graf_macierz::LosowyGraf(int gestosc, int minValue, int maxValue) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, V - 1);
    uniform_int_distribution<> waga_losowa(minValue, maxValue);

    int max_krawedzi = V * V; 
    int liczba_krawedzi = (gestosc * max_krawedzi/100);

    set<pair<int, int>> istniejace;

    while ((int)istniejace.size() < liczba_krawedzi) {
        int u = dis(gen);
        int v = dis(gen);

        if (istniejace.find({ u, v }) == istniejace.end()) {
            int value = waga_losowa(gen);
            dodajKrawedz(u, v, value);
            istniejace.insert({ u, v });
        }
    }
}

