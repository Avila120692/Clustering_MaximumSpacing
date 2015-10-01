/* Edge class implementation*/
#include "Edge.h"

using namespace std;

// Constructor
Edge::Edge(int src, int dest, int weight) {

	this->src = src;
	this->dest = dest;
	this->weight = weight;
}

// Print edge info
void Edge::toString() {
	printf("\n Ende : %i - $i Weight : ", src, dest, weight);
}

// Compares two edges
int Edge::compareTo(Edge another){
	return (this->weight - another.weight);
}

// Destructor
Edge::~Edge(){}