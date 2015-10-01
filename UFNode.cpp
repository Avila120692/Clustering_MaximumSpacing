/*UFNode class implementation*/
#include "UFNode.h"

using namespace std;

UFNode::UFNode(int parent, int rank){

	this->parent = parent;
	this->rank = rank;
}

// Destructor
UFNode::~UFNode(){}