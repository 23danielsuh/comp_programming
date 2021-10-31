#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define int ll

const int mxN = 25;
int N;
int dist[mxN][mxN][4][mxN][mxN][4];
bool grid[mxN][mxN];
 
struct Point {
	int first, second, direction;
};

Point move_forward(Point cur) {
	int direction = cur.direction;
	switch(direction) {
		case 0:
			cur.second--;
			if(cur.second < 0) { cur.second++; return cur; }
			if(grid[cur.first][cur.second] == 1) cur.second++;
			return cur;
			break;
		case 1:
			cur.first--;
			if(cur.first < 0) { cur.first++; return cur; }
			if(grid[cur.first][cur.second] == 1) cur.first++;
			return cur;
			break;
		case 2:
			cur.second++;
			if(cur.second >= N) { cur.second--; return cur; }
			if(grid[cur.first][cur.second] == 1) cur.second--;
			return cur;
			break;
		case 3:
			cur.first++;
			if(cur.first >= N) { cur.first--; return cur; }
			if(grid[cur.first][cur.second] == 1) cur.first--;
			return cur;
			break;
	}
	assert(false);
}
 
void solve() {
	for(auto &a : dist) 
		for(auto &b : a) 
			for(auto &c : b) 
				for(auto &d : c)
					for(auto &e : d)
						for(auto &f : e)
							f = 100000000LL;
	cin >> N;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			char c; cin >> c;
			grid[i][j] = c == 'E' ? 0 : 1;
		}
	}
	queue<pair<pair<Point, Point>, int>> q;
	/*
	Directions:
	0 = left
	1 = up
	2 = right
	3 = down
	*/
	Point start1, start2;
	start1.first = N - 1, start1.second = 0, start1.direction = 2;
	start2.first = N - 1, start2.second = 0, start2.direction = 1;
	q.push({make_pair(start1, start2), 0});
	dist[start1.first][start1.second][start1.direction][start2.first][start2.second][start2.direction] = 0;
	int ans = INT_MAX;
	while(!q.empty()) {
		Point x = q.front().first.first, y = q.front().first.second; int cur_dist = q.front().second; q.pop();
		bool move_x = 1, move_y = 1;
		if(x.first == 0 && x.second == N - 1) {
			move_x = 0;
		}
		if(y.first == 0 && y.second == N - 1) {
			move_y = 0;
		}
		if(x.first == 0 && x.second == N - 1 && y.first == 0 && y.second == N - 1) {
			ans = min(ans, cur_dist);
		}
		//simulate moving forward
		Point forward_x = x, forward_y = y;
		if(move_x) {
			forward_x = move_forward(x);
		}
		if(move_y) {
			forward_y = move_forward(y);
		}
		if(cur_dist + 1 < dist[forward_x.first][forward_x.second][x.direction][forward_y.first][forward_y.second][y.direction]) {
			q.push({make_pair(move_forward(x), move_forward(y)), cur_dist + 1});
			dist[forward_x.first][forward_x.second][x.direction][forward_y.first][forward_y.second][y.direction] = cur_dist + 1;
		}
		for(int i = 1; i <= 3; i++) {
			Point new_x = x, new_y = y;
			if(move_x) {
				new_x.direction = (new_x.direction + i) % 4;
			}
			if(move_y) {
				new_y.direction = (new_y.direction + i) % 4;
			}
			if(i == 2 && cur_dist + 2 < dist[x.first][x.second][new_x.direction][y.first][y.second][new_y.direction]) {
				q.push({make_pair(new_x, new_y), cur_dist + 2});
				dist[x.first][x.second][new_x.direction][y.first][y.second][new_y.direction] = cur_dist + 2;
				continue;
			}
			if(cur_dist + 1 < dist[x.first][x.second][new_x.direction][y.first][y.second][new_y.direction]) {
				q.push({make_pair(new_x, new_y), cur_dist + 1});
				dist[x.first][x.second][new_x.direction][y.first][y.second][new_y.direction] = cur_dist + 1;
			}
		}
	}
	cout << ans << "\n";
}
 
int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("cownav.in", "r", stdin);
	freopen("cownav.out", "w", stdout);
    int T = 1;
    // cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}