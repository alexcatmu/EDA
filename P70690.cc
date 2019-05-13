#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char> > Matrix;

int f, c;

bool founded = false;

ostream& operator << (ostream& out, const Matrix& M){
    for(int i = 0; i < f; i++){
        for(int j = 0; j < c; j++){
            out << M[i][j];
        }
        out << endl;
    }
    return out;
}

istream& operator >> (istream& in, Matrix& M){
    for(int i = 0; i < f; i++){
        for(int j = 0; j < c; j++){
            in >> M[i][j];
        }
    }
    return in;
}

bool valid_position(const Matrix &m, int i, int j, vector<vector<bool> >& mark){
    //in range
    if(i < 0) return false;
    if(j < 0) return false;
    if(i >= f) return false;
    if(j >= c) return false;
    
    //no X
    if(m[i][j] == 'X') return false;
    if(mark[i][j]) return false;
    return true;
}

bool find_treasure(const Matrix &m, int i, int j, vector<vector<bool> > &mark){
    
    mark[i][j] = true;
    if(m[i][j] == 't') {
        founded = true;
        return true;
    }
    if(valid_position(m, i+1, j, mark)) {
        if(m[i+1][j] == 't') {
            founded = true;
            return true;
        }
        else find_treasure(m, i+1, j, mark);
    }
    if(valid_position(m, i-1, j, mark)) {
        if(m[i-1][j] == 't') {
            founded = true;
            return true;
        }
        else find_treasure(m, i-1, j, mark);
    }
    if(valid_position(m, i, j+1, mark)) {
        if(m[i][j+1] == 't') {
            founded = true;
            return true;
        }
        else find_treasure(m, i, j+1, mark);
    }
    if(valid_position(m, i, j-1, mark)) {
        if(m[i][j-1] == 't') {
            founded = true;
//             return true;
        }
        else find_treasure(m, i, j-1, mark);
    }
    
    return false;
}

int main() {
    int i, j;
    cin >> f >> c;
    Matrix m(f, vector<char>(c));
    vector<vector<bool> > mark(f, vector<bool>(c,false));
    cin >> m;
    cin >> i >> j;
    --i;
    --j;
    find_treasure(m, i, j, mark);
    //cout << m << endl;
    if(founded) cout << "yes" << endl;
    else cout << "no" << endl;
}
