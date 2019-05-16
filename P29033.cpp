#include<iostream>
#include<vector>
#include<stack>
#include<list>
using namespace std;


void print(vector<vector<int> > g){
	for(int i = 0; i < g.size(); i++){
		cout << i << ": ";
		for(int j = 0; j < g[i].size(); j++){
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
}

bool dfs_bipartito(vector<vector<int> > g){//g = graph, u=arista, v=vertice, S = auxiliar para hacer el recorrido
	int n = g.size();
	stack<int> S;
	vector<bool> vis(n,false);
	vector<int> colors(n,-1);
	for(int u = 0; u < n; u++){
		S.push(u);
		colors[u] = 1;
		while(not S.empty()){
			int v = S.top();
			S.pop();
			if(not vis[v]){
				vis[v] = true;
				for(int w : g[v]){
					if(colors[w] == -1) colors[w] = 1-colors[v];
					else if(colors[w] == colors[v]) return false;
					//cout << "v: " << v << " w: " << w << " colors[v]: " << colors[v] << endl;
					S.push(w);
				}
			}
		}
	}
	return true;
}

int main(){
	int vertices, edges;
	while(cin >> vertices >> edges){
		vector<vector<int> > graph(vertices, vector<int>());
		for(int i = 0; i < edges; i++){
			int inicio, final;
			cin >> inicio >> final;
			graph[inicio].push_back(final);
			graph[final].push_back(inicio);
		}
		print(graph);

		if(dfs_bipartito(graph)) cout << "yes";
		else cout << "no";
		cout << endl;
	}
}

