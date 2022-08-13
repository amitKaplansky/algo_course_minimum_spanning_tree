#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <istream>
#include <vector>
#include "string.h"
using namespace std;

struct Element
{
    int parent;
    int size;
};

class DisjointSets {

private:
    vector<Element> a;

public:
    DisjointSets(const int& size) {
        newSet(size);
    }
    void MakeSet(const int& x);
    int Find(const int& x);
    void Union(const int& repx, const int& repy);
    void newSet(const int&  size);

};
