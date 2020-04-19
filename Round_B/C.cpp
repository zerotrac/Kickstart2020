#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <random>
#include <chrono>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLL = pair<LL, LL>;
// const int mod = 1e9 + 7;
// const int mod = 998244353;
const int mod = 1000000000;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

string st;
int pos;

inline void update(int& x, int y) {
    x += y;
    if (x < 0) {
        x += mod;
    }
    else if (x >= mod) {
        x -= mod;
    }
}

pair<int, int> dfs() {
    int u = 0, v = 0;
    while (pos < st.size()) {
        char ch = st[pos];
        ++pos;
        if (ch == 'N') {
            update(v, -1);
        }
        else if (ch == 'S') {
            update(v, 1);
        }
        else if (ch == 'W') {
            update(u, -1);
        }
        else if (ch == 'E') {
            update(u, 1);
        }
        else if (ch == ')') {
            return {u, v};
        }
        else {
            int eff = ch - 48;
            ++pos;
            auto nxt = dfs();
            update(u, (LL)eff * nxt.first % mod);
            update(v, (LL)eff * nxt.second % mod);
        }
    }
    return {u, v};
}

inline void work() {
    cin >> st;
    pos = 0;
    auto ans = dfs();
    cout << ans.first + 1 << " " << ans.second + 1 << "\n";
}

int main() {
    freopen("C.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_) {
        cout << "Case #" << _ << ": ";
        work();
    }
    return 0;
}