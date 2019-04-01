#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > operator* (vector<vector<int> > v, vector<vector<int> > v2){
    vector<vector<int> > aux(2,vector<int>(2));
    aux[0][0] = v[0][0] * v2[0][0] + v[0][1] * v2[1][0];
    aux[0][1] = v[0][0] * v2[0][1] + v[0][1] * v2[1][1];
    aux[1][0] = v[1][0] * v2[0][0] + v[1][1] * v2[1][0];
    aux[1][1] = v[1][0] * v2[0][1] + v[1][1] * v2[1][1];
    return aux;
}

vector<vector<int> > operator% (vector<vector<int> > v, int m){
    vector<vector<int> > aux(2,vector<int>(2));
    aux[0][0] = v[0][0] % m;
    aux[0][1] = v[0][1] % m;
    aux[1][0] = v[1][0] % m;
    aux[1][1] = v[1][1] % m;
    return aux;
}

ostream& operator<<(ostream& out, const vector<vector<int> > v){
    cout << v[0][0] << " " << v[0][1] << endl;
    cout << v[1][0] << " " << v[1][1] << endl;
}

vector<vector<int> > powersOfAMatrix(vector<vector<int> > M, int n, int m){
    if(n == 0){
        return {{1,0},{0,1}};
    }
    vector<vector<int> > y = powersOfAMatrix(M, n/2, m);
    if(n % 2 == 0){
        return (y * y) % m;
    } else {
        return (y * y * M) % m;
    }
}

int main(){
    int M1,M2,M3,M4,m,n;
    vector<vector<int> > M(2,vector<int>(2));
    
    while(
        cin >> M1 and
        cin >> M2 and
        cin >> M3 and
        cin >> M4 and
        cin >> n and
        cin >> m
    ){
        M[0][0] = M1;
        M[0][1] = M2;
        M[1][0] = M3;
        M[1][1] = M4;

        M = powersOfAMatrix(M, n, m);
        
        cout << M << "----------" << endl;
    }
}
