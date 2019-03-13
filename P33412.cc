#include <iostream>
#include <vector>
using namespace std;

bool binary_search(double x, const vector<double>& v, int left, int right)
{
    if(left > right) return false;
    int middle = (left+right)/2;
    if(v)
    
    return true;
    
}

bool resistant_search(double x, const vector<double>& v)
{
    if(binary_search(x,v,0,v.size())) return true;
    
}

int main() {
    vector<double> v1{33,4,22,11,41,45,3,2,4,5,10}
    resistant_search(4,v1);
    
    vector<double> v1{1,2,3,4,5,6,7,,8,9,10}
    resistant_search(4,v1);
    
    vector<double> v1{3,1,4,5,31,23,53,12}
    resistant_search(12,v1);
    
    vector<double> v1{33,4,22,11,41,45,3,2,4,5,10}
    resistant_search(33,v1);
    
}