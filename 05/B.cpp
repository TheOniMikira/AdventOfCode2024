/*
Author : Mikira
Thu 05 Dec 2024 08:16:53 PM HKT
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
vector<string> split(const string &s, char delimiter) {
  vector<string> result;
  result.reserve(count(s.begin(), s.end(), delimiter) + 1); // Optional optimization
  stringstream ss(s);
  string item;

  while (getline(ss, item, delimiter)) {
    result.emplace_back(item);
  }

  return result;
}
map <LL, set<LL>> edge;
map <LL, set<LL>> revEdge;
bool isLessThan[100][100];

int main() {
  string dummy;

  vector <LL> available;

  while (getline(cin, dummy)) {
    auto isRule = dummy.find("|");
    if (isRule == string::npos) break;
    auto splitted = split(dummy, '|');
    available.push_back(stoll(splitted[0]));
    available.push_back(stoll(splitted[1]));
    edge[stoll(splitted[0])].insert(stoll(splitted[1]));
    revEdge[stoll(splitted[1])].insert(stoll(splitted[0]));
  }

  LL ans = 0;
  while (getline(cin, dummy)) {
    // query
    auto pages = split(dummy, ',');
    vector <LL> pageLL;
    trav(cur, pages) {
      pageLL.pb(stoll(cur));
    }
    int n = pageLL.size();
    vector <vector <LL>> fin(n + 5, vector <LL>(n + 5));
    vector <LL> indegree(n + 5);
    int swapCount = 0;
    rep(i,0,n) {
      rep(j,i + 1,n) {
        if(edge[pageLL[i]].count(pageLL[j])) {
          fin[i].pb(j);
        }
        if(edge[pageLL[j]].count(pageLL[i])) {
          swap(pageLL[i], pageLL[j]);
          swapCount++;
        }
      }
    }
    // topo sort
    priority_queue <LL, vector<LL>, greater<LL>> antri;
    rep(i,0,n) {
      if(indegree[i] == 0) antri.push(i);
    }
    if(swapCount == 0) continue;
    trav(cur, pageLL) cout << cur << " ";
    cout << endl;
    ans += pageLL[(n - 1) / 2];
  }

  cout << ans << endl;

}