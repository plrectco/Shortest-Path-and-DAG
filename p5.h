#ifndef __P5__H__
#define __P5__H__ 

#include <iostream>
class Edge
{
public:
	int vertex;
	unsigned weight;
	Edge* next;
	Edge(int v, unsigned w)
	{
		next = NULL;
		weight = w;
		vertex = v;
	}
};
class Node
{
public:
	int index;
	Edge* firstEdge;
	unsigned dist;
	Node* pred;
	int indegree;

	Node(int i)
	{
		indegree = 0;
		pred = NULL;
		dist = -1; // distance is maximum
		index = i;
		firstEdge = NULL;
	}
	Edge* addEdge(int v, unsigned w, Node& endNode)
	{
		Edge* e = new Edge(v,w);
		e->next = firstEdge;
		firstEdge = e;
		endNode.indegree += 1;

		return e;
	}


	~Node()
	{
		Edge* temp = firstEdge;
		while(temp!=NULL)
		{
			Edge* todelete = temp;
			temp = temp->next;
			delete todelete;
		}
		firstEdge = NULL;
	}

};
#endif