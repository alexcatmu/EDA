#include<iostream>
#include<vector>
using namespace std;

void print_array(vector<vector<int> > g){
    for (int i = 0; i < g.size(); i++) {
        cout << i << ": ";
        for (int j = 0; j < g[i].size(); j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}

void print_bools(vector<vector<bool> > M){
	for(int i = 0; i < M.size(); i++){
		for(int j = 0; j < M[i].size(); j++){
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
}

void findCycle(const vector<vector<int> >& g, vector<bool>& vis, int i, int parent, bool& b){
	if(vis[i] == false){
		vis[i] = true;
		for(int j = 0; j < g[i].size(); j++){
			if(g[i][j] != parent){
				findCycle(g, vis, g[i][j], i, b);
				if(b) return;
			}
		}
	} else {
		b = true;
	}
}

bool haveCicle(const vector<vector<int> >& g){
	vector<bool> vis(g.size(), false);
	for(int i = 0; i < g.size(); i++){
		if(vis[i] == false){
			bool b = false;
			findCycle(g, vis, i, i, b);
			if(b){
				return true;
			}
		}
	}
	return false;
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
		//print_array(graph);
		if(haveCicle(graph)) cout << "no" << endl;
		else cout << (vertices - edges) << endl;
	}
}

