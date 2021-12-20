#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 5e5 + 9, mod = 1e9 + 7;

template <const int32_t MOD>
struct modint {
  int32_t value;
  modint() = default;
  modint(int32_t value_) : value(value_) {}
  inline modint<MOD> operator + (modint<MOD> other) const { int32_t c = this->value + other.value; return modint<MOD>(c >= MOD ? c - MOD : c); }
  inline modint<MOD> operator - (modint<MOD> other) const { int32_t c = this->value - other.value; return modint<MOD>(c <    0 ? c + MOD : c); }
  inline modint<MOD> operator * (modint<MOD> other) const { int32_t c = (int64_t)this->value * other.value % MOD; return modint<MOD>(c < 0 ? c + MOD : c); }
  inline modint<MOD> & operator += (modint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
  inline modint<MOD> & operator -= (modint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
  inline modint<MOD> & operator *= (modint<MOD> other) { this->value = (int64_t)this->value * other.value % MOD; if (this->value < 0) this->value += MOD; return *this; }
  inline modint<MOD> operator - () const { return modint<MOD>(this->value ? MOD - this->value : 0); }
  modint<MOD> pow(uint64_t k) const { modint<MOD> x = *this, y = 1; for (; k; k >>= 1) { if (k & 1) y *= x; x *= x; } return y; }
  modint<MOD> inv() const { return pow(MOD - 2); }  // MOD must be a prime
  inline modint<MOD> operator /  (modint<MOD> other) const { return *this *  other.inv(); }
  inline modint<MOD> operator /= (modint<MOD> other)       { return *this *= other.inv(); }
  inline bool operator == (modint<MOD> other) const { return value == other.value; }
  inline bool operator != (modint<MOD> other) const { return value != other.value; }
  inline bool operator < (modint<MOD> other) const { return value < other.value; }
  inline bool operator > (modint<MOD> other) const { return value > other.value; }
};
template <int32_t MOD> modint<MOD> operator * (int64_t value, modint<MOD> n) { return modint<MOD>(value) * n; }
template <int32_t MOD> modint<MOD> operator * (int32_t value, modint<MOD> n) { return modint<MOD>(value % MOD) * n; }
template <int32_t MOD> istream & operator >> (istream & in, modint<MOD> &n) { return in >> n.value; }
template <int32_t MOD> ostream & operator << (ostream & out, modint<MOD> n) { return out << n.value; }

using mint = modint<mod>;

struct combi{
  int n; vector<mint> facts, finvs, invs;
  combi(int _n): n(_n), facts(_n), finvs(_n), invs(_n){
    facts[0] = finvs[0] = 1;
    invs[1] = 1;
    for (int i = 2; i < n; i++) invs[i] =  invs[mod % i] * (-mod / i);
    for(int i = 1; i < n; i++){
      facts[i] = facts[i - 1] * i;
      finvs[i] = finvs[i - 1] * invs[i];
    }
  }
  inline mint fact(int n) { return facts[n]; }
  inline mint finv(int n) { return finvs[n]; }
  inline mint inv(int n) { return invs[n]; }
  inline mint ncr(int n, int k) { return n < k or k < 0 ? 0 : facts[n] * finvs[k] * finvs[n-k]; }
};
combi C(mxN);

const int MOD = 1e9 + 7;

void solve() {
    int N, M, K; cin >> N >> M >> K;
	vector<int> A(N); for(auto &x : A) cin >> x;
	sort(A.begin(), A.end());
	mint ans = 0;
	for(int i = 0; i < N; i++) {
		int l = i + 1;
		int r = upper_bound(A.begin(), A.end(), A[i] + K) - A.begin();
		ans += C.ncr(r - l, M - 1);
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
 * number of subsequences such that the max(A) - min(A) <= K
 *
 * states:
 * dp[i] -> # of tuples of size M in the array [0, i]
 * 
 * transitions:
 * when you add an element, what happens?
 * well, how many new subsequences can you form wiht that new element?
 * dp[i - 1] + ?
 * dp[i - 1] because you can still form all of the other subsequences by just not using element i
 * num_elements greater than a[i] - k and less than a[i] -> cnt_l
 * add cnt_l choose 2
 *
 * num_elements greater than a[i] and less than a[i] + k -> cnt_r
 * add cnt_r choose 2 
 * actually, cnt_r double counts, so don't add (cnt_r choose 2)
 *
 * dp[i - 1] + (cnt_l choose 2) 
 *
 * how do we deal with the in between space?
 *
 * can you sort it WLOG? -> max is communative, and indices can just be switched around, so yes?
 * actually never mind 
 * 
 * sample case 1:
 * choose 3 elements, such that the max(A) - min(A) <= K
 * dp[0] = 0
 * dp[1] = 0
 * dp[2] = 0
 * 
 */
