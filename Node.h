#pragma once
#include <iostream>
#include <string>
#include <istream>
#include <vector>

using namespace std;

struct Edge
{
    bool mark = false;
    int from;
    int to;
    int weight;
};

class Node {

    Edge data;
    struct Node* next = nullptr;
    struct Node* dup = nullptr;

public:

    Node(const Edge& newEdge, Node* next, Node* dup): data(newEdge) {
        this->next = next;
        this->dup = dup;
    }
    void updateDup(Node* dup);
    bool isEdge(const int& v);
    int getWeight() const{ return data.weight;}
    int getFrom() const{ return data.from;}
    int getTo() const{ return data.to;}
    void updateMark(const bool& newMark){ data.mark = newMark;}
    Edge getEdge() const {return data;}
    bool isMarked() const {return data.mark;}
    void updateDupMark(const bool& newMark) { dup->data.mark = newMark;}
    Node* getDup (){return dup;}

    friend class LinkedList;

};