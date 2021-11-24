#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 50;
pair<char, pair<int, int>> grid[mxN][mxN];
bool visited[mxN][mxN][100000];
bool visited_board[100000];
vector<int> pow3(10);
int ans = 0;
int N;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

bool check(int x) {
    return x > 0 && x <= N;
}

int board[3][3];

bool win(int hash) {
    memset(board, 0, sizeof board);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            int cur_char = hash % 3;
            hash /= 3;
            board[i][j] = cur_char;
        }
    }
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == 2 && board[i][1] == 1 && board[i][2] == 1) {
            return true;
        }
        if(board[i][2] == 2 && board[i][1] == 1 && board[i][0] == 1) {
            return true;
        }
    }
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == 2 && board[1][i] == 1 && board[2][i] == 1) {
            return true;
        }
        if(board[2][i] == 2 && board[1][i] == 1 && board[0][i] == 1) {
            return true;
        }
    }
    if(board[0][0] == 2 && board[1][1] == 1 && board[2][2] == 1) {
        return true;
    }
    if(board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 2) {
        return true;
    }
    if(board[0][2] == 2 && board[1][1] == 1 && board[2][0] == 1) {
        return true;
    }
    if(board[0][2] == 1 && board[1][1] == 1 && board[2][2] == 2) {
        return true;
    }
    return false;
}

set<int> answers;

void floodfill(int r, int c, int hash) {
    if(visited[r][c][hash]) return;
    visited[r][c][hash] = true;

    if(grid[r][c].first == 'O' || grid[r][c].first == 'M') {
        //change hash function
        pair<int, int> temp_idx = grid[r][c].second;
        int idx = temp_idx.first * 3 + temp_idx.second;
        int current_char = (hash / pow3[idx]) % 3;
        if(current_char == 0) {
            int new_char = grid[r][c].first == 'O' ? 1 : 2;
            assert((hash % pow3[idx]) + new_char * pow3[idx] + (hash - hash % pow3[idx+1]) == new_char * pow3[idx] + hash);
            hash = hash + pow3[idx] * new_char;
            if(!visited[r][c][hash] && win(hash)) { answers.insert(hash); return; };
            visited[r][c][hash] = true;
        }
    }
    
    for(int i = 0; i < 4; i++) {
        if(check(r + dx[i]) && check(c + dy[i])) {
            if(grid[r + dx[i]][c + dy[i]].first != '#') {
                floodfill(r + dx[i], c + dy[i], hash);
            }
        }
    }
}

void solve() {
    cin >> N;
    pair<int, int> start;
    pow3[0] = 1;
    for(int i = 1; i < 10; i++) {
        pow3[i] = pow3[i - 1] * 3;
    }
    for(int i = 0; i < N; i++) {
        string S; cin >> S;
        for(int j = 0; j < N; j++) {
            string cur = S.substr(j * 3, 3);
            if(cur[0] == 'B') {
                start = {i, j};
                grid[i][j].first = '.';
            }else if(cur[0] == 'O' || cur[0] == 'M') {
                grid[i][j].first = cur[0];
                grid[i][j].second = {cur[1] - '0' - 1, cur[2] - '0' - 1};
            }else if(cur[0] == '#') {
                grid[i][j].first = '#';
            }else if(cur[0] == '.') {
                grid[i][j].first = '.';
            }
        }
    }
    floodfill(start.first, start.second, 0);
    cout << answers.size() << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}
