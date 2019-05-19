#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int minDistance = -1;

int dijkstra(vector<vector<pair<int, int> > >& g, int inicio, int destino){
	int n = g.size();
	vector<int> distances(n,minDistance);
	distances[inicio] = 0;
	vector<bool> mark(n,false);
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
	q.push(make_pair(0,inicio));
	

	while(!q.empty()){
		int vertice_actual = q.top().second;
		q.pop();
		if(!mark[vertice_actual]){
			mark[vertice_actual] = true;
			for(pair<int, int> adyacente : g[vertice_actual]){
				int cost = adyacente.first;
				int verticeAdyacente = adyacente.second;
				
				//cout << "vertice Actual: " << actual.first << endl;
				//cout << "vertice Adyacente: " << verticeAdyacente << endl;
				//cout << distances[adyacente.second] << " " << distances[actual.first] << endl; 
				//cout << endl << endl;

				if((distances[verticeAdyacente] > distances[vertice_actual] + cost) || distances[verticeAdyacente] == minDistance) {
					distances[verticeAdyacente] = distances[vertice_actual] + cost;
					q.push(make_pair(distances[verticeAdyacente], verticeAdyacente));
				}
			}
		}
	}
	//for(int i = 0;  i< distances.size(); i++) cout << i << "->" << distances[i] << "     ";
	//cout << endl; 
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
			g[inicio].push_back(make_pair(peso, destino));
		}
		cin >> inicio >> destino;
		//print_g(g);
		int distancia = dijkstra(g, inicio, destino);
		if(distancia == -1) cout << "no path from " << inicio << " to " << destino << endl;
		else cout << distancia << endl;
		
	}
}
