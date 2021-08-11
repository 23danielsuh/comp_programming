#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 2005;
int task[mxN][mxN];
vector<int> scores(mxN), cont(mxN), task_solved(mxN);

bool cmp(const int &a, const int &b) {
    if(cont[a] != cont[b]) {
        return cont[a] > cont[b];
    }
    if(task_solved[a] != task_solved[b]) {
        return task_solved[a] > task_solved[b];
    }
    return a < b;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, T, P; cin >> N >> T >> P;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < T; j++) {
            cin >> task[i][j];
        }
    }
    for(int i = 0; i < T; i++) {
        int temp = 0;
        for(int j = 0; j < N; j++) {
            temp += int(task[j][i] == 0);
        }
        scores[i] = temp;
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < T; j++) {
            task[i][j] == 1 ? cont[i] += scores[j] : cont[i] += 0;
            task_solved[i] += int(task[i][j] == 1);
        }
    }
    vector<int> indices(N);
    for(int i = 0; i < N; i++) {
        indices[i] = i;
    }
    sort(indices.begin(), indices.end(), cmp);
    cout << cont[P - 1] << " ";
    for(int i = 0; i < N; i++) {
        if(indices[i] == P - 1) {
            cout << i + 1 << "\n";
            return 0;
        }
    }
}

