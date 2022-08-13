#pragma once
#include "Node.h"

class LinkedList {

public:

    bool isEmpty();
    void makeEmpty();
    Node* insertNodeToLast(const Edge& newEdge, Node* next, Node* dup);
    int len();
    Node* removeEdge(const int& v);
    bool isEdgeInList(const int& v);

    void markFalse();
   // vector<struct Edge> returnAllEdges();
    vector<Edge> returnAllEdges();
    void removeNode(Node* ToDelete);


    class iterator{
        Node* node;
        friend class LinkedList;

    public:
        iterator(Node* p = nullptr) : node(p) {}
        //pre fix
        iterator operator++() {
            node = node->next;
            return *this;
        }
        /*Edge operator*() {
            return node->getEdge();
        }*/

        Node* operator*() {
            return node;
        }
        int operator!=(iterator iter) const{
            return node != iter.node;
        }

        };

        // begin() and end()
        iterator begin() {return head;}
        iterator end() {
            Node* temp = head;
            while(temp != nullptr){
                temp = temp->next;
            }
            return temp;
        }
private:

    Node* head = nullptr;
};