#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, string> p1, pair<int, string> p2){
    if(p1.first > p2.first) return true;
    else if(p1.first < p2.first) return false;
    else{
        if(p1.second >= p2.second) return false;
        else return true;
    }
}

int main(){
    string action;
    string player;
    string player1;
    string player2;
    map<string,pair<int,bool>> player_points;
    
    
    int MIN = 1200;
    int DAMAGE = 10;
    
    while(cin >> action){
        if(action == "LOGIN"){
            cin >> player;
            auto search = player_points.find(player);
            if(search == player_points.end()) player_points[player]= make_pair(MIN, true);
            else player_points[player].second = true;
        } else if(action == "LOGOUT"){
            cin >> player;
            auto search = player_points.find(player);
            if(search != player_points.end()) player_points[player].second = false;
        } else if(action == "PLAY"){
            cin >> player1 >> player2;
            auto search1 = player_points.find(player1);
            auto search2 = player_points.find(player2);
            
            if(search1 != player_points.end() and search2 != player_points.end()){
                if(player_points[player1].second == true and player_points[player2].second == true){
                    
                    player_points[player1].first += DAMAGE;
                    if(player_points[player2].first >= MIN+10) player_points[player2].first -= DAMAGE;
                    
                } else cout << "player(s) not connected" << endl;
            } else cout << "player(s) not connected" << endl;
            
        } else if(action == "GET_ELO"){
            cin >> player;
            cout << player << " " << player_points[player].first << endl;
        }
        
    }
    
    
    
    cout << endl << "RANKING" << endl;
    
    vector<pair<int,string> > ranking(player_points.size());
    int i = 0;
    for(auto it = player_points.begin(); it != player_points.end(); ++it){
        ranking[i].first = it->second.first;
        ranking[i].second = it->first;
        ++i;
    }
    
    sort(ranking.begin(), ranking.end(), comp);
    
    
    for(int i = 0; i < ranking.size(); ++i){
        cout << ranking[i].second << " " << ranking[i].first << endl;
    }
    
    /*
    
    
    
    map<int, vector<string>> final_ranking;
    
    for(auto it = player_points.begin(); it != player_points.end(); ++it){
        final_ranking[it->second.first].push_back(it->first);
        //cout << it->first << " " << it->second.first << endl;
    }
    
    
    auto it = final_ranking.end();
    --it;
    while(it != final_ranking.begin()){
        for(int i = 0; i < it->second.size(); ++i){
            cout << it->second[i] << " " << it->first << endl;
        }
        --it;
    }
    
    for(int i = 0; i < it->second.size(); ++i){
            cout << it->second[i] << " " << it->first << endl;
    }
    
    /*
    cout << "-------------------------------" << endl;
    
    for(auto it = final_ranking.begin(); it != final_ranking.end(); ++it){
        //cout << it->first << " " << it->second.first << endl;
        for(int i = it->second.size() - 1; i >= 0; --i){
            cout << it->second[i] << " " << it->first << endl;
        }
    }
    */
}