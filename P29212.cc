#include <iostream>


using namespace std;

int modular_exponent(long n, int k, long m){
    if(k == 0) return 1;
    else {
        long y = modular_exponent(n, k/2, m);
        if(k %2 == 0) return (y * y)%m;
        else return (y * y * n)%m;
    }
}

int main(){
    long n, m;
    int k;
    while(cin >> n >> k >> m){
        long n_exp_k = modular_exponent(n,k,m);
        cout << n_exp_k % m << endl;
    }
}
