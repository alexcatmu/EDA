
#include <iostream>
#include <vector>
using namespace std;

int search_unimodal(int left, int right, const vector<int>& v){
    if(right == left) return left;
    else if(right -left == 1) {
        if(v[right] > v[left]) return right;
        else return left;
    }
    int mid = (left+right) / 2;
    if(v[mid] > v[mid-1] and v[mid] > v[mid+1]) return mid;
    else if(v[mid-1] > v[mid]) return search_unimodal(left, mid-1, v);
    else if(v[mid+1] > v[mid]) return search_unimodal(mid+1, right, v);
    return mid;
}

bool dichotomic_search_asc(int left, int right, int x, const vector<int>& v){
    if(left > right) return false;
    else{
        int mid = (left+right) / 2;
        if(v[mid] == x) return true;
        else if(v[mid] < x) dichotomic_search_asc(mid+1, right, x, v);
        else dichotomic_search_asc(left, mid-1, x, v);
    }
}

bool dichotomic_search_desc(int left, int right, int x, const vector<int>& v){
    if(left > right) return false;
    else{
        int mid = (left+right) / 2;
        if(v[mid] == x) return true;
        else if(v[mid] > x) dichotomic_search_desc(mid+1, right, x, v);
        else dichotomic_search_desc(left, mid-1, x, v);
    }
}

bool search(int x, const vector<int>& v){
    int pivot = search_unimodal(0, v.size()-1, v);
    //cout << pivot << " " << v[pivot] << endl;
    if(dichotomic_search_asc(0, pivot, x, v)) return true;
    else if(dichotomic_search_desc(pivot, v.size()-1, x, v)) return true;
    else return false;
}


int main() {
    int n;
    while (cin >> n) {
        vector<int> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int m;
        cin >> m;
        while (m--) {
          int x;
          cin >> x;
          cout << ' ' << search(x, V);
        }
        cout << endl;
    }
}