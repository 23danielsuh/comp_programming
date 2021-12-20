#include <bits/stdc++.h>
//WAY TOO EASY?????

using namespace std;
typedef long long ll;
#define int ll

void solve() {
	int p, f; cin >> p >> f;
	int cnt_s, cnt_w; cin >> cnt_s >> cnt_w;
	int cost_s, cost_w; cin >> cost_s >> cost_w;
	if(cost_s > cost_w) {
		swap(cnt_s, cnt_w);
		swap(cost_s, cost_w);
	}
	int b = min(p / cost_s + f / cost_s, cnt_s);
	int ans = b;
	for(int i = 0; i <= b; i++) {
		//i represents the number of swords that i have, j represents the number of swords that the follower has
		int j = b - i;
		int new_p = p - i * cost_s;
		int new_f = f - j * cost_s;
		if(new_p < 0 || new_f < 0) continue;
		int cur_ans = min(new_p / cost_w + new_f / cost_w, cnt_w);
		ans = max(ans, cur_ans + b);
	}
	cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
	cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve();
    }
}

/*
 * i can carry 33, follower can carry 27:
 * 6 swords of price 5, 10 axes with price 6
 * it's clearly optimal to just choose the lower price, but you have to fit it in a knapsack so that "most" of it is used
 *
 * i can carry 6 swords -> price 30, 3 left over
 * follower can carry 4 swords -> price 24, 3 left over
 *
 * brute force number of swords that both buy:
 * how many swords do i give to my follower?
 * b = # swords buying
 * x = # swords keeping to myself
 * therefore, (b - x) is # swords for follower
 *
 *
 * 
 * thinking:
 * why would we ever choose not to buy the maximum number of weapons of the cheapest weapon?
 * 	well, what if we had a gap of size 10:
 * 		if we had 3 and 5 as costs: 
 * 			even if the gap were to be open with 3 + 5, it is still optimal?
 * 	
 * 	actually, i think we can fix b to just min(floor(p / cost_sword) + floor(f / cost_sword), num_sword):
 * 		brute force how many swords we keep to ourselves, and calculate the leftover stuff
 *
 * 	sample case 1:
 * 		p = 33, f = 27
 * 		# swords = 6, # axes = 10
 * 		cost_sword = 5, cost_axe = 6
 *
 * 		b = min(floor(33 / 5) + floor(27 / 5), 6) = 6
 * 		
 * 		brute force: let's say we give 1 sword to myself, and 5 swords to my follower
 * 		then, p = 33 - 1 * 5 -> 27
 * 			  f = 27 - 5 * 5 -> 2
 */
