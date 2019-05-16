#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Pos{
	int i,j;
	char c;
	
	Pos(int I, int J, char C){
		i = I;
		j = J;
		c = C;
	}
};

int rows, columns;


void print_board(vector<vector<char> > b){
	for(int i = 0; i < b.size(); i++){
		for(char c : b[i]) cout << c ;
		cout << endl;
	}
}

void print_iniciales(vector<Pos> posit){
	for (Pos p : posit){
		cout << p.i << "|" << p.j << "-->" << p.c << endl;
	}
}

bool isPosible(Pos p, vector<vector<char> >& board, vector<vector<bool> >& mark){
	if(p.i < 0 or p.i >= rows) return false;
	if(p.j < 0 or p.j >= columns) return false;
	if(board[p.i][p.j] != '.') return false;
	if(mark[p.i][p.j]) return false;
	board[p.i][p.j] = p.c;
	return true;
}

void dfs(vector<vector<char> >& board, Pos p){
	queue<Pos> q;
	q.push(p);
	vector<vector<bool> > mark(board.size(), vector<bool>(board[0].size(), false));
	
	while(!q.empty()){
		Pos aux = q.front();
		q.pop();
		mark[aux.i][aux.j] = true;
		Pos up = Pos(aux.i-1,aux.j, aux.c);
		Pos down = Pos(aux.i+1,aux.j, aux.c);
		Pos left = Pos(aux.i,aux.j-1, aux.c);
		Pos right = Pos(aux.i,aux.j+1, aux.c);
		if(isPosible(up, board, mark)) q.push(up);
		if(isPosible(down, board, mark)) q.push(down);
		if(isPosible(left, board, mark)) q.push(left);
		if(isPosible(right, board, mark)) q.push(right);
		//cout << "-";
	}
	//cout << endl;
}

int main(){
	while(cin >> rows >> columns){
		vector<Pos> iniciales;
		vector<vector<char> > board(rows, vector<char>(columns));
		for(int i = 0; i < board.size(); i++){
			for(int j = 0; j < board[i].size(); j++){
				char c;
				cin >> c;
				if(c != '#' and c != '.') {
					iniciales.push_back(Pos(i,j, c));	
				}
				board[i][j] = c;
			}
		}
		//print_board(board);
		//print_iniciales(iniciales);
		for(int i = 0; i < iniciales.size(); i++){
			dfs(board, iniciales[i]);
		}
		print_board(board);
		cout << endl;
	}
}

