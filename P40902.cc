#include <iostream>
#include <map>

using namespace std;

int main(){
    map<string,int> players;
    string name;
    string action;
    int money;
    auto search = players.begin();
    while(cin >> name){
        cin >> action;
        if(action == "enters") {
            search = players.find(name);
            if(search != players.end()) cout << name << " is already in the casino" << endl;
            else {
                players[name] = 0;
            }
        } else if(action == "leaves"){
            search = players.find(name);
            if(search == players.end()) cout << name << " is not in the casino" << endl;
            else {
                cout << name << " has won " << players[name] << endl;
                players.erase(search);
            }
        } else if(action == "wins"){
            cin >> money;
            search = players.find(name);
            if(search == players.end()) cout << name << " is not in the casino" << endl;
            else {
                players[name] += money;
            }
        }
    }
    cout << "----------" << endl;
    for(auto it = players.begin(); it != players.end(); ++it){
        cout << it->first << " is winning " << it->second << endl;
    }
}
