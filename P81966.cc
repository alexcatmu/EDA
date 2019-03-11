#include <iostream>
#include <vector>
using namespace std;


int position(double x, const vector<double>& v, int left, int right){
    if(left > right) return -1;
    int n = (right + left) / 2;
    if(v[n] > x) return position(x, v, left, n-1);
    if(v[n] < x) return position(x,v,n+1,right);
    return n;
}


int main() {
    vector<double> V{1,2,3,4,5,6,7};
    cout << position(5,V, 0, V.size()) << endl;
}
