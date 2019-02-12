#include <iostream>
#include <map>
using namespace std;

int main(){
    int x,y,n;
    
    while (cin >> x >> y >> n){
        map<int,int> serie;
        int i = 1;
        serie.insert(make_pair(n,i));
        bool encontrado = false;
        auto search = serie.begin();
        while(n <= 100000000 && !encontrado){
            i++;
            if(n % 2 == 0) n = n/2 + x;
            else n = 3*n + y;
            search = serie.find(n);
            if(search != serie.end()) encontrado = true;
            else serie.insert(make_pair(n,i));
        }
        if(!encontrado) cout << n << endl;
        else cout << (serie.size() - search->second + 1) << endl;   
    }
}
