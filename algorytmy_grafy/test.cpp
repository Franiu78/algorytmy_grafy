#include "test.h"
#include "grafy_lista.h"
#include "grafy_macierz.h"
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

void TestLista(int V, double gestosc, int proby) {
    ofstream fout("wyniki.csv", ios::app);

    fout << endl << endl << "Lista;V=" << V << ";gestosc=" << gestosc << endl;
    fout << "nr;BFS;DFS;Dijkstra;BellmanFord" << endl;

    for (int i = 0; i < proby; ++i) {
        graf_lista g(V);
        g.LosowyGraf(gestosc);

        fout << i + 1 << ";";

        // BFS
        auto start = high_resolution_clock::now();
        g.BFS(0);
        auto end = high_resolution_clock::now();
        fout << duration_cast<nanoseconds>(end - start).count() << ";";

        // DFS
        start = high_resolution_clock::now();
        g.DFS(0);
        end = high_resolution_clock::now();
        fout << duration_cast<nanoseconds>(end - start).count() << ";";

        // Dijkstra
        start = high_resolution_clock::now();
        g.Dijkstra(0);
        end = high_resolution_clock::now();
        fout << duration_cast<nanoseconds>(end - start).count() << ";";

        // Bellman-Ford
        start = high_resolution_clock::now();
        g.BellmanFord(0);
        end = high_resolution_clock::now();
        fout << duration_cast<nanoseconds>(end - start).count() << ";" << endl;
    }

    fout << endl;
    fout.close();
}


void TestMacierz(int V, double gestosc, int proby) {
    ofstream fout("wyniki.csv", ios::app);

    fout << endl << endl << "Macierz;V=" << V << ";gestosc=" << gestosc << endl;
    fout << "nr;BFS;DFS;Dijkstra;BellmanFord" << endl;

    for (int i = 0; i < proby; ++i) {
        graf_macierz g(V);
        g.LosowyGraf(gestosc);

        fout << i + 1 << ";";

        // BFS
        auto start = high_resolution_clock::now();
        g.BFS(0);
        auto end = high_resolution_clock::now();
        fout << duration_cast<nanoseconds>(end - start).count() << ";";

        // DFS
        start = high_resolution_clock::now();
        g.DFS(0);
        end = high_resolution_clock::now();
        fout << duration_cast<nanoseconds>(end - start).count() << ";";

        // Dijkstra
        start = high_resolution_clock::now();
        g.Dijkstra(0);
        end = high_resolution_clock::now();
        fout << duration_cast<nanoseconds>(end - start).count() << ";";

        // Bellman-Ford
        start = high_resolution_clock::now();
        g.BellmanFord(0);
        end = high_resolution_clock::now();
        fout << duration_cast<nanoseconds>(end - start).count() << ";" << endl;
    }

    fout << endl;
    fout.close();
}
