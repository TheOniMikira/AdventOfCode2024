/*
Author : Mikira
Mon 16 Dec 2024 07:55:26 PM HKT
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
const int dy[8] = {1, 0, -1, 0, 1};
const char dch[4] = {'R', 'D', 'L', 'U'};

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
struct DijkNode {
  PLL pos;
  int facing;
  LL val;
  explicit DijkNode(PLL a, int b, LL c = 0): pos(a), facing(b), val(c) {

  }
  bool operator <(const DijkNode &other)const {
    return val > other.val;
  }
};

const int kMax = 200;
LL dist[kMax + 5][kMax + 5][4];
vector <DijkNode> from[kMax + 5][kMax + 5][4];
bool vis[kMax + 5][kMax + 5][4];
LL cost[] = {1000, 1, 1000};

int main() {
  string dummy;
  Grid vv;
  while (getline(cin, dummy)) {
    vv.pb(dummy);
  }
  int n = vv.size();
  int m = vv[0].size();
  rep(i, 0, n) rep(j, 0, m) rep(dir, 0, 4) dist[i][j][dir] = INT_MAX;
  PLL st, ed;
  rep(i, 0, n) {
    rep(j, 0, m) {
      // Mark the start and end of the points
      if (vv[i][j] == 'S') st = {i, j};
      if (vv[i][j] == 'E') ed = {i, j};
    }
  }
  priority_queue <DijkNode> dijkQueue;
  dist[st.fi][st.se][0] = 0;
  dijkQueue.push(DijkNode(st, 0, 0));
  while (!dijkQueue.empty()) {
    DijkNode pos = dijkQueue.top();
    dijkQueue.pop();
    auto &curDist = dist[pos.pos.fi][pos.pos.se][pos.facing];
    if (curDist > pos.val) continue;
    // cout << pos.pos.fi << " " << pos.pos.se << " " << pos.facing << " " << curDist << endl;
    for (int go = -1; go <= 1; go++) {
      int dir = (pos.facing + go + 4) % 4;
      int nx = (go != 0) ? pos.pos.fi : (pos.pos.fi + dx[dir]);
      int ny = (go != 0) ? pos.pos.se : (pos.pos.se + dy[dir]);
      auto curcost = curDist + cost[go + 1];
      if (nx == -1 || ny == -1 || nx == n || ny == m) continue;
      if (vv[nx][ny] == '#') continue;
      auto &nxDist = dist[nx][ny][dir];
      if (nxDist > curcost) {
        nxDist = curcost;
        dijkQueue.push(DijkNode({nx, ny}, dir, curcost));
        from[nx][ny][dir].clear();
      }
      if (nxDist == curcost) {
        from[nx][ny][dir].pb(pos);
      }
    }
  }
  LL ans = LLONG_MAX;
  rep(dir, 0, 4) ans = min(ans, dist[ed.fi][ed.se][dir]);
  auto markAsTrue = [&](DijkNode & asd) {
    vis[asd.pos.fi][asd.pos.se][asd.facing] = 1;
  };
  auto isTrue = [&](DijkNode & asd) -> bool {
    return vis[asd.pos.fi][asd.pos.se][asd.facing];
  };

  rep(dir, 0, 4) {
    if (ans == dist[ed.fi][ed.se][dir]) {
      DijkNode tmpFirst(ed, dir);
      queue <DijkNode> relax;
      relax.push(tmpFirst);
      markAsTrue(tmpFirst);
      while (!relax.empty()) {
        auto curPos = relax.front();
        relax.pop();
        trav(nx, from[curPos.pos.fi][curPos.pos.se][curPos.facing]) {
          if (isTrue(nx)) continue;
          markAsTrue(nx);
          relax.push(nx);
        }
      }
      // Backtrack
    }
  }
  LL cntAns = 0;
  rep(i, 0, n) {
    rep(j, 0, m) {
      int cnt = 0;
      rep(dir, 0, 4) cnt += vis[i][j][dir];
      cnt = cnt > 0;
      cntAns += cnt;
    }
  }

  cout << cntAns << endl;
}
