/*
Author : Mikira
Tue 03 Dec 2024 07:58:31 PM HKT
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

#define endl '\n'
const int MOD = 1000000007;
// const int MOD = 998244353;

int sign(LL a){ 
  if(!a) return 0;
  return a / abs(a);
}

int main(){
  string s;
  LL ans = 0;
  while(getline(cin, s)) {
    stringstream ss(s);
    LL num; vector <LL> levels;
    while(ss >> num) {
      levels.push_back(num);
    }
    int n = levels.size();
    int diff = levels[1] - levels[0];
    bool safe = true;
    if(abs(diff) > 3 || diff == 0) {
      safe = false;
    }
    for(int i = 1;i < n;i++) {
      int currentDiff = levels[i] - levels[i - 1];
      if(sign(diff) != sign(currentDiff)) safe = false;
      if(abs(currentDiff) > 3) safe = false;
    }
    ans += safe;
  }
  cout << ans << endl;
  
}