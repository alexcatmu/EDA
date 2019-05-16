#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

typedef vector<vector<char> > Board;
typedef pair<int,int> position;

void print_board(Board b){
	for(int i = 0; i < b.size(); i++){
		for(int j = 0; j < b[i].size(); j++){
			cout << b[i][j];
		}
		cout << endl;
	}
}

bool pos_ok(int i, int j, Board& b){
	if(i < 0 or i >= b.size()) return false;
	if(j < 0 or j >= b[0].size()) return false;
	if(b[i][j] == 'X') return false;
	return true;
}

int bfs(Board& board, int i, int j){
	vector<vector<bool> > marks(board.size(), vector<bool>(board[0].size(), false));
	queue<pair<position,int> > q;
	q.push(make_pair(make_pair(i,j), 0));

	while(!q.empty()){
		pair<position,int> current = q.front();
		position currentPos = current.first;
		int currentDistance = current.second;
		q.pop();
		if(not marks[currentPos.first][currentPos.second]){
			marks[currentPos.first][currentPos.second] = true;
			//cout << currentDistance  << endl;
			if(board[currentPos.first][currentPos.second] == 't') {
				return currentDistance;
			}
			if(pos_ok(currentPos.first+1,currentPos.second, board)){//up
				q.push(make_pair(make_pair(currentPos.first+1,currentPos.second), currentDistance+1));
			}
			if(pos_ok(currentPos.first-1,currentPos.second, board)){//down
				q.push(make_pair(make_pair(currentPos.first-1,currentPos.second), currentDistance+1));
			}
			if(pos_ok(currentPos.first,currentPos.second+1, board)){//right
				q.push(make_pair(make_pair(currentPos.first,currentPos.second+1), currentDistance+1));
			}
			if(pos_ok(currentPos.first,currentPos.second-1, board)){//left
				q.push(make_pair(make_pair(currentPos.first,currentPos.second-1), currentDistance+1));
			}
			//cout << "q" << q.size()<< endl;
		}
	}
	return -1;
}

int main(){
	int rows, columns;
	
	while(cin >> rows >> columns){
		Board board(rows, vector<char>(columns));
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < columns; j++){
				char c;
				cin >> c;
				board[i][j] = c;
			}
		}
		//cout << endl << endl;
		//print_board(board);
		
		int initI, initJ;
		cin >> initI >> initJ;
		int dist = bfs(board, initI-1, initJ-1);
		if(dist == -1) cout << "no treasure can be reached";
		else cout << "minimum distance: " << dist;
		cout << endl;
	}
	
	
}

