/*
Author : Mikira
Mon 09 Dec 2024 07:52:26 PM HKT
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

#define rep(i, a, b) for(int i = a; i < (b); ++i)
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
const int kMaxDisk = 4e5;
int disks[kMaxDisk + 5];
int main() {
  fasterios();
  string s; cin >> s;
  int n = s.length();
  int idx = 0;
  memset(disks, -1, sizeof(disks));
  rep(i, 0, n) {
    rep(j, 0, s[i] - '0') {
      // cout << j << " " << i / 2 << endl;
      if (i % 2 == 0) {
        disks[idx] = i / 2;
      }
      idx++;
    }
  }
  int rr = idx;
  int ll = 0;
  while (ll < rr) {
    while (disks[ll] != -1) ll++;
    if (ll > rr) break;
    while(rr >= 0 && disks[rr] == -1) rr--;
    if (ll > rr) break;
    swap(disks[rr], disks[ll]);
    rr--;
    ll++;
  }
  LL ans = 0;
  rep(i, 0, kMaxDisk) {
    if(disks[i] == -1) continue;
    ans += i * disks[i];
  }
  cout << ans << endl;
}