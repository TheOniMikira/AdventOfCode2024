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

#define rep(i, a, b) for(int i = a; i < int(b); ++i)
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
  vector <PLL> emptySegments;
  memset(disks, -1, sizeof(disks));
  vector <PLL> numbered;
  rep(i, 0, n) {
    int start = idx;
    int ed = idx + s[i] - '0' - 1;
    idx = ed + 1;
    // cout << start << " " << ed << " i " << i << endl;
    if(i%2) emptySegments.emplace_back(start, ed);
    else numbered.emplace_back(start, ed);
  }
  LL ans = 0;
  int N = numbered.size();
  for(int i = N - 1;i >= 0;i--){
    auto &curNum = numbered[i];
    rep(j,0,emptySegments.size()) {
      auto &curSegment = emptySegments[j];
      LL len = curSegment.se - curSegment.fi + 1;
      if(curSegment.fi > curNum.se) break;
      LL len2 = curNum.se - curNum.fi + 1;
      if(len2 > len) continue;
      curNum.fi = curSegment.fi;
      curNum.se = curSegment.fi + len2 - 1;
      curSegment.fi += len2;
      break;
    }
    ans += (curNum.se + curNum.fi) * (curNum.se - curNum.fi + 1) / 2 * i;
    // cout << curNum.fi << " " << curNum.se << endl;
  }
  cout << ans << endl;
}