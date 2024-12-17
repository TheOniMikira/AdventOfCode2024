/*
Author : Mikira
Tue 17 Dec 2024 09:13:00 PM HKT
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

/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a,b) ((a) |= (1ULL<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b))))        // '!!' to make sure this returns 0 or 1

/* x=target variable, y=mask */
#define BITMASK_SET(x,y) ((x) |= (y))
#define BITMASK_CLEAR(x,y) ((x) &= (~(y)))
#define BITMASK_FLIP(x,y) ((x) ^= (y))
#define BITMASK_CHECK_ALL(x,y) (((x) & (y)) == (y))   // warning: evaluates y twice
#define BITMASK_CHECK_ANY(x,y) ((x) & (y))

vector <LL> instructions = {
  2, 4, 1, 1, 7, 5, 1, 5, 4, 3, 0, 3, 5, 5, 3, 0
};

void printbit(LL current_mask, LL start_at = 0, LL end_at = 10) {
  for (int i = start_at; i <= end_at; i++)
    cout << ((current_mask >> i) & 1);
  cout << endl;
}
vector <LL> candidates;
void dfs(LL ans, LL occupied, int pos) {

  // cout << ans << " " << occupied << " " << pos << endl;
  // printbit(ans, 0, 14);
  if (pos >= instructions.size()) {
    if ((ans >> (3 * instructions.size())) == 0) {
      candidates.pb(ans);
    }
    return;
  }
  LL curval = instructions[pos];
  for (LL b = 0; b < 8; b++) {
    //            2109 876
    //                 2   1   0
    // 000000001110101 011 111 111
    //                 XXX 111 111
    //   0000000000000 101 000 000
    //                 ^^^
    bool valid = true;
    LL nxtOccupied = occupied;
    LL nxtAns = ans;
    for (int j = 0; j < 3; j++) {
      bool curBit = BIT_CHECK(b, j);
      int kiri = 3 * pos + j;
      if (BIT_CHECK(occupied, kiri)) {
        if (curBit != BIT_CHECK(ans, kiri)) {
          valid = false;
        }
      }
      BIT_SET(nxtOccupied, kiri);
      if (curBit) BIT_SET(nxtAns, kiri);
    }
    if (valid) {
      curval = instructions[pos] ^ 4 ^ b;
      int nxtPos = 3 * pos + (b ^ 1);
      rep(j, 0, 3) {
        if (BIT_CHECK(nxtOccupied, nxtPos + j)) {
          if (BIT_CHECK(nxtAns, nxtPos + j) != BIT_CHECK(curval , j)) {
            valid = false;
          }
        }
      }
      if (valid) {
        rep(j, 0, 3) {
          BIT_SET(nxtOccupied, nxtPos);
          BIT_SET(nxtOccupied, nxtPos + 1);
          BIT_SET(nxtOccupied, nxtPos + 2);
          if (BIT_CHECK(curval, j)) {
            BIT_SET(nxtAns, nxtPos + j);
          }
        }
        // cout << "For " << pos << " Picking " << b << " " << curval << endl;
        dfs(nxtAns, nxtOccupied, pos + 1);
      }
    }
  }

}

int main() {
  dfs(0, 0, 0);
  sort(all(candidates));
  cout << candidates[0] << endl;
}

/**
2 4 -> b = a%3
4 3 -> Cur = b^4^(a>>(b^1));
0 3 -> A >>= 3;
5 5 -> Prints register Cur
3 0 -> if(A is not 0), come back beginning


2,4,1,1,7,5,1,5,4,3,0,3,5,5,3,0

16 * 3

48 bits number

000 000 000 000 000
000 000 000 000 000
                    0
000 000 000 000 000 000
                    xxx
**/