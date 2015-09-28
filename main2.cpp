using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Edge.h"
#include "KCluster.h"

Edge* generateEdges(){

	Edge* edges[13];

	edges[0] = new Edge(1, 2, 4);
	edges[1] = new Edge(2, 3, 8);
	edges[2] = new Edge(3, 4, 7);
	edges[3] = new Edge(4, 5, 9);
	edges[4] = new Edge(5, 6, 10);
	edges[5] = new Edge(6, 3, 4);
	edges[6] = new Edge(6, 7, 2);
	edges[7] = new Edge(7, 8, 1);
	edges[8] = new Edge(8, 1, 8);
	edges[9] = new Edge(8, 2, 11);
	edges[10] = new Edge(8, 0, 7);
	edges[11] = new Edge(0, 3, 2);
	edges[12] = new Edge(0, 7, 6);

	return *edges;
}

int main2(void)
{
	/*
	Edge* edges = generateEdges();

	KCluster graph(9, 13);
	int k = 4;
	graph.addEdges(edges);
	graph.print();

	graph.maxClusterDistance = graph.getMaxSpacing(k);

	if (graph.maxClusterDistance != -1)
	printf("\nMaximum Cluster Spacing for %i clusters is %i", k, graph.maxClusterDistance);
	else
	printf("\n %s", "Something went Wrong
	*/

	system("pause");
	return 0;
}