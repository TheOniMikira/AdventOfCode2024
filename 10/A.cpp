/*
Author : Mikira
Tue 10 Dec 2024 08:30:52 PM HKT
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
const int dx[8] = {0,0,1,-1,1,-1,1,-1};
const int dy[8] = {1,-1,0,0,1,-1,-1,1};
const char dch[4] = {'R','L','D','U'};

// Do (dir + 2)%4 to get reverse direction
// const int dx[8] = {-1,0,1,0,-1,1,1,-1};
// const int dy[8] = {0,1,0,-1,1,1,-1,-1};
// const char dch[4] = {'U','R','D','L'};
const double PI = 3.141592653589793;

inline void fasterios(){
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
}
#define endl '\n'
const int MOD = 1000000007;
// const int MOD = 998244353;
vector <string> vv;
vector <vi> cnt;
int main(){
  string s;
  while(getline(cin, s)) {
    vv.pb(s);
  }
  int n = vv.size();
  int m = vv[0].size();
  cnt.resize(n, vi(m));
  LL ans = 0;
  for(int i = '9';i >= '0';i--){
    rep(j,0,n) {
      rep(k,0,m) {
        if(vv[j][k] == i) {
          if(i == '9') cnt[j][k] = 1;
          else {
            rep(dir,0,4) {
              int nx = j + dx[dir];
              int ny = k + dy[dir];
              if(nx < 0 || ny < 0 || nx == n || ny == m) continue;
              if(vv[nx][ny] == i + 1) {
                cnt[j][k] += cnt[nx][ny];
              }
            }
          }
          if(i == '0') {
            ans += cnt[j][k];
            cout << (char) i << " " << cnt[j][k] << endl;
          }        
        } 
      }
    }
  }
  cout << ans << endl;
}