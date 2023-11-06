#include "Graph.h"
//uncomment this to include your own "heap.h"
//we will assume that you use the same code in your previous assignment
#include "heap.h"

std::ostream& operator<<(std::ostream& os, nodeWeightPair const& n) {
	return os << " (idx:" << n._node << " w:" << n._weight << ")";
}


Graph::Graph(int n)
{
	_al = new List<nodeWeightPair> [n];
	_nv = n;
}

int Graph::shortestDistance(int s, int d)
{	
	if (s > _nv || d > _nv) throw out_of_range("s or d not in Graph!"); 

	if (_al[s].size() == 0) return -1;

	Heap<nodeWeightPair> nwpHeap;
	bool* visited = new bool[_nv];
	for (int i = 0; i < _nv; i++) {
		visited[i] = false;
	}

	int res = 0;
	
	_al[s].start();
	while (!_al[s].end()) {
		nodeWeightPair curr = _al[s].current();
		res += curr.weight();
		if (_al[s].current().nodeIndex() == d) return res;
		_al[s].next();
	}

	return -1;
}
void Graph::addEdge(int s, int d, int w)  //from, to, weight
{
	_al[s].insertHead(nodeWeightPair(d, w));
}

void Graph::printGraph()
{
	for (int i=0; i < _nv; i++)
	{
		cout << "Node " << i << ": ";
		for (_al[i].start(); !_al[i].end(); _al[i].next())
			cout << " (" << _al[i].current().nodeIndex() << "," << _al[i].current().weight() << ")";
		cout << endl;

	}

}
Graph::~Graph()
{

	delete[] _al;

}