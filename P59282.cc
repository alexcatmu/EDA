#include <iostream>
#include <map>

using namespace std;


int main(){
    
    cout.setf(ios::fixed);
    cout.precision(4);
    
    map<int,int> num;
    double average = 0;
    int acumulador = 0;
    int cantidad = 0;
    int n;
    string s;
    auto it = num.begin();
    while(cin >> s){
        if(s == "number"){
            cin >> n;
            acumulador += n;
            cantidad++;
            if(num.find(n) != num.end()) {
                ++num[n];
            }
            else {
                num[n] = 1;
            }
            
        } else if(s == "delete"){
            if(not num.empty()){
                n = num.begin()->first;
                acumulador -= n;
                cantidad--;
                if(num[n] <= 1) num.erase(num.begin());
                else --num[n];
            }
            
            
        }
        if(not num.empty()){
            it = num.begin();
            cout << "minimum: " << it->first << ", ";
            it = num.end();
            --it;
            average = (double)acumulador / cantidad;
            cout << "maximum: " << it->first << ", average: " << average << endl;
        } else {
            cout << "no elements" << endl;
        }
    }
}