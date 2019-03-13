#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef vector<int> VI; 
typedef vector<VI> VVI;


int k_esim(int k, const VVI& V){
    map<int,int> min;
    for(int i = 0; i < V.size(); ++i){
        if(!V[i].empty()) min[V[i][0]] = i;
    }
    
    pair<int,int> res;
    VI it(V.size(), 1);
    
    while(k > 0){
        res.first = min.begin()->first;
        res.second = min.begin()->second;
        if(V[res.second].size() > it[res.second]) {
            int aux = V[res.second][it[res.second]++];
            min[aux] = res.second;
        }
        min.erase(min.begin());
        --k;
    }
    return res.first;
}
