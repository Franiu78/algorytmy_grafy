#include "grafy_lista.h"
#include <iostream>
#include <stack>
#include <queue>
#include <climits> // int_max
#include <random> // do generowania losowych
#include <set> // do generowania losowych

using namespace std;

graf_lista::graf_lista(int wierzcholki) : V(wierzcholki), lista(wierzcholki, nullptr) {}

graf_lista::~graf_lista() 
{
    for (int i = 0; i < V; ++i)
    {
        AdjNode* aktualny = lista[i];
        while (aktualny != nullptr) 
        {
            AdjNode* temp = aktualny;
            aktualny = aktualny->next;
            delete temp;
        }
    }
}

void graf_lista::dodajKrawedz(int u, int v, int value = 1)
{
    AdjNode* node = new AdjNode(v, value);
    node->next = lista[u];
    lista[u] = node; // dodajemy na pocz�tek listy
}

void graf_lista::wypisz()
{
    cout << "Lista sasiadow:\n";
    for (int u = 0; u < V; ++u) {
        cout << u << ": ";
        for (AdjNode* sasiad = lista[u]; sasiad != nullptr; sasiad = sasiad->next) {
            cout << "(" << sasiad->v << ", waga: " << sasiad->value << ") ";
        }
        cout << endl;
    }
}



void graf_lista::DFS(int start) //przeszukaj w glab
{
        vector<bool> odwiedzony(V, false);
        stack<int> s;

        s.push(start);

        cout << "DFS od wierzcholka " << start << ": ";

        while (!s.empty()) 
        {
            int v = s.top();
            s.pop();

            if (!odwiedzony[v]) 
            {
                odwiedzony[v] = true;
                cout << v << " ";

                for (AdjNode* sasiad = lista[v]; sasiad != nullptr; sasiad = sasiad->next)
                {
                    if (!odwiedzony[sasiad->v]) s.push(sasiad->v);
                    
                }
            }
        }
        cout << endl;
    }

void graf_lista::BFS(int start) //przeszukaj w szerz
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

            for (AdjNode* sasiad = lista[v]; sasiad != nullptr; sasiad = sasiad->next) 
            {
                if (!odwiedzony[sasiad->v]) 
                {
                    odwiedzony[sasiad->v] = true;
                    q.push(sasiad->v);
                }
            }
        }
        cout << endl;
    }




void graf_lista::LosowyGraf(int gestosc, int minValue, int maxValue) 
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

void graf_lista::Dijkstra(int start) 
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

        for (AdjNode* sasiad = lista[u]; sasiad != nullptr; sasiad = sasiad->next) 
        {
            int v = sasiad->v;
            int w = sasiad->value;

            if (dystans[v] > dystans[u] + w) dystans[v] = dystans[u] + w;
            
        }
    }

    // wypisz wynik
    cout << "Najkrótsze odległości od " << start << ":\n";
    for (int i = 0; i < V; ++i) 
    {
        if (dystans[i] == INT_MAX)
            cout << i << ": brak drogi\n";
        else
            cout << i << ": " << dystans[i] << "\n";
    }
}


bool graf_lista::BellmanFord(int start)
 {
    vector<int> dystans(V, INT_MAX);
    dystans[start] = 0;

    // relaksacja (V-1 razy)
    for (int i = 0; i < V - 1; ++i) 
    {
        for (int u = 0; u < V; ++u) 
        {
            for (AdjNode* sasiad = lista[u]; sasiad != nullptr; sasiad = sasiad->next)
            {
                int v = sasiad->v;
                int w = sasiad->value;

                if (dystans[u] != INT_MAX && dystans[v] > dystans[u] + w) dystans[v] = dystans[u] + w;
                
            }
        }
    }

    // wykrywanie cyklu ujemnego
    for (int u = 0; u < V; ++u)
    {
        for (AdjNode* sasiad = lista[u]; sasiad != nullptr; sasiad = sasiad->next) 
        {
            int v = sasiad->v;
            int w = sasiad->value;

            if (dystans[u] != INT_MAX && dystans[v] > dystans[u] + w) 
            {
                cout << "Wykryto cykl o ujemnej wadze!\n";
                return false;
            }
        }
    }

    // Wypisz wynik
    cout << "Najkrótsze odległości od wierzchołka " << start << ":\n";
    for (int i = 0; i < V; ++i) 
    {
        if (dystans[i] == INT_MAX)
            cout << i << ": brak drogi\n";
        else
            cout << i << ": " << dystans[i] << "\n";
    }

    return true;
}
