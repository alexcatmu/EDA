#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

void print_g(vector<vector<int> >& g){
	for(int i = 0; i < g.size(); i++){
		cout << i << ": ";
		for(int j = 0; j < g[i].size(); j++){
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
}

void print_v(vector<int>& v){
	for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;
}

list<int> topo(vector<int>& vertices, vector<vector<int> > g){
	priority_queue<int, vector<int>, greater<int> > q;
	for(int i = 0; i < vertices.size(); i++) if(vertices[i] == 0) q.push(i);
	list<int> l;
	while(!q.empty()){
		int vert = q.top();
		q.pop();
		l.push_back(vert);
		for(int adyacente = 0; adyacente < g[vert].size(); adyacente++){
			vertices[g[vert][adyacente]]--;
			if(vertices[g[vert][adyacente]] == 0) q.push(g[vert][adyacente]);
		}
	}
	return l;
}

void print_l(list<int> l){
	string c = "";
	for(int value : l){
		cout << c << value;
		c = " ";
	} 
	cout << endl;
}

int main(){
	int n, m;
	while(cin >> n >> m){
		vector<vector<int> > Tasks(n, vector<int>());
		vector<int> vertices(n, 0);
		
		for(int i = 0; i < m; i++){
			int x, y;
			cin >> x >> y;
			vertices[y]++;
			Tasks[x].push_back(y);
		}
		//print_g(Tasks);
		//print_v(vertices);
		
		list<int> l = topo(vertices, Tasks);
		print_l(l);
	}
}

