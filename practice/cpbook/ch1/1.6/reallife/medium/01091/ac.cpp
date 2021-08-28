#include <bits/stdc++.h>
#define maxn 210
using namespace std;
int n, a[maxn], b[maxn];
map<string, int> M;
string check() {
    if(n % 6 != 5 || (n + 1) / 6 < 5) {
        return "bad code";
    }
    int maxa = 0, mina = INT_MAX;
    for(int i = 0; i < n; ++i) {
        maxa = max(maxa, a[i]);
        mina = min(mina, a[i]);
    }
    double t = (maxa + mina) / 2.0;
    maxa = 0, mina = INT_MAX;
    for(int i = 0; i < n; ++i) {
        int tmp = a[i];
        if(tmp < t) tmp *= 2;
        maxa = max(maxa, tmp);
        mina = min(mina, tmp);
    }
    if(maxa * 95 > mina * 105) return "bad code";
    string s;
    for(int i = 0; i < n; i++) {
        s.push_back(a[i] < t ? '0' : '1');
    }
    if(s.substr(0, 5) != "00110")
        reverse(s.begin(), s.end());
    if(s.substr(0, 5) != "00110")
        return "bad code";
    int k = 0;
    for(int i = 0; i < n; i += 6) {
        if(i + 5 < n && s[i + 5] == '1') 
            return "bad code";
        if(!M.count(s.substr(i, 5)))
            return "bad code";
        b[k++] = M[s.substr(i, 5)];
    }
    if(b[0] != -1 || b[k - 1] != -1) return "bad code";
    for(int i = 1; i < k - 1; i++) {
        if(b[i] == -1) {
            return "bad code";
        }
    }
    int m = k - 2, c = 0, d = 0;
    for(int i = 1; i <= m - 2; ++i) {
        c += ((m - 2 - i) % 10 + 1) * b[i];
        c %= 11;
    }
    for(int i = 1; i <= m - 1; ++i) {
        d += ((m - 1 - i) % 9 + 1) * b[i];
        d %= 11;
    }
    if(c != b[m - 1]) return "bad C";
    if(d != b[m]) return "bad K";
    string ret;
    for(int i = 1; i <= m - 2; i++) {
        ret.push_back(b[i] == 10 ? '-':'0' + b[i]);
    }
    return ret;
}

int main() {
    M["00001"] = 0;
    M["10001"] = 1;
    M["01001"] = 2;
    M["11000"] = 3;
    M["00101"] = 4;
    M["10100"] = 5;
    M["01100"] = 6;
    M["00011"] = 7;
    M["10010"] = 8;
    M["10000"] = 9;
    M["00100"] = 10;
    M["00110"] = -1;
    int kase = 0;
    while(~scanf("%d", &n) && n) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        printf("Case %d: %s\n", ++kase, check().c_str());
    }
}

