#include <iostream>
#include <set>
using namespace std;

int main(){
    int x,y,n;
    cin >> x >> y >> n;
    set<int> set1;
    set1.insert(10);
    for (auto it = set1.begin(); it != set1.end(); ++it) cout << *it << endl;
}
