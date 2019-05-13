#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& v){
    for(int i = 0; i < v.size(); i++) {
        if(i == 0) cout << v[i];
        else cout << " " << v[i];
    }
    cout << endl;
}
void Zu(vector<int>& v, int i, int nc, int nu){
    if(i == v.size()) print(v);
    else {
        if(0 < nc){
            v[i] = 0;
            Zu(v, i+1, nc-1, nu);
        }
        if(0 < nu){
            v[i] = 1;
            Zu(v, i+1, nc, nu-1);
        }
    }
}

int main(){
    int n, o;
    cin >> n >> o;
    int nc = n-o;
    int nu = o;
    vector<int> v(n);
    Zu(v, 0, nc, nu);
}
