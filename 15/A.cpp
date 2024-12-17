/*
Author : Mikira
Sun 15 Dec 2024 02:47:38 PM HKT
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
const int dx[8] = {0, 0, 1, -1};
const int dy[8] = {1, -1, 0, 0};
const char dch[4] = {'>', '<', 'v', '^'};

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

using Grid = vector <string>;

inline int toDir(char ch) {
  rep(i, 0, 4) if (dch[i] == ch) return i;
  assert(false);
  return -1;
}

//#.#
//#..[].
//#[][]
// .[][]
//   @

void moveSubmarine(Grid &table, PLL &pos, const int dir) {
  PLL firstMove = {pos.fi + dx[dir], pos.se + dy[dir]};
  rep(step, 0, 10000) {
    int nx = pos.fi + dx[dir] * step;
    int ny = pos.se + dy[dir] * step;
    if (table[nx][ny] == '.') {
      // #..OOOOOOO.@
      // #OOO@
      swap(table[firstMove.fi][firstMove.se], table[nx][ny]);
      swap(table[firstMove.fi][firstMove.se], table[pos.fi][pos.se]);
      pos = firstMove;
      break;
    } else if (table[nx][ny] == '#') {
      break;
    }
  }
}

int main() {

  // Reading inputs
  string s;
  Grid table;
  while (getline(cin, s)) {
    if (s == "") break;
    table.pb(s);
  }
  int n = table.size();
  int m = table[0].size();

  string directions = "";
  while (getline(cin, s)) {
    directions += s;
  }

  PLL pos;

  rep(i, 0, n) {
    rep(j, 0, m) {
      if (table[i][j] == '@') {
        pos = {i, j};
      }
    }
  }

  // Move the submarine

  rep(i, 0, sz(directions)) {
    moveSubmarine(table, pos, toDir(directions[i]));
  }

  LL ans = 0;
  // Count the answers after movement
  rep(i, 0, n) {
    rep(j, 0, m) {
      cout << table[i][j];
      if (table[i][j] == 'O') ans += i * 100 + j;
    }
    cout << endl;
  }
  cout << ans << endl;


}