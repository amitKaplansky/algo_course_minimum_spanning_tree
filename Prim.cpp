#include "Prim.h"


int Prim::PrimSpanningTree(Graph& graph) {// check if there is a problem with the edges - double edges u -> v and v -> u
    int res = 0;
    p[0].vertex = -1;
    p[0].weight = 0;
    LinkedList lst;

    for (int i = 1; i < graph.getN(); i++) {

        p[i].vertex = -1;
        p[i].weight = std::numeric_limits<int>::max();
    }

    heap.buildHeap(graph.getN(), p);
    Pair u;

    while (heap.isEmpty()) {
        u = heap.deleteMin();
        inT[u.vertex - 1] = true;

        lst = graph.getAdjList(u.vertex);

        for (Node *edge: lst) {
            if (!inT[edge->getTo() - 1] && edge->getWeight() < p[edge->getTo() - 1].weight) {
                p[edge->getTo() - 1].weight = edge->getWeight();
                p[edge->getTo() - 1].vertex = edge->getFrom() - 1;
                heap.decreaseKey(edge->getTo(), p[edge->getTo() - 1].weight);
            }
        }
    }

    for (Pair i: p) {
        res += i.weight;
    }

    return res;

}


