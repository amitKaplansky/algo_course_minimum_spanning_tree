#include "Heap.h"

void Heap::buildHeap(const int& n, vector<Pair> weight) {
    heapSize = maxSize = n;
    data = new Pair[n];
    vertexIndInHeep.resize(n);
    allocated = 1;

    for (int i = 0; i < n; i++) {//enter the min[v] to data
        data[i].weight = weight[i].weight;
        data[i].vertex = i + 1;
        vertexIndInHeep[i] = i;
    }
    for (int i = n / 2 - 1; i >= 0; i--)
            fixHeap(i);

}

int Heap::parent(const int& node) {
    return (node - 1) / 2;
}
int Heap::Left(const int& node) {
    return (2 * node + 1);
}
int Heap::Right(const int& node) {
    return (2 * node + 2);
}

void Heap::fixHeap(const int& node) {
    int min, left, right;
    left = Left(node);
    right = Right(node);

    // Find minimum among node, left and right.
    if ((left < heapSize) && ((data[left].weight < data[node].weight)))
        min = left;

    else
        min = node;

    if ((right < heapSize) && (data[right].weight < data[min].weight))
        min = right;

    if (min != node) {

        swap(data[node], data[min]);
        mySwap(vertexIndInHeep[data[node].vertex -1], vertexIndInHeep[data[min].vertex -1]);
        fixHeap(min);
    }
}

Pair Heap::deleteMin() {
    if (heapSize < 1) {
        cout << "The heap is empty";
        exit(1);
    }

    Pair min = data[0];
    heapSize--;
    vertexIndInHeep[data[heapSize].vertex -1] = 0;
    data[0] = data[heapSize];
    fixHeap(0);
    return min;

}

void Heap::decreaseKey(const int& node,const int& newWeight) {

    int i = vertexIndInHeep[node-1];
    data[i].weight = newWeight;

    while ( i != 0 && data[parent(i)].weight > data[i].weight)
    {
        swap(data[i], data[parent(i)]);
        mySwap(vertexIndInHeep[data[i].vertex -1], vertexIndInHeep[data[parent(i)].vertex -1]);
        i = parent(i);
    }

}

void Heap:: mySwap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

