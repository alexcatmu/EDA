#include <iostream>
#include <map>

using namespace std;

int main(){
    string action;
    string word;
    map<string,int> map_words;
    auto search = map_words.begin();
    while(cin >> action){
        if(action == "minimum?"){
            if(map_words.empty()) cout << "indefinite minimum" << endl;
            else {
                auto it = map_words.begin();
                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        } else if(action == "maximum?"){
            if(map_words.empty()) cout << "indefinite maximum" << endl;
            else {
                auto it = map_words.end();
                --it;
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl; 
            }
        } else if(action == "store"){
            cin >> word;
            search = map_words.find(word);
            if(search != map_words.end()) ++map_words[word];
            else map_words[word] = 1;
        } else if(action == "delete"){
            cin >> word;
            search = map_words.find(word);
            if(search != map_words.end()){
                if(map_words[word] > 1) --map_words[word];
                else map_words.erase(search);
            }
        }
    }
}