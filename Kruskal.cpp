#include "Kruskal.h"

int Kruskal::kruskalSpanningTree(Graph &graph, const bool& isFirst, bool& edgeInTree) {
    int v, u,res=0;

    if(isFirst)
        sort(graph);
    else
    {
        F.resize(0);//Make empty set
        UF.newSet(graph.getN());
    }

    for (int i = 0; i < graph.getN(); i++)
        UF.MakeSet(i);


    setMarks();

    // remove edge after running kruskal the first time
    if(edgeInTree){
        Edge toRemove = graph.getEdgeToRemove();
        removeEdge(toRemove.from, toRemove.to);
    }
    // main loop
    for (Edge edge : L) {

            u = UF.Find(edge.from-1);
            v = UF.Find(edge.to -1);

            if (u != v) {
                F.push_back(edge);
                UF.Union(u, v);
                res += edge.weight;
            }
    }

    //check if edge to remove is in F
    if(isFirst) {
        Edge remove = graph.getEdgeToRemove();
        if (isEdgeInF(remove.from, remove.to))
            edgeInTree = true;
        else
            edgeInTree = false;
    }
    return res;
}

int Kruskal::compare(const void* a, const void* b)
{
    const int x = ((Edge*)a)->weight;
    const int y = ((Edge*)b)->weight;

    if (x > y)
        return 1;
    else if (x < y)
        return -1;

    return 0;
}

void Kruskal::sort(Graph& graph) {

    copyEdges(graph);

    qsort(&L[0], L.size(), sizeof(Edge), compare);

}

bool Kruskal:: isEdgeInF(const int& v, const int& u )
{
    for(Edge edge: L)
    {
        if(edge.from == v && edge.to == u || edge.to == v && edge.from == u)
            return true;
    }

    return false;
}

void Kruskal::copyEdges( Graph& graph) {

    L = graph.getEdges();

}
void Kruskal::removeEdge(const int& u, const int& v){
    int i;
    Node * dup;
    for(i = 0 ; i < L.size(); i++){
        if(L[i].from == u && L[i].to == v || L[i].from == v && L[i].to == u)
            break;
    }
    L.erase(L.begin() + i);
}
void Kruskal:: setMarks(){
    for(Edge edge: L){
        edge.mark = false;
    }
}

