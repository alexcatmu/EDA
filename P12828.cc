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

void Zu(vector<int> v, int i){
    if(i == v.size()) print(v);
    else {
        v[i] = 0;
        Zu(v, i+1);
        v[i] = 1;
        Zu(v, i+1);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n,0);
    Zu(v, 0);
}
