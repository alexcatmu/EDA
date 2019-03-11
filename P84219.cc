#include <iostream>
#include <vector>
using namespace std;

int find(double x, const vector<double>& v, int left, int right){
    if(left > right) return -1;
    if(left == right) {
        if(v[right] == x) return right;
        else return -1;
    }
    
    
    int n = (left + right) / 2;
    if(v[n] < x) return find(x, v, n+1, right);
    else return find(x, v, left, n);
}

int first_occurrence(double x, const vector<double>& v){
    return find(x, v, 0, v.size()-1);
}


int main() {
    vector<double> v{1,2,3,3,4,4,5,5,6,6,6,6,6,7};
    cout << first_occurrence(7,v) << endl;
    
    
    vector<double> v1{1};
    cout << first_occurrence(1,v1) << endl;
    
    
    vector<double> v2{1};
    cout << first_occurrence(7,v2) << endl;
}
