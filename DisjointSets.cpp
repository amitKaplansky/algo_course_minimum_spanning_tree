#include "DisjointSets.h"

void DisjointSets::MakeSet(const int& x) {

    a[x].parent = x;
    a[x].size = 1;
}

int DisjointSets::Find(const int& x) { // with path comparison
    // problem with find?

    if (a[x].parent == x)
        return x;
    else
        return (a[x].parent = Find(a[x].parent));
}
void DisjointSets::Union(const int& repx, const int& repy) { // Assuming repx, repy are the representatives + with union by size

    if (a[repx].size > a[repy].size)
    {
        a[repy].parent = repx;
        a[repx].size += a[repy].size;
    }
    else
    {
        a[repx].parent = repy;
        a[repy].size += a[repx].size;
    }
}

void DisjointSets:: newSet(const int&  size){
    a.resize(size);

    for (int i = 0; i < size; i++) {
        a[i].parent = -1;
        a[i].size = 0;
    }
}