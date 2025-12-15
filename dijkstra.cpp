#include<bits/stdc++.h>
using namespace std;

class Edge{
	public:
		int v;
		int wt;
		
		Edge(int v, int wt){
			this->v = v;
			this->wt = wt;
		}
};

void dijkstra(int src, vector<vector<Edge>> g, int V){
	vector<int> dist(V, INT_MAX);
	dist[src] = 0;
	
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>> >pq;
	pq.push({0, src}); //dist[u], u
	
	while(!pq.empty()){
		auto top = pq.top();
		pq.pop();
		
		int d = top.first;
		int u = top.second;
		
		//go through all the neighbours of vertex u
		for(Edge e : g[u]){
			int v = e.v;
			int wt = e.wt;
			
			if(dist[v] > dist[u] + wt){
				dist[v] = dist[u] + wt;
				pq.push({dist[v],v});
			}
		}
		
	}
	
	for(int i=0;i<V;i++){
		cout<<"Distance from 0 to "<<i<<" = "<<dist[i]<<endl;
		
	}
	
}

int main(){
	int V = 6;
	vector<vector<Edge>> g(V);
	
	g[0].push_back(Edge(1,2));
	g[0].push_back(Edge(2,4));
	
	g[1].push_back(Edge(2,1));
	g[1].push_back(Edge(3,7));
	
	g[2].push_back(Edge(4,3));
	
	g[3].push_back(Edge(5,1));
	
	g[4].push_back(Edge(3,2));
	g[4].push_back(Edge(5,5));
	
	dijkstra(0, g,V);
	return 0;
}
