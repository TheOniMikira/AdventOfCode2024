/*
Author : Mikira
Tue 03 Dec 2024 07:51:32 PM HKT
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

int main(){
  string s;
  vector <LL> numberA;
  vector <LL> numberB;
  while(getline(cin, s)) {
    stringstream ss(s);
    LL a, b; ss >> a >> b;
    numberA.push_back(a);
    numberB.push_back(b);
  }
  sort(all(numberA));
  sort(all(numberB));
  LL ans = 0;
  LL n = numberA.size();
  rep(i,0,n) {
    ans += abs(numberA[i] - numberB[i]);
  }
  cout << ans << endl;
}