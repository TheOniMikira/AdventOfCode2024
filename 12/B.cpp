/*
Author : Mikira
Fri 13 Dec 2024 12:31:57 AM HKT
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
const int dx[8] = {0, 1, 0, -1};
const int dy[8] = {1, 0, -1, 0};

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
vector <vector<PLL>> bucket;
bool vis[1005][1005];
int main() {
  string dummy;
  while (getline(cin, dummy)) {
    vv.pb(dummy);
  }
  int n = vv.size();
  int m = vv[0].size();
  auto isValid = [&](int NX, int NY) {
    return !(NX < 0 || NY < 0 || NX >= n || NY >= m);
  };
  LL ans = 0;
  rep(i, 0, n) {
    rep(j, 0, m) {
      if (vis[i][j]) continue;
      vis[i][j] = 1;
      queue <PLL> q;
      q.push({i, j});
      LL perim = 0;
      LL area = 0;
      while (!q.empty()) {
        PLL pos = q.front();
        q.pop();
        area++;
        rep(dir, 0, 4) {
          int nx = pos.fi + dx[dir];
          int ny = pos.se + dy[dir];
          if (!isValid(nx, ny) || vv[i][j] != vv[nx][ny]) {
            // ok potential, now look at the dir + 1
            int gox = pos.fi + dx[(dir + 1) % 4];
            int goy = pos.se + dy[(dir + 1) % 4];
            if(!isValid(gox, goy) || vv[gox][goy] != vv[i][j]) {
              perim++;
              continue;
            }
            int nxx = gox + dx[dir];
            int nyy = goy + dy[dir];
            if(!isValid(nxx, nyy) || vv[nxx][nyy] != vv[i][j]) {
              continue;
            } else {
              perim++;
              continue;
            }
          }
        }
        rep(dir, 0, 4) {
          int nx = pos.fi + dx[dir];
          int ny = pos.se + dy[dir];
          if (vis[nx][ny]) continue;
          if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
          if (vv[i][j] != vv[nx][ny]) continue;
          vis[nx][ny] = 1;
          q.push({nx, ny});
        }
      }
      cout << area << " " << vv[i][j] << " " << perim << endl;
      ans += area * perim;
    }
  }
  cout << ans << endl;
}