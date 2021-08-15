#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool attack[8][8];
char grid[8][8];
string S;

bool check(int row, int col) {
    return row >= 0 && row < 8 && col >= 0 && col < 8;
}

void rook(int row, int col, bool black) {
    int trow = row, tcol = col;
    trow++;
    while(check(trow, tcol)) { attack[trow][tcol] = true; 
        if(grid[trow][tcol] != '0') {
            break;
        }trow++; }
    trow = row, tcol = col;
    trow--;
    while(check(trow, tcol)) { attack[trow][tcol] = true; 
        if(grid[trow][tcol] != '0') {
            break;
        }trow--; }
    trow = row, tcol = col;
    tcol++;
    while(check(trow, tcol)) { attack[trow][tcol] = true; 
        if(grid[trow][tcol] != '0') {
            break;
        }tcol++; }
    trow = row, tcol = col;
    tcol--;
    while(check(trow, tcol)) { attack[trow][tcol] = true; 
        if(grid[trow][tcol] != '0') {
            break;
        }tcol--; }
}

void pawn(int row, int col, bool black) {
    if(!black) {
        if(check(row - 1, col - 1)) attack[row - 1][col - 1] = true;
        if(check(row - 1, col + 1)) attack[row - 1][col + 1] = true;
    }else {
        if(check(row + 1, col - 1)) attack[row + 1][col - 1] = true;
        if(check(row + 1, col + 1)) attack[row + 1][col + 1] = true;
    }
}

void queen(int row, int col, bool black) {
    int trow = row, tcol = col;
    trow++;
    while(check(trow, tcol)) { attack[trow][tcol] = true; 
        if(grid[trow][tcol] != '0') {
            break;
        }trow++; }
    trow = row, tcol = col;
    trow--;
    while(check(trow, tcol)) { attack[trow][tcol] = true; 
        if(grid[trow][tcol] != '0') {
            break;
        }trow--; }
    trow = row, tcol = col;
    tcol++;
    while(check(trow, tcol)) { attack[trow][tcol] = true; 
        if(grid[trow][tcol] != '0') {
            break;
        }tcol++; }
    trow = row, tcol = col;
    tcol--;
    while(check(trow, tcol)) { attack[trow][tcol] = true; 
        if(grid[trow][tcol] != '0') {
            break;
        }tcol--; }
    
    //diags
    trow = row, tcol = col;
    trow++; tcol++;
    while(check(trow, tcol)) { attack[trow][tcol] = true; 
        if(grid[trow][tcol] != '0') {
            break;
        }trow++; tcol++;}
    trow = row, tcol = col;
    trow--; tcol++;
    while(check(trow, tcol)) { attack[trow][tcol] = true; 
        if(grid[trow][tcol] != '0') {
            break;
        }trow--; tcol++;}
    trow = row, tcol = col;
    trow++; tcol--;
    while(check(trow, tcol)) { attack[trow][tcol] = true; 
        if(grid[trow][tcol] != '0') {
            break;
        }trow++; tcol--;}
    trow = row, tcol = col;
    trow--; tcol--;
    while(check(trow, tcol)) { attack[trow][tcol] = true; 
        if(grid[trow][tcol] != '0') {
            break;
        }trow--; tcol--;}
    trow = row, tcol = col;
}

void bishop(int row, int col, bool black) {
    int trow = row, tcol = col;
    trow = row, tcol = col;
    trow++; tcol++;
    while(check(trow, tcol)) { attack[trow][tcol] = true; 
        if(grid[trow][tcol] != '0') {
            break;
        }trow++; tcol++;}
    trow = row, tcol = col;
    trow--; tcol++;
    while(check(trow, tcol)) { attack[trow][tcol] = true; 
        if(grid[trow][tcol] != '0') {
            break;
        }trow--; tcol++;}
    trow = row, tcol = col;
    trow++; tcol--;
    while(check(trow, tcol)) { attack[trow][tcol] = true; 
        if(grid[trow][tcol] != '0') {
            break;
        }trow++; tcol--;}
    trow = row, tcol = col;
    trow--; tcol--;
    while(check(trow, tcol)) { attack[trow][tcol] = true; 
        if(grid[trow][tcol] != '0') {
            break;
        }trow--; tcol--;}
}

void king(int row, int col, bool black) {
    if(check(row + 1, col)) attack[row + 1][col] = true;
    if(check(row - 1, col)) attack[row - 1][col] = true;
    if(check(row, col + 1)) attack[row][col + 1] = true;
    if(check(row, col - 1)) attack[row][col - 1] = true;
    if(check(row + 1, col + 1)) attack[row + 1][col + 1] = true;
    if(check(row + 1, col - 1)) attack[row + 1][col - 1] = true;
    if(check(row - 1, col + 1)) attack[row - 1][col + 1] = true;
    if(check(row - 1, col - 1)) attack[row - 1][col - 1] = true;
}

void knight(int row, int col, bool black) {
    if(check(row + 2, col - 1)) attack[row + 2][col - 1] = true;
    if(check(row + 2, col + 1)) attack[row + 2][col + 1] = true;
    if(check(row - 2, col - 1)) attack[row - 2][col - 1] = true;
    if(check(row - 2, col + 1)) attack[row - 2][col + 1] = true;
    if(check(row - 1, col + 2)) attack[row - 1][col + 2] = true;
    if(check(row + 1, col + 2)) attack[row + 1][col + 2] = true;
    if(check(row - 1, col - 2)) attack[row - 1][col - 2] = true;
    if(check(row + 1, col - 2)) attack[row + 1][col - 2] = true;
}

int32_t main() {
    //ios::sync_with_stdio(false); cin.tie(nullptr);
    while(cin >> S) {
        memset(attack, 0, sizeof attack);
        memset(grid, 0, sizeof grid);
        int row = 0, column = 0;
        for(int i = 0; i < (int) S.size(); i++) {
            if(S[i] == '/') {
                column = 0;
                row++;
                continue;
            }
            if(S[i] - '0' > 0 && S[i] - '0' <= 8) {
                int cnt = 0;
                while(cnt < S[i] - '0') {
                    grid[row][column] = '0';
                    column++;
                    cnt++;
                }
            }else {
                grid[row][column] = S[i];
                column++;
            }
        }
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                //cout << grid[i][j];
                if(grid[i][j] == '0') continue;
                if(grid[i][j] == 'r' || grid[i][j] == 'R') {
                    rook(i, j, grid[i][j] == 'r');
                }
                if(grid[i][j] == 'n' || grid[i][j] == 'N') {
                    knight(i, j, grid[i][j] == 'n');
                }
                if(grid[i][j] == 'b' || grid[i][j] == 'B') {
                    bishop(i, j, grid[i][j] == 'b');
                }
                if(grid[i][j] == 'q' || grid[i][j] == 'Q') {
                    queen(i, j, grid[i][j] == 'q');
                }
                if(grid[i][j] == 'k' || grid[i][j] == 'K') {
                    king(i, j, grid[i][j] == 'k');
                }
                if(grid[i][j] == 'p' || grid[i][j] == 'P') {
                    pawn(i, j, grid[i][j] == 'p');
                }
            }
            //cout << "\n";
        }
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(grid[i][j] != '0') {
                    attack[i][j] = true;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(!attack[i][j]) ans++;
            }
        }
        cout << ans << "\n";
    }
}

