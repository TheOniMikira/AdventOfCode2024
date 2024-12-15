/*
Author : Mikira
Sat 14 Dec 2024 07:45:03 PM HKT
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
/**
Button A: X+94, Y+34
Button B: X+22, Y+67
Prize: X=8400, Y=5400

Button A: X+26, Y+66
Button B: X+67, Y+21
Prize: X=12748, Y=12176

Button A: X+17, Y+86
Button B: X+84, Y+37
Prize: X=7870, Y=6450

Button A: X+69, Y+23
Button B: X+27, Y+71
Prize: X=18641, Y=10279
**/

vector<vector<string>> goMatch(string text, string pattern) {
  vector<vector<string>> results;
  regex regexPattern(pattern);

  // Iterator for regex matches
  sregex_iterator iter(text.begin(), text.end(), regexPattern);
  sregex_iterator end;

  while (iter != end) {
    vector<string> match;
    smatch matchResult = *iter;

    // First element (index 0) is the full match
    // Subsequent elements are the capture groups
    for (size_t i = 0; i < matchResult.size(); i++) {
      match.push_back(matchResult[i].str());
    }

    results.push_back(match);
    ++iter;
  }

  return results;
}


LL euclid(LL a, LL b, LL &x, LL &y) {
  if (!b) return x = 1, y = 0, a;
  LL d = euclid(b, a % b, y, x);
  return y -= a/b * x, d;
}

int main() {
  string buttonA;
  LL total = 0;
  while (getline(cin, buttonA)) {
    if(buttonA[0] != 'B') continue;
    string buttonB, prize;
    getline(cin, buttonB);
    getline(cin, prize);
    string matchButton = "Button \\w: X\\+(\\d+), Y\\+(\\d+)";
    string matchPrize = "Prize: X=(\\d+), Y=(\\d+)";
    vector <vector <LL>> A(2, vector<LL>(2));
    auto matchedA = goMatch(buttonA, matchButton);
    auto matchedB = goMatch(buttonB, matchButton);
    auto matchedprize = goMatch(prize, matchPrize);
    vector <LL> b(2);
    A[0][0] = stoll(matchedA[0][1]);
    A[0][1] = stoll(matchedB[0][1]);
    A[1][0] = stoll(matchedA[0][2]);
    A[1][1] = stoll(matchedB[0][2]);
    auto oriA = A;
    b[0] = 10000000000000LL + stoll(matchedprize[0][1]);
    b[1] = 10000000000000LL + stoll(matchedprize[0][2]);
    auto oriB = b;
    // rep(i,0,2) rep(j,0,2) cout << A[i][j] << " \n"[j == 1];
    // cout << b[0] << endl;
    // cout << b[1] << endl;
    //
    // Ax = b
    // Minimize(3 * A + B)
    // Put LP solver too


    // Ax = b
    LL sameGCD = __gcd(A[0][0], A[1][0]);
    LL multiplierA = A[1][0] / sameGCD; 
    LL multiplierC = A[0][0] / sameGCD; 

    A[0][0] *= multiplierA;
    A[0][1] *= multiplierA;
    b[0] *= multiplierA;


    A[1][0] *= multiplierC;
    A[1][1] *= multiplierC;
    b[1] *= multiplierC;

    cout << A[0][0] << " " << A[0][1] << endl;
    cout << A[1][0] << " " << A[1][1] << endl;

    cout << b[0] << " " << b[1] << endl;

    LL bigB = A[0][1] - A[1][1];
    LL bigC = b[0] - b[1];
    // (bigB * y = bigC);
    LL ans = LLONG_MAX;
    if(bigB == 0) {
      assert(false);
      cout << "Case rank 1 " << endl;
      // Rank = 1
      A = oriA;
      b = oriB;
      // Solve the equation
      // A[0][0] * x + A[1][0] * y = b[0]
      // x >= 0, y >= 0
      LL x, y;
      euclid(A[0][0], A[1][0], x, y);
      if(b[0] % sameGCD != 0) continue;
      LL multiplier = b[0] / sameGCD;
      // x as small as possible
      // constant = i
      LL xMul = A[1][0] / sameGCD;
      LL yMul = A[0][0] / sameGCD;
      vector <LL> candidates;
      {
        LL possibleI = -x / xMul;
        for(int i = possibleI - 3;i <= possibleI + 3;i++) {
          candidates.pb(i);
        }
      }
      {
        LL possibleI = y / yMul;
        for(int i = possibleI - 3;i <= possibleI + 3;i++) {
          candidates.pb(i);
        }

      }
      trav(i, candidates) {
        LL possibleX = x + i * xMul;
        LL possibleY = y - i * yMul;
        possibleX *= multiplier;
        possibleY *= multiplier;
        if(possibleX >= 0 && possibleY >= 0) {
          LL cost = possibleX *   3 + possibleY;
          cost = min(cost, ans);
        }
      }
      // Minimize (3x + y)
    } else {
      // cout << "Unique " << endl;
      // Unique
      // cout << bigC << " " << bigB << endl;
      if(bigC % bigB != 0) continue;
      LL y = bigC / bigB;
      LL x = b[0] - y * A[0][1];
      if(x % A[0][0] != 0) continue;
      x /= A[0][0];
      ans = 3 * x + y;
    }
    if(ans == LLONG_MAX) continue;
    cout << ans << endl;
    total += ans;
  }
  cout << total << endl;
}