/*
Author : Mikira
Tue 03 Dec 2024 08:18:53 PM HKT
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
#define endl '\n'
const int MOD = 1000000007;
// const int MOD = 998244353;
using PairLongString = pair<LL, string>;

LL computeMul(string it) {
  string matchedMul(it);
  regex pattern2("\\d+");
  sregex_iterator it2(matchedMul.begin(), matchedMul.end(), pattern2);
  LL ans = stoll(it2->str()) * stoll(next(it2)->str());
  return ans;
}

vector <PairLongString> gather(string s, regex pattern) {
  sregex_iterator it(s.begin(), s.end(), pattern);

  vector <PairLongString> allFound;
  // Method 1: Using iterator
  sregex_iterator end;
  while (it != end) {
    std::cout << "Found: " << it->str() << '\n';
    cout << it->position() << endl;
    allFound.emplace_back(it->position(), it->str());
    ++it;
  }
  return allFound;
}

int main() {
  string s;
  string line;
  while (getline(cin, line)) {
    s += line;
    s += '\n';  // add the newline back
  }
  while (getline(cin, line)) {
    line += '\n';  // add the newline back
  }
  regex pattern("mul\\(\\d+,\\d+\\)");
  regex patternDo("do\\(\\)");
  regex patternDont("don't\\(\\)");
  vector <PairLongString> gathermul = gather(s, pattern);
  vector <PairLongString> gatherDo = gather(s, patternDo);
  vector <PairLongString> gatherDont = gather(s, patternDont);
  vector <PairLongString> allFound;
  allFound.insert(allFound.end(), all(gathermul));
  allFound.insert(allFound.end(), all(gatherDo));
  allFound.insert(allFound.end(), all(gatherDont));
  sort(all(allFound));
  int n = allFound.size();
  bool abled = true;
  LL ans = 0;
  for(int i = 0;i < n;i++) {
    cout << allFound[i].fi << " " << allFound[i].se << endl;
    auto instruction = allFound[i].se.substr(0, 3);
    cout << abled << endl;
    if(instruction == "mul"){
      if(abled) ans += computeMul(allFound[i].se);
    } else if(instruction == "don") {
      abled = false;
    } else {
      abled = true;
    }
  } 
  cout << ans << endl;
}