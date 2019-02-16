#include <iostream>
#include <set>
//this version is not a valid solution, need order words
using namespace std;

int main(){
    string s;
    set<string> has;
    set<string> had;
    int i = 0;
    while(cin >> s and s != "QUIT"){
        if(s != "END"){
            auto search_has = has.find(s);//buscamos en has
            auto search_had = had.find(s);//buscamos en had
        
            if(search_has != has.end()){//la palabra está en has
                has.erase(search_has);
                had.insert(s);
            } else if(search_had != had.end()){//la palabra esta en had
                had.erase(search_had);
                has.insert(s);
            } else {//la palabra no está en ninguna, por tanto es nueva
                has.insert(s);
            }
        } else {
            ++i;
            cout << "GAME #" << i << endl;
            cout << "HAS:" << endl;
            //cout has
            for(auto it = has.begin(); it != has.end(); ++it){
                cout << *it << endl;
            }
            
            cout << endl;
            cout << "HAD:" << endl;
            //cout had
            for(auto it = had.begin(); it != had.end(); ++it){
                cout << *it << endl;
            }
            had.clear();
            has.clear();
        }
    }
    ++i;
    cout << endl << "GAME #" << i << endl;
    cout << "HAS:" << endl;
    //cout has
    for(auto it = has.begin(); it != has.end(); ++it){
        cout << *it << endl;
    }
    
    cout << endl;
    cout << "HAD:" << endl;
    //cout had
    for(auto it = had.begin(); it != had.end(); ++it){
        cout << *it << endl;
    }
    
}
