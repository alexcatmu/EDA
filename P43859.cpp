#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int minDistance = 1;

int dijkstra(vector<vector<pair<int, int> > >& g, int inicio, int destino){
	vector<bool> mark(g.size(), false);
	vector<int> distances(g.size(), minDistance);
	distances[inicio] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int,int> > > q;
	q.push(make_pair(inicio,0));
	
	while(!q.empty()){
		pair<int, int> actual = q.top();
		q.pop();
		if(!mark[actual.first]){
			mark[actual.first] = true;
			for(pair<int, int> adyacente : g[actual.first]){
				int cost = adyacente.second;
				int verticeAdyacente = adyacente.first;
				if(distances[adyacente.second] > distances[actual.first] + cost) {
					distances[adyacente.second] = distances[actual.first] + cost;
					q.push(make_pair(verticeAdyacente, distances[verticeAdyacente]));
				}
			}
		}
	}
	for(int i = 0;  i< distances.size(); i++) cout << i << "->" << distances[i] << "     ";
	cout << endl; 
	return distances[destino];
}

void print_g(vector<vector<pair<int, int > > >& g){
	for(int i = 0; i < g.size(); i++){
		cout << i << ": ";
		for(int j = 0; j <g[i].size(); j++){
			cout << g[i][j].first << "(" << g[i][j].second << ") "; 
		}
		cout << endl;
	}
}

int main(){
	int vertices, arcos;
	while(cin >> vertices >> arcos){
		vector<vector<pair<int, int > > > g(vertices, vector<pair<int, int> >());
		int inicio, destino, peso;
		for(int i = 0; i < arcos; i++){
			cin >> inicio >> destino >> peso;
			g[inicio].push_back(make_pair(destino, peso));
		}
		cin >> inicio >> destino;
		print_g(g);
		int distancia = dijkstra(g, inicio, destino);
		if(distancia == -1) cout << "no path from " << inicio << " to " << destino << endl;
		else cout << distancia << endl;
		
	}
}

