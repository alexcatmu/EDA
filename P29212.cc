#include <iostream>


using namespace std;

int exponent(double n, int k){
    if(k == 0) return 1;
    else {
        double y = exponent(n, k/2);
        if(k %2 == 0) return y * y;
        else return y * y * n;
    }
}

int main(){
    double n, m;
    int k;
    cin >> n >> k >> m;
    double n_exp_k = exponent(n,k);
    cout << n_exp_k << endl;
    //cout << n_exp_k % m << endl;
}
