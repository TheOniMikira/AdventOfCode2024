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
const int dx[4] = {1, -1, 1, -1};
const int dy[4] = {1, -1, -1, 1};
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

vector <string> vv;
int n, m;
void goPlus(int x, int y, int goDir, vector <int> &cnter) {
  int nx = x + dx[goDir];
  int ny = y + dy[goDir];
  if (nx < 0 || ny < 0 || nx >= n || ny >= m) return;
  cnter[vv[nx][ny] - 'A']++;
}
const int M = 'M' - 'A';
const int S = 'S' - 'A';
int main() {
  string s;
  while (getline(cin, s)) {
    vv.push_back(s);
  }
  n = vv.size();
  m = vv[0].size();
  LL ans = 0;
  rep(i, 0, n) {
    rep(j, 0, m) {
      if (vv[i][j] != 'A') continue;
      bool matches = true;
      vector <int> cnter(26);
      goPlus(i, j, 0, cnter);
      goPlus(i, j, 1, cnter);
      if (cnter[S] == cnter[M] && cnter[S] == 1) {}
      else matches = false;
      vector <int> cnter2(26);
      goPlus(i, j, 2, cnter2);
      goPlus(i, j, 3, cnter2);
      if (cnter2[S] == cnter2[M] && cnter2[S] == 1) {}
      else matches = false;
      ans += matches;
    }
  }
  cout << ans << endl;
}