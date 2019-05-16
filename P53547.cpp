#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void bfs(M){
	int n = M.size();
	
	stack<string>
}

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int rows,columns;
		cin >> rows >> columns;
		vector<vector<string> > M(columns, vector<int>(rows));
		for(int j = 0; j < rows; j++){
			for(int k = 0; k < columns; k++){
				string cell;
				cin >> cell;
				M[j][k] = cell;
			}
		}
		bfs(M);
	}
}

