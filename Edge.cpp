/* Edge class implementation*/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "Edge.h"

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
int Edge::compareTo(Edge* another){
	return (this->weight - another->weight);
}