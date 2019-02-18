#include <iostream>
#include <queue>

using namespace std;

string s;

class comp{
    public:
        bool operator()(string a, string b){
            if(a.length() == b.length()){
                string new_char_for_compare = s.substr(0,a.size());
                if(a == new_char_for_compare) return false;
                if(b == new_char_for_compare) return true;
                if(a < b){
                    if(a < new_char_for_compare and new_char_for_compare < b) return true;
                    return false;
                } else {
                    if(a > new_char_for_compare and new_char_for_compare > b) return false;
                    return true;
                }
            }
            else return a.length() > b.length();
        }    
};


int main(){
    while(cin >> s){
        char action;
        string ask_for_ticket;
        priority_queue<string, vector<string>, comp> tickets_asked;
        int give_ticket = 0;
        while(cin >> action && action != 'E'){
            if(action == 'S'){
                cin >> ask_for_ticket;
                tickets_asked.push(ask_for_ticket);
            } else if(action == 'T'){
                ++give_ticket;
            }
            while(give_ticket > 0 and (!tickets_asked.empty())){
                cout << tickets_asked.top() << endl;
                tickets_asked.pop();
                --give_ticket;
            }
        }

        cout << give_ticket << " ticket(s) left" << endl;
        cout << (tickets_asked.size()) << " supporter(s) with no ticket" << endl;
        cout << endl;
    }
}