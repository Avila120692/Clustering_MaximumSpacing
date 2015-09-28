/*UFNode class implementation*/
using namespace std;

#include "UFNode.h"

UFNode::UFNode(int parent, int rank){

	this->parent = parent;
	this->rank = rank;
}

// Destructor
UFNode::~UFNode(){}