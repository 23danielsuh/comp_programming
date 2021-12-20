#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

// Updates a node in Binary Index Tree (BITree) at given index
// in BITree. The given value 'val' is added to BITree[i] and
// all of its ancestors in tree.
void updateBIT(int BITree[], int n, int index, int val)
{
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
  
    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
        // Add 'val' to current node of BI Tree
        BITree[index] += val;
  
        // Update index to that of parent in update View
        index += index & (-index);
    }
}
  
// Constructs and returns a Binary Indexed Tree for given
// array of size n.
int *constructBITree(vector<int> &arr, int n)
{
    // Create and initialize BITree[] as 0
    int *BITree = new int[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;
  
    // Store the actual values in BITree[] using update()
    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);
  
    // Uncomment below lines to see contents of BITree[]
    //for (int i=1; i<=n; i++)
    //      cout << BITree[i] << " ";
  
    return BITree;
}
  
// SERVES THE PURPOSE OF getElement()
// Returns sum of arr[0..index]. This function assumes
// that the array is preprocessed and partial sums of
// array elements are stored in BITree[]
int getSum(int BITree[], int index)
{
    int sum = 0; // Iniialize result
  
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
  
    // Traverse ancestors of BITree[index]
    while (index>0)
    {
        // Add current element of BITree to sum
        sum += BITree[index];
  
        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}
  
// Updates such that getElement() gets an increased
// value when queried from l to r.
void update(int BITree[], int l, int r, int n, int val)
{
    // Increase value at 'l' by 'val'
    updateBIT(BITree, n, l, val);
  
    // Decrease value at 'r+1' by 'val'
    updateBIT(BITree, n, r+1, -val);
}

struct pi {
	pair<int, int> range;
	int sum = 0;
};

void solve() {
	int K, M, N; cin >> K >> M >> N;
	vector<pair<int, int>> fields(K); for(auto &x : fields) cin >> x.first >> x.second;
	vector<int> F;
	for(int i = 0; i < M; i++) {
		int x; cin >> x;
		F.push_back(x);
	}
	F.push_back(-1e9 - 5000000); F.push_back(1e9 + 500000);
	sort(F.begin(), F.end());
	sort(fields.begin(), fields.end());
	int idx = 0;
	vector<int> all_vals;
	for(int i = 1; i < (int) F.size(); i++) {
		set<int> dont_include;
		pair<int, int> cur_range = make_pair(F[i - 1], F[i]);
		vector<pair<int, int>> cur;
		while(idx < K && fields[idx].first > cur_range.first && fields[idx].first < cur_range.second) {
			cur.push_back(make_pair(fields[idx].first, fields[idx].second));
			idx++;
		}
		int sz = (int) cur.size();
		if(!sz) continue;
		vector<pi> ranges;
		for(int j = 0; j < sz; j++) {
			int pos = cur[j].first, taste = cur[j].second;
			pi next;

			auto L = lower_bound(F.begin(), F.end(), pos);
			auto R = lower_bound(F.begin(), F.end(), pos);
			int distL = 1e9, distR = 1e9;
			if(L != F.begin()) {
				L--;
				distL = abs(pos - *L);
			}
			if(R != F.end()) {
				distR = abs(pos - *R);
			}
			next.range = make_pair(pos - min(distL, distR), pos + min(distL, distR) - 1);
			next.sum = taste;
			ranges.push_back(next);
		}
		set<int> cc_vals;
		map<int, int> cc;
		for(auto &x : ranges) {
			cc_vals.insert(x.range.first);
			cc_vals.insert(x.range.second);
		}
		int cc_cur = 1;
		for(auto &x : cc_vals) {
			cc[x] = cc_cur;
			cc_cur++;
		}
		vector<int> diff((int) cc_vals.size() + 5, 0);
		vector<int> psum((int) cc_vals.size() + 5, 0);
		for(auto &x : ranges) {
			x.range.first = cc[x.range.first];
			x.range.second = cc[x.range.second];
			diff[x.range.first] += x.sum;
			diff[x.range.second] -= x.sum;
		}
		for(int j = 1; j <= (int) cc_vals.size(); j++) {
			diff[j] += diff[j - 1];
			psum[j] += diff[j];
		}

		//create BIT of psum
		int *BITree = constructBITree(psum, (int) psum.size());
		
		//BOTTLENECK HERE:
		while(true) {
			int mx = 0, upd_val = -1;
			mx = getSum(BITree, (int) psum.size() - 1);
			if(mx < 0) break;
			for(int j = 0; j < (int) ranges.size(); j++) {
				if(dont_include.count(j)) continue;
				if(upd_val >= ranges[j].range.first && upd_val <= ranges[j].range.second) {
					int l = ranges[j].range.first, r = ranges[j].range.second, val = -ranges[j].sum;
					update(BITree, l, r, (int) psum.size(), val);
					dont_include.insert(j);
				}
			}
			all_vals.push_back(mx);
		}
	}
	sort(all_vals.begin(), all_vals.end(), greater<int>());
	int ans = 0;
	for(int i = 0; i < N; i++) {
		if(i >= (int) all_vals.size()) {
			break;
		}
		ans += all_vals[i];
	}
	cout << ans << "\n";
}

int32_t main() {
	//ios::sync_with_stdio(false); cin.tie(nullptr);
	//freopen("in", "r", stdin);
	solve();
}
