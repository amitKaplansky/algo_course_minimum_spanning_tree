#pragma once
#include "LinkedList.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <istream>
#include <vector>
#include "string.h"
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

class Graph {
    vector<int> toRemove;
    vector<LinkedList> mtrx;
    int n;
    int m;

    void visit(const int& u);

public:
    enum class color { WHITE = 0, GRAY, BLACK };

    ~Graph() {
        if (!mtrx.empty()) {
            for (auto & i : mtrx)
                i.makeEmpty();

            mtrx.clear();
        }
    }
    void makeEmptyGraph(const int& n) { mtrx.resize(n); }
    bool isAdjacent (const int& u,const int& v) ;
    LinkedList getAdjList(int u) const { return mtrx[u-1]; }
    bool addEdge(const int& u, const int& v,const int& weight);
    void removeEdge(const int& u,const int& v);
    void readFromFile(const string& name);
    bool checkEdge(const int& u, const int& v);
    vector<Edge> getEdges();
    bool checkIsNumber(string str, const bool& isWeight);
    int getN() const { return n; }
    int getM() const { return m; }
    bool isLinked();
    Edge getEdgeToRemove();

private:
    vector<color> colors;



};