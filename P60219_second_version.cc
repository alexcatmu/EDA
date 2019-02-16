#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string a, string b){
    if(a.size() < b.size()) return true;
    else if(a.size() > b.size()) return false;
    else return a < b;
}

void print_words(const map<string,bool> &words, const int &i){
    
    cout << "GAME #" << i << endl << "HAS:" << endl;
    vector<string> words_length;
    
    for(auto it = words.begin(); it != words.end(); ++it){
        if(it->second) cout << it->first << endl;
        else words_length.push_back(it->first);
    }
    
    cout << endl << "HAD:" << endl;
    sort(words_length.begin(), words_length.end(), comp);
    for(int cont = 0; cont < words_length.size(); ++cont){
        cout << words_length[cont] << endl;
    }
}

int main(){
    string s;
    map<string, bool> words;
    int i = 0;
    while(s != "QUIT"){
        while(cin >> s && s!= "END" && s!= "QUIT") {
            words[s] = !words[s];
        }
        ++i;
        if(i > 1) cout << endl;
        print_words(words, i);
        words.clear();
    }
}
