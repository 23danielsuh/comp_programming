template <int MOD=998244353>
struct Mint {
    int value;
    static const int MOD_value = MOD;

    Mint(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
    Mint(long long a, long long b) : value(0){ *this += a; *this /= b;}

    Mint& operator+=(Mint const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
    Mint& operator-=(Mint const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
    Mint& operator*=(Mint const& b) {value = (long long)value * b.value % MOD;return *this;}

    friend Mint mexp(Mint a, long long e) {
		Mint res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
		return res;
    }
    friend Mint inverse(Mint a) { return mexp(a, MOD - 2); }

    Mint& operator/=(Mint const& b) { return *this *= inverse(b); }
    friend Mint operator+(Mint a, Mint const b) { return a += b; }
    friend Mint operator-(Mint a, Mint const b) { return a -= b; }
    friend Mint operator-(Mint const a) { return 0 - a; }
    friend Mint operator*(Mint a, Mint const b) { return a *= b; }
    friend Mint operator/(Mint a, Mint const b) { return a /= b; }
    friend std::ostream& operator<<(std::ostream& os, Mint const& a) {return os << a.value;}
    friend bool operator==(Mint const& a, Mint const& b) {return a.value == b.value;}
    friend bool operator!=(Mint const& a, Mint const& b) {return a.value != b.value;}
};
#define mint Mint
