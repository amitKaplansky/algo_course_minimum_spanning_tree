#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <istream>
#include <vector>
#include "string.h"

using namespace std;

struct Pair {
    int vertex;
    int weight;
};
class Heap {

private:
    Pair* data;
    int maxSize; // max Size of heap
    int heapSize; // curr size of heap
    int allocated = 0;
    vector<int> vertexIndInHeep;
    static int Left(const int& node);
    static int Right(const int& node);
    static int parent( const int& node);
    void fixHeap(const int& node);
    void mySwap(int& a, int& b);

public:
    ~Heap() {
        if (allocated)
            delete[] data;

        data = nullptr;
    }
    Pair deleteMin();
    void decreaseKey(const int& node,const int& newWeight);
    void buildHeap(const int& n, vector<Pair> weight);
    bool isEmpty() const { return heapSize; }

};