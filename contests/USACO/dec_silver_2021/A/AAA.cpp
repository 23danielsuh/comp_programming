#include <bits/stdc++.h>

using namespace std;
typedef long long ll; 
#define int ll

void solve() {
	int K, M, N; cin >> K >> M >> N;
	vector<pair<int, int>> A(K);
	for(int i = 0; i < K; i++) {
		cin >> A[i].first >> A[i].second;
	}
	sort(A.begin(), A.end());
	set<int> F;
	for(int i = 0; i < M; i++){
		int x; cin >> x;
		F.insert(x);
	}
	F.insert(-1e15); F.insert(1e15);
	vector<pair<pair<int, int>, int>> ranges;
	int j = 0;
	int sum = 0;
	for(int i = 0; i < K; i++) {
		if(i > 0) sum -= A[i - 1].second;
		j = max(j, i);
		int dist_l = LLONG_MAX, dist_r = LLONG_MAX;
		auto l = F.lower_bound(A[i].first);
		if(l != F.begin()) {
			l--;
			dist_l = A[i].first - *l;
		}
		auto r = F.lower_bound(A[j].first);
		if(r != F.end()) {
			dist_r = *r - A[j].first;
		}
		// cout << "at the range [" << A[i].first << ", " << A[j].first << "], the nearest l is at " << *l << ", and the nearest r is at " << *r << "\n";
		double avg = (A[j].first + A[i].first) * 1.0 / (j - i + 1.0);
		if(A[j].first == A[i].first) {
			avg = A[j].first * 1.0;
		}
		// cout << "the distance to the left is " << dist_l << " and the distance to the right is " << dist_r << "\n";
		// cout << "i think that we should be at: " << avg << "\n\n";
		// cout << fixed << setprecision(5) << avg << "\n";
		// cout << "CONFUSING RESULT: " << (max(avg - A[i].first, A[j].first - avg) < min(dist_l, dist_r)) << (j < K) << "\n";
		while(j < K && max(avg - A[i].first, A[j].first - avg) < min(dist_l, dist_r)) {
			sum += A[j].second;
			j++;
			if(j < K) {
				avg = (A[j].first + A[i].first) * 1.0 / (j - i + 1.0);
				// cout << "CURRENT AVERAGE: " << avg << "\n";
			}else {
				break;
			}
		}
		if(j >= N || max(avg - A[i].first, A[j].first - avg) >= min(dist_l, dist_r)) {
			// sum -= A[j].second;
			// j--;
		}
		ranges.push_back({make_pair(A[i].first, A[j - 1].first), sum});
	}
	sort(ranges.begin(), ranges.end(), [](const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
		return a.second > b.second;
	});
	// for(auto &x : ranges) {
	// 	cout << x.first.first << " " << x.first.second << ": " << x.second << "\n";
	// }
	vector<bool> visited((int) 1e7 + 5);
	int ans = 0;
	for(int i = 0, cnt = 0; cnt < N; ) {
		if(i >= ranges.size()) break;
		if(visited[ranges[i].first.first] || visited[ranges[i].first.second]) { i++; continue; }
		ans += ranges[i].second;
		for(int x = ranges[i].first.first; x <= ranges[i].first.second; x++) {
			visited[x] = true;
		}
		cnt++, i++;
	}
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	solve();
}
