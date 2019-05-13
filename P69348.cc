#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& v){
    for(int i = 0; i < v.size(); i++) {
        if(i == 0) cout << "(" << v[i] + 1;
        else cout << "," << v[i] + 1;
    }
    cout << ")" << endl;
}

void permutations(vector<int>& v,vector<bool>& use, int i){
    if(i == v.size()) print(v);
    else {
        for(int j = 0; j < v.size(); j++){
            if(use[j]) {
                v[i] = j;
                use[j] = false;
                permutations(v, use, i+1);
                use[j] = true;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    vector<bool> use(n, true);
    permutations(v,use, 0);
}
