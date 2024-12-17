/*
Author : Mikira
Tue 17 Dec 2024 08:18:04 PM HKT
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
LL b, c;
vector <LL> instructions;
void run(LL a) {
  LL ori = a;
  auto combo = [&](LL op) {
    if (op <= 3) return op;
    if (op == 4) return a;
    if (op == 5) return b;
    if (op == 6) return c;
    assert(false);
  };

  int ptr = 0;
  vector <LL> outputs;
  for (;; ptr += 2) {
    if (ptr >= instructions.size()) {
      break;
    }
    int opcode = instructions[ptr];
    if (ptr + 1 >= instructions.size()) {
      break;
    }
    LL literal = instructions[ptr + 1];
    if (opcode == 0) {
      LL numerator = a;
      numerator >>= combo(literal);
      a = numerator;
    } else if (opcode == 1) {
      b ^= literal;
    } else if (opcode == 2) {
      b = combo(literal) % 8;
    } else if (opcode == 3) {
      if (a == 0) continue;
      ptr = literal - 2;
    } else if (opcode == 4) {
      b = b ^ c;
    } else if (opcode == 5) {
      int currentI = outputs.size();
      outputs.pb(combo(literal) % 8);
    } else if (opcode == 6) {
      LL numerator = a;
      numerator >>= combo(literal);
      b = numerator;
    } else if (opcode == 7) {
      LL numerator = a;
      numerator >>= combo(literal);
      c = numerator;
    } else {
      assert(false);
    }
  }
  trav(cur, outputs) cout << cur << " ";
  cout << endl;
  return;
}

int main() {
  int dd;
  while (cin >> dd) {
    instructions.pb(dd);
  }
  run(164546384918965);
  return 0;
}