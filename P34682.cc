#include <iostream>
#include <vector>

using namespace std;

int searchFixedPoints(int x, const vector<int>& v, int left, int right){
    if(left > right) return -1;
    if(left == right){
        //cout << "iguales!!"  << endl;
        if(v[left] + x == left+1) {
            //cout << "if" << endl;
            return left + 1;
        }
        else {
            //cout << "else!!" << endl;
            return -1;
        }
    }
    int m = (left + right) / 2;
    if(v[m] + x < m+1) return searchFixedPoints(x,v,m+1,right);
    else return searchFixedPoints(x,v,left,m);
}

int main()
{
    int cont = 1;
    int S;
    int x;
    int m;
    while(cin >> S){
        cout << "Sequence #" << cont << endl;
        vector<int> v(S);
        for(int i = 0; i < S; ++i){
            cin >> x;
            v[i] = x;
        }
        
        cin >> m;
        for(int i = 0; i < m; ++i){
            int a;
            cin >> a;
            int result = searchFixedPoints(a,v,0,v.size()-1);
            if(result == -1) cout << "no fixed point for " << a << endl;
            else cout << "fixed point for " << a << ": " << result << endl;
        }
        cout << endl;
        ++cont;
    }
}
