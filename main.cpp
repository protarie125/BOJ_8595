#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

ll n;
string s;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n >> s;
  auto ans = ll{0};
  auto oss = ostringstream{};
  auto pushed = ll{0};
  for (auto i = 0; i < n; ++i) {
    if ('0' <= s[i] && s[i] <= '9') {
      oss << s[i];
      ++pushed;
    } else {
      if (pushed <= 0) {
        continue;
      }

      auto iss = istringstream{oss.str()};
      ll u;
      iss >> u;
      // cout << "u = " << u << endl;
      ans += u;

      oss = ostringstream{};
      pushed = 0;
    }
  }

  if (0 < pushed) {
    auto iss = istringstream{oss.str()};
    ll u;
    iss >> u;
    // cout << "u = " << u << endl;
    ans += u;
  }

  cout << ans;

  return 0;
}