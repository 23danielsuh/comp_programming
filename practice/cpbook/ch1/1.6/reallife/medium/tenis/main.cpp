#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int wins1 = 0, wins2 = 0;

pair<bool, int> analyze(int score1, int score2, int set_num, string player1, string player2) {
    if(score1 == score2) 
        return make_pair(0, 0);
    bool winner = 0;
    if(score1 < score2) {
        winner = 1;
        swap(score1, score2);
        swap(player1, player2);
    }
    if(player2 == "federer") 
        return make_pair(0, winner);
    if(score1 < 6) 
        return make_pair(0, winner);
    if(score1 == 6)
        return make_pair(score2 <= 4, winner);
    if(score1 == 7 && set_num < 2) 
        return make_pair(score2 == 5 || score2 == 6, winner);
    if(score1 >= 7 && set_num == 2)
        return make_pair(abs(score1 - score2) == 2, winner);
    
    return make_pair(0, winner);
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string p1, p2;
    cin >> p1 >> p2;
    int T; cin >> T;
    cin.ignore();
    while(T--) {
        //cin.ignore(0);
        string S; getline(cin, S);
        vector<string> scores;
        string word = "";
        int N = (int) S.size();
        for(int i = 0; i < N; i++) {
            if(S[i] == ' ') {
                scores.push_back(word);
                word = "";
            }else {
                word += S[i];
            }
        }
        if(word.size()) scores.push_back(word);
        bool flag = 1;
        wins1 = 0, wins2 = 0;
        
        for(int i = 0; i < (int) scores.size(); i++) {
            string x = scores[i];
            int pos = x.find(":");
            string sub1 = x.substr(0, pos), sub2 = x.substr(pos + 1);
            int score1 = stoi(sub1), score2 = stoi(sub2);
            
            flag &= wins1 < 2;
            flag &= wins2 < 2;
            
            //cout << analyze(score1, score2, i, p1, p2).first << " " << analyze(score1, score2, i, p1, p2).second << "\n";

            flag &= analyze(score1, score2, i, p1, p2).first;
            analyze(score1, score2, i, p1, p2).second ? wins2++ : wins1++;
        }
        if(flag && (wins1 == 2 || wins2 == 2)) {
            cout << "da";
        }else {
            cout << "ne";
        }
        cout << "\n";
    }
}

