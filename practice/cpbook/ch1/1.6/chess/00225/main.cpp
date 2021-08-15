#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool queen_vis[8][8], king_vis[8][8], queen_vis1[8][8];
pair<int, int> queen_pos, king_pos, mov_pos;
int king, queen, mov;

int cdiv(int a, int b) { return a / b + ((a ^ b) > 0 && a % b); }
int fdiv(int a, int b) { return a / b - ((a ^ b) < 0 && a % b); }

bool legal_state() {
    if(king == queen) return false;
    return true;
}

bool legal_move() {
    if(king_pos.first > 0) king_vis[king_pos.first - 1][king_pos.second] = true;
    if(king_pos.first < 7) king_vis[king_pos.first + 1][king_pos.second] = true;
    if(king_pos.second > 0) king_vis[king_pos.first][king_pos.second - 1] = true;
    if(king_pos.second < 7) king_vis[king_pos.first][king_pos.second + 1] = true;
    
    pair<int, int> temp = queen_pos;
    while(temp.first >= 0 && temp != king_pos) {queen_vis[temp.first][temp.second] = true; temp.first--; }
    temp = queen_pos;
    while(temp.first < 8 && temp != king_pos) {queen_vis[temp.first][temp.second] = true; temp.first++; }
    temp = queen_pos;
    while(temp.second >= 0 && temp != king_pos) {queen_vis[temp.first][temp.second] = true; temp.second--; }
    temp = queen_pos;
    while(temp.second < 8 && temp != king_pos) {queen_vis[temp.first][temp.second] = true; temp.second++; }
    
    queen_vis[queen_pos.first][queen_pos.second] = false;

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(!queen_vis[i][j] && i == mov_pos.first && j == mov_pos.second) {
                return false;
            }
        }
    }
    
    return true;
}

bool allowed_move() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(king_vis[i][j] && queen_vis[i][j] && (i == mov_pos.first && j == mov_pos.second)) {
                return false;
            }
        }
    }
    return true;
}

bool cont() {
    pair<int, int> temp = mov_pos;
    while(temp.first >= 0) {queen_vis1[temp.first][temp.second] = true; temp.first--; }
    temp = mov_pos;
    while(temp.first < 8) {queen_vis1[temp.first][temp.second] = true; temp.first++; }
    temp = mov_pos;
    while(temp.second >= 0) {queen_vis1[temp.first][temp.second] = true; temp.second--; }
    temp = mov_pos;
    while(temp.second < 8) {queen_vis1[temp.first][temp.second] = true; temp.second++; }
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(king_vis[i][j] && !queen_vis1[i][j]) {
                return true;
            }
        }
    }
    return false;
}

int32_t main() {
    //ios::sync_with_stdio(false); cin.tie(nullptr);
    while(cin >> king) {
        memset(king_vis, 0, sizeof king_vis);
        memset(queen_vis, 0, sizeof queen_vis);
        memset(queen_vis1, 0, sizeof queen_vis1);
        cin >> queen >> mov;
        queen_pos.first = fdiv(queen, 8);
        queen_pos.second = queen % 8;
        king_pos.first = fdiv(king, 8);
        king_pos.second = king % 8;
        mov_pos.first = fdiv(mov, 8);
        mov_pos.second = mov % 8;
        if(!legal_state()) {
            cout << "Illegal state\n";
            continue;
        }
        if(!legal_move()) {
            cout << "Illegal move\n";
            continue;
        }
        if(!allowed_move()) {
            cout << "Move not allowed\n"; 
            continue;
        }
        if(cont()) {
            cout << "Continue\n";
        }else {
            cout << "Stop\n";
        }
    }
}

