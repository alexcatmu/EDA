#include <iostream>
#include <set>

using namespace std;

int main(){
    set<string> word;
    string s;
    auto it = word.begin();
    while (cin >> s && s != "END"){
        word.insert(s);
        if(word.size() == 1) it = word.begin();
        if(s > *it && word.size() % 2 != 0) it++;
        else if (s < *it && word.size() % 2 == 0) it--;
        cout << *it << endl;
    }
}
