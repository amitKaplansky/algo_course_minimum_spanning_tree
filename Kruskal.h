#pragma once
#include "Graph.h"
#include "DisjointSets.h"


class Kruskal {

private:
    vector<Edge> F;
    DisjointSets UF;
    //vector<Edge> L;
    vector<Edge> L;
public:
    Kruskal(int n, int m) :UF(n) {
        L.resize(m);
        F.resize(0);//Make empty set.
    }
    int kruskalSpanningTree(Graph& graph, const bool& isFirst, bool& edgeInTree);

private:
    bool isEdgeInF(const int& v, const int& u );
    void sort( Graph& graph);
    static int compare(const void* a, const void* b);
    void copyEdges(Graph& graph);
    void removeEdge(const int& u, const int& v);
    void setMarks();

};