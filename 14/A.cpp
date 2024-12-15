/*
Author : Mikira
Sat 14 Dec 2024 01:08:20 PM HKT
*/
#include<stdlib.h>
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
const int kX = 101;
const int kY = 103;

int getQuadrant(LL x, LL y) {
  LL ans = 0;
  if (x == kX / 2) return 4;
  if (y == kY / 2) return 4;
  if (x < kX / 2) ans += 2;
  if (y > kY / 2) ans ^= 1;
  return ans;
}

void display(const vector <PLL> &robots) {
  vector <vector<int>> dis(kX, vector <int>(kY));
  trav(cur, robots) dis[cur.fi][cur.se]++;
  rep(j, 0, kY) {
    rep(i, 0, kX) {
      if (dis[i][j] == 0) cout << '.';
      else cout << dis[i][j];
    }
    cout << endl;
  }

}

int main() {
  std::ifstream file("input.in");  // Open file

  // p=(-?\d*),(-?\d*) v=(-?\d*),(-?\d*)
  LL n; file >> n;
  vector <PLL> robots(n);
  vector <PLL> ori(n);
  vector <PLL> velo(n);
  // LL ans = 0;
  rep(i, 0, n) file >> robots[i].fi >> robots[i].se >> velo[i].fi >> velo[i].se;
  vector <LL> cnt(5);
  int step = 0;
  ori = robots;
  file.close();
  while (true) {
    system("stty raw");   // Enable raw mode
    char tmp = getchar();
    system("stty cooked"); 
    if(tmp == 'c') return 0;
    if(tmp == 'd') step++;
    if(tmp == 'a') step--;
    system("clear");
    cout << endl;
    cout << endl;
    cout << endl;
    cout << step << endl;
    for (int i = 0; i < n; i++) {
      robots[i].fi = ori[i].fi + velo[i].fi * step;
      robots[i].se = ori[i].se + velo[i].se * step;
      robots[i].fi %= kX;
      robots[i].se %= kY;
      robots[i].fi += kX;
      robots[i].se += kY;
      if (robots[i].fi >= kX) robots[i].fi -= kX;
      if (robots[i].se >= kY) robots[i].se -= kY;
      // cout << robots[i].fi << " " << robots[i].se << endl;
      // int curQuad = getQuadrant(robots[i].fi, robots[i].se);
      // cout << curQuad << endl;
      // cnt[curQuad]++;
    }
    display(robots);
  }
  // cout << cnt[0] * cnt[1] * cnt[2] * cnt[3] << endl;
}