#include "LinkedList.h"


bool LinkedList::isEmpty()
{
    return (head == nullptr);
}

void LinkedList::makeEmpty()
{
    Node* temp;

    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int LinkedList:: len() {

    Node* temp = head;
    int res = 0;

    while(temp != nullptr) {
        temp = temp->next;
        ++res;
    }

    return res;
}



Node* LinkedList:: insertNodeToLast(const Edge& newEdge, Node* next, Node* dup)
{
    //Create a new node
    Node* newNode = new Node(newEdge, next, dup);

    //insert to start
    if (isEmpty())
        return head = newNode;

    Node *temp = head;
    while (temp->next != nullptr) {

            // Update temp
            temp = temp->next;
    }

        // Insert at the last.
    return temp->next = newNode;
}

Node* LinkedList:: removeEdge(const int& v) // edge exists
{
    Node* temp = head;
    Node* before = head;
    Node* res;
    int count = 1;

    while(!temp->isEdge(v))
    {
        before = temp;
        temp = temp->next;
        count++;
    }

    if(count == 1){
        head = head->next;
        res = temp->dup;
        delete temp;
    }
    else{
        res = temp->dup;
        before->next = temp->next;
        delete temp;

    }

    return res;
}
void LinkedList:: removeNode( Node* toDelete)
{
    Node* temp = head;

    if(toDelete == head){
        if(len() == 1)
            delete head;
        else
        {
            head = temp->next;
            delete temp;
        }
    }
    else{

        while(temp->next != toDelete){
            temp = temp->next;
        }

        temp->next = toDelete->next;
        delete toDelete;
    }
}


bool LinkedList:: isEdgeInList(const int& v) {

    Node *temp = head;

    while (temp != nullptr) {
        if (temp->isEdge(v))
            return true;
        temp = temp->next;
    }

    return false;

}

void LinkedList:: markFalse()
{
    Node* temp = head;

    while( temp != nullptr)
    {
        temp->data.mark = false;
        temp->dup->data.mark = false;
        temp = temp->next;
    }
}

vector<Edge> LinkedList:: returnAllEdges()
{
    Node* temp = head;
    vector<Edge> res;

    while( temp != nullptr)
    {
        if(!temp->isMarked()){
            temp->dup->data.mark = true;
            res.push_back(temp->data);
        }
        temp = temp->next;
    }
    return res;
}