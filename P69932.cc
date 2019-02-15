#include <iostream>
#include <set>
#include <sstream>

using namespace std;


int main(){
    int n;
    string s;
    while (getline(cin, s)){
        istringstream ss(s);
        set<int> conj_num;
        while (ss >>n){
            conj_num.insert(n);
        }
        auto it_next = conj_num.begin();
        int sequence_quantity = 0;
        for(auto it = conj_num.begin(); it != conj_num.end(); ++it){
            it_next++;
            if(
                it_next != conj_num.end()
                and (
                    (*it % 2 == 0 and *it_next % 2 != 0)
                    or
                    (*it_next % 2 == 0 and *it & 2 != 0)
                )
            ) ++sequence_quantity;
        }
        if(!conj_num.empty()) ++sequence_quantity;
        cout << sequence_quantity << endl;
    }
}














