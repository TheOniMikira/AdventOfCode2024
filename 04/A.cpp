/*
Author : Mikira
Wed 04 Dec 2024 07:44:03 PM HKT
*/

#include "bits/stdc++.h"
using namespace std;

typedef long long LL;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> PII;
typedef pair<int, int> pii;
typedef pair<LL, LL> PLL;
typedef pair<LL, LL> pll;
typedef long double ld;

#define rep(i, a, b) for(int i = a; i < (int)(b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define popf pop_front
#define pf push_front
#define popb pop_back
#define pb push_back
#define fi first
#define se second

const double EPS = 1e-9;
const int INFMEM = 63;

// Do dir^1 to get reverse direction
const int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
const int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
const char dch[4] = {'R', 'L', 'D', 'U'};

// Do (dir + 2)%4 to get reverse direction
// const int dx[8] = {-1,0,1,0,-1,1,1,-1};
// const int dy[8] = {0,1,0,-1,1,1,-1,-1};
// const char dch[4] = {'U','R','D','L'};
const double PI = 3.141592653589793;

inline void fasterios() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
}
#define endl '\n'
const int MOD = 1000000007;
// const int MOD = 998244353;

int main() {
  string s;
  vector <string> vv;
  while (getline(cin, s)) {
    vv.push_back(s);
  }
  int n = vv.size();
  int m = vv[0].size();
  string matcher = "XMAS";
  LL ans = 0;
  rep(i, 0, n) {
    rep(j, 0, m) {
      rep(dir, 0, 8) {
        bool matches = true;
        rep(l, 0, matcher.size()) {
          int nx = i + l * dx[dir];
          int ny = j + l * dy[dir];
          if(nx < 0 || ny < 0 || nx >= n || ny >= m) {
            matches = false;
            break;
          }
          if(vv[nx][ny] != matcher[l]) {
            matches = false;
            break;
          }
        }
        ans += matches;
      }
    }
  }
  cout << ans << endl;
}