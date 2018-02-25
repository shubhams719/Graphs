#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	void DFSutil(int v,bool* visited);
	public:
	void addedge(int u,int v);
	Graph(int V);
	void BFS(int V);
	void DFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addedge(int u,int v)
{
	adj[u].push_back(v);
}

void Graph::DFSutil(int v,bool* visited)
{
	cout << v << " ";
	visited[v] = true;
	list<int>::iterator it;
	for(it = adj[v].begin();it != adj[v].end();it++)
	{
		if(!visited[*it])
		{
			DFSutil(*it,visited);
		}
	}
}
		

void Graph::DFS(int s)
{
	bool *visited = new bool[V];
	int i;
	for(i=0;i<V;i++)
		visited[i] = false;
	DFSutil(0,visited);
}

void Graph::BFS(int s)
{
	int i;
	bool *visited = new bool[V];
	for(i=0;i<V;i++)
		visited[i] = false;
	list<int> q;
	list<int>:: iterator it;
	visited[0] = true;
	q.push_back(0);
	while(!q.empty())
	{
		s = q.front();
		cout << s << " ";
		q.pop_front();
	for(it = adj[s].begin();it != adj[s].end();it++)
	{
		if(!visited[*it])
		{
			visited[*it] = true;
			q.push_back(*it);
		}
	}
	}
}
int main()
{
	Graph g(5);
	g.addedge(0,1);
	g.addedge(0,4);
	g.addedge(1,2);
	g.addedge(2,1);
	g.addedge(1,3);
	g.DFS(0);
}
