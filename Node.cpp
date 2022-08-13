#include "Node.h"

void Node:: updateDup(Node* dup){
    this->dup = dup;
}


bool Node:: isEdge(const int& v){

    return (data.to == v);

}

