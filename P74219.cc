#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > operator* (const vector<vector<int> > &v, const vector<vector<int> > &v2){
    vector<vector<int> > aux(2,vector<int>(2));
    int p1,p2,p3,p4,p5,p6,p7;
    p1 = v[0][0] * (v2[0][1]-v2[1][1]);
    p2 = (v[0][0] + v[0][1]) * v2[1][1];
    p3 = (v[1][0]+v[1][1])*v2[0][0];
    p4 = v[1][1]*(v2[1][0]-v2[0][0]);
    p5 = (v[0][0]+v[1][1])*(v2[0][0]+v2[1][1]);
    p6 = (v[0][1]-v[1][1])*(v2[1][0]+v2[1][1]);
    p7 = (v[0][0]-v[1][0])*(v2[0][0]+v2[0][1]);
    
    aux[0][0] = p5+p4-p2+p6;
    aux[0][1] = p1+p2;
    aux[1][0] = p3+p4;
    aux[1][1] = p1+p5-p3-p7;
    return aux;
}

vector<vector<int> > operator% (const vector<vector<int> > &v, const int &m){
    vector<vector<int> > aux(2,vector<int>(2));
    aux[0][0] = v[0][0] % m;
    aux[0][1] = v[0][1] % m;
    aux[1][0] = v[1][0] % m;
    aux[1][1] = v[1][1] % m;
    return aux;
}

vector<vector<int> > powersOfAMatrix(const vector<vector<int> > &M, const int &n, const int &m){
    if(n <= 1){
        return M;
    } else {
        vector<vector<int> > y = powersOfAMatrix(M, n/2, m);
        if(n % 2 == 0){
            return (y * y) % m;
        } else {
            return (y * y * M) % m;
        }   
    }
}

int main(){
    long n;
    long m;
    vector<vector<int> > M(2,vector<int>(2));
    
    while(
        cin >> n and
        cin >> m
    ){
        if(n <= 1) cout << n << endl;
        else {
            M[0][0] = 0;
            M[0][1] = 1;
            M[1][0] = 1;
            M[1][1] = 1;
            vector<vector<int> > aux = powersOfAMatrix(M, n-1, m);
            
            cout << (aux[0][0] + aux[0][1])%m << endl;
        }
    }
}