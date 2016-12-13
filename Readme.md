# Implementation
1. Ajancency list is used. Every node is associated with a linked list of Edge.
2. Use `indegree` rather than delete the edge to do the topological sort, it works becasue we won't revisit any node if they have already been visited. All the indegree keeps decreasing. We maintain a queue where all the nodes in the queue has indegree of 0. Every visit of the indegree 0 node we pop it out. Finally, if the number of indegree 0 nodes is less than the total number, then there must be a cycle.

# Attention
1. Don't forget `e = e->next;` at the end of while
2.

	if(startNode.dist==-1)
	continue;

This command is also important when doing the BellmanFord. Overflow occurs when we add things to -1.


