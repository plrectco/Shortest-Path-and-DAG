#include "p5.h"
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int numVertex, src, dst;
	cin>>numVertex>>src>>dst;
	vector<Node> nodeArr;
	for(int i = 0; i < numVertex; i++)
	{
		Node a(i);
		nodeArr.push_back(a);
	}

	int inVertex,outVertex;
	unsigned weight;
	while(cin>>inVertex>>outVertex>>weight)
	{
		nodeArr[inVertex].addEdge(outVertex,weight,nodeArr[outVertex]);
	}
	nodeArr[src].dist = 0;

	for(int j = 0; j < numVertex; j++)
	{
		for(int i = 0; i < numVertex; i++)
		{
			Edge* e = nodeArr[i].firstEdge;
			Node& startNode = nodeArr[i];
			if(startNode.dist==-1)
				continue;
			while(e)
			{
				Node& endNode = nodeArr[e->vertex];
				if(endNode.dist > startNode.dist+e->weight)
				{
					endNode.dist = startNode.dist+e->weight;
					endNode.pred = &startNode;
				}
				e = e->next;
			}
		}
	}
	if(nodeArr[dst].dist!= -1)
	{
		cout<<"Shortest path length is "<<nodeArr[dst].dist<<endl;
		vector<Node*> outputStack;
		Node* n = &nodeArr[dst];
		while(n)
		{
			outputStack.push_back(n);
			n = n->pred;
		}
		cout<<"Shortest path is";
		while(!outputStack.empty())
		{
			cout<<" ";
			cout<<outputStack.back()->index;
			outputStack.pop_back();
		}
		cout<<endl;
	}
	else
		cout<<"No path exists!"<<endl;
	

	int vertexVisited = 0;

	queue<Node*> dagQueue;
	for(int i = 0 ; i<numVertex;i++)
	{
		if(nodeArr[i].indegree == 0)
			dagQueue.push(&nodeArr[i]);
	}


	while(!dagQueue.empty())
	{
		Node* current = dagQueue.front();
		Edge* e = current->firstEdge;
		while(e)
		{
			nodeArr[e->vertex].indegree--;
			if(nodeArr[e->vertex].indegree == 0)
				dagQueue.push(&nodeArr[e->vertex]);
			e = e->next;
		}
		vertexVisited++;
		dagQueue.pop();
	}
	if(numVertex>vertexVisited)
		cout<<"The graph is not a DAG"<<endl;
	else
		cout<<"The graph is a DAG"<<endl;

	return 0;
}