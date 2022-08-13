#pragma once
#include "Graph.h"
#include "Heap.h"

class Prim {
private:
    vector<bool> inT;
    Heap heap;
    vector<Pair> p;

public:
    Prim(int n)  {
        inT.resize(n);
        p.resize(n);

        for(int i=0;i<n;i++)
            inT[i] =  false ;

    }

    int PrimSpanningTree(Graph& graph);
};