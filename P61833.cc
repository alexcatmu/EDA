#include <iostream>
#include <vector>

using namespace std;

int multiply_matrix(vector<int> M, vector<int> G, int position){
    if(position == 0){
        return ((M[0] * G[0]) + (M[1] * G[2]));
    }
    if(position == 1){
        return ((M[0] * G[1]) + (M[1] * G[3]));
    }
    if(position == 2){
        return ((M[2] * G[0]) + (M[3] * G[2]));
    }
    if(position == 3){
        return ((M[2] * G[1]) + (M[3] * G[3]));
    }
}

vector<int> potenciaMod(vector<int> M, int m){
    vector<int> v(4);
    v[0] = multiply_matrix(M,M,0)%m;
    v[1] = multiply_matrix(M,M,1)%m;
    v[2] = multiply_matrix(M,M,2)%m;
    v[3] = multiply_matrix(M,M,3)%m;
    return v;
}

vector<int> potenciaMod(vector<int> M, vector<int> x, int m){
    vector<int> v(4);
    
    cout << M[0] << "     " << M[1] << endl << M[2] << "     " << M[3] << endl << endl;
    v[0] = multiply_matrix(M,M,0);
    v[1] = multiply_matrix(M,M,1);
    v[2] = multiply_matrix(M,M,2);
    v[3] = multiply_matrix(M,M,3);
    cout << M[0] << "     " << M[1] << endl << M[2] << "     " << M[3] << endl << endl;
    cout << v[0] << "     " << v[1] << endl << v[2] << "     " << v[3] << endl;
    cout << endl << endl;
    v[0] = multiply_matrix(v,x,0)%m;
    v[1] = multiply_matrix(v,x,1)%m;
    v[2] = multiply_matrix(v,x,2)%m;
    v[3] = multiply_matrix(v,x,3)%m;
    return v;
}

vector<int> powersOfAMatrix(vector<int> M, int n, int m){
    if(n == 0){
        return {1,0,0,1};
    }
    vector<int> y = powersOfAMatrix(M, n/2, m);
    if(n % 2 == 0){
        return potenciaMod(y,m);
    } else {
        return potenciaMod(y,M,m);
    }
}

int main(){
    int M1,M2,M3,M4,m,n;
    vector<int> M(4);
    
    while(
        cin >> M1 and
        cin >> M2 and
        cin >> M3 and
        cin >> M4 and
        cin >> n and
        cin >> m
    ){
        M[0] = M1;
        M[1] = M2;
        M[2] = M3;
        M[4] = M4;

        M = powersOfAMatrix(M, n, m);
        
        cout << M[0] << " " << M[1] << endl;
        cout << M[2] << " " << M[3] << endl;
        cout << "----------" << endl;
    }
}
