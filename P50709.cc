#include <iostream>
#include <queue>
using namespace std; 

int main(){
    std::priority_queue<int> q;
    char c;
    int n;
    int aux;
    while (cin >> c){
        switch(c){
            case 'S':
                cin >> n;
                q.push(n);
                break;
                
            case 'A':
                if(q.empty()) cout << "error!" << endl;
                else {
                    cout << q.top() << endl;
                }
                break;
                
            case 'R':
                if(q.empty()) cout << "error!" << endl;
                else {
                    q.pop();
                }
                break;
                
            case 'I':
                cin >> n;
                if(q.empty()) cout << "error!" << endl;
                else {
                    aux = q.top();
                    aux += n;
                    q.pop();
                    q.push(aux);
                }
                break;
                
            case 'D':
                cin >> n;
                if(q.empty()) cout << "error!" << endl;
                else {
                    aux = q.top();
                    aux -= n;
                    q.pop();
                    q.push(aux);
                }
                break;
        }
    }
}
