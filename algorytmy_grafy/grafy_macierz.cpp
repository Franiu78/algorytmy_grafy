#include "grafy_macierz.h"
#include <iostream>
#include <stack>
#include <queue>
#include <random>
#include <set>
#include <climits>

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

void graf_macierz::LosowyGraf(int gestosc, int minValue, int maxValue)
 {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, V - 1);
    uniform_int_distribution<> waga_losowa(minValue, maxValue);

    int max_krawedzi = V * V; 
    int liczba_krawedzi = (gestosc * max_krawedzi/100);

    set<pair<int, int>> istniejace;

    while ((int)istniejace.size() < liczba_krawedzi) 
    {
        int u = dis(gen);
        int v = dis(gen);

        if (istniejace.find({ u, v }) == istniejace.end()) 
        {
            int value = waga_losowa(gen);
            dodajKrawedz(u, v, value);
            istniejace.insert({ u, v });
        }
    }
}

void graf_macierz::Dijkstra(int start) 
{
    vector<int> dystans(V, INT_MAX);
    vector<bool> odwiedzony(V, false);

    dystans[start] = 0;

    for (int i = 0; i < V; ++i)
    {
        int u = -1;

        // znajdź nieodwiedzonego z najmniejszym dystansem
        for (int j = 0; j < V; ++j)
        {
            if (!odwiedzony[j] && (u == -1 || dystans[j] < dystans[u])) u = j;
            
        }

        if (dystans[u] == INT_MAX)
            break;

        odwiedzony[u] = true;

        for (int v = 0; v < V; ++v) 
        {
            int value = Matrix[u * V + v];
            if (value > 0 && dystans[v] > dystans[u] + value) dystans[v] = dystans[u] + value;
            
        }
    }

    // wypisanie wyników
    cout << "Najkrótsze odległości od " << start << ":\n";
    for (int i = 0; i < V; ++i) 
    {
        if (dystans[i] == INT_MAX)
            cout << i << ": brak drogi\n";
        else
            cout << i << ": " << dystans[i] << "\n";
    }
}


bool graf_macierz::BellmanFord(int start) 
{
    vector<int> dystans(V, INT_MAX);
    dystans[start] = 0;

    // relaksacja (V-1 razy)
    for (int i = 0; i < V - 1; ++i) 
    {
        for (int u = 0; u < V; ++u) 
        {
            for (int v = 0; v < V; ++v)
            {
                int value = Matrix[u * V + v];
                if (value != 0 && dystans[u] != INT_MAX && dystans[v] > dystans[u] + value)  dystans[v] = dystans[u] + value;
                
            }
        }
    }

    // wykrywanie cyklu ujemnego
    for (int u = 0; u < V; ++u) 
    {
        for (int v = 0; v < V; ++v) 
        {
            int value = Matrix[u * V + v];
            if (value != 0 && dystans[u] != INT_MAX && dystans[v] > dystans[u] + value)
            {
                cout << "Cykl o ujemnej wadze!\n";
                return false;
            }
        }
    }

    // Wypisz wynik
    cout << "Najkrótsze odległości od " << start << ":\n";
    for (int i = 0; i < V; ++i) 
    {
        if (dystans[i] == INT_MAX)
            cout << i << ": brak drogi\n";
        else
            cout << i << ": " << dystans[i] << "\n";
    }

    return true;
}
