#include <iostream>
#include <iomanip>
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

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

double ln_sum[200010];
int m, n;
int l, u, r, d;

inline void init() {
    ln_sum[0] = 0;
    for (int i = 1; i <= 200000; ++i) {
        ln_sum[i] = ln_sum[i - 1] + log(i);
    }
}

inline double get(int x, int y) {
    // p = C(x+y-2, x-1) / 2^(x+y-2) = (x+y-2)! / (x-1)! / (y-1)! / 2^(x+y-2)
    // use ln p instead
    return ln_sum[x + y - 2] - ln_sum[x - 1] - ln_sum[y - 1] - log(2) * (x + y - 2);
}

inline double getProbability(int x, int y) {
    if (x == m) {
        double ret = 0.;
        for (int yt = y; yt >= 1; --yt) {
            ret += exp(get(x + y - yt, yt));
        }
        return ret;
    }
    else if (y == n) {
        double ret = 0.;
        for (int xt = x; xt >= 1; --xt) {
            ret += exp(get(xt, x + y - xt));
        }
        return ret;
    }
    else {
        return exp(get(x, y));
    }
}

inline void work() {
    cin >> m >> n >> l >> u >> r >> d;
    if (m == 1 || n == 1) {
        cout << "0.0\n";
        return;
    }

    double ans = 1.;
    if (l != 1) {
        for (int i = u; i <= d; ++i) {
            double p = getProbability(l - 1, i);
            ans -= (i == n ? p : p / 2.);
        }
    }
    if (u != 1) {
        for (int i = l; i <= r; ++i) {
            double p = getProbability(i, u - 1);
            ans -= (i == m ? p : p / 2.);
        }
    }

    cout << setprecision(10) << ans << "\n";
}

int main() {
    // freopen("D.txt", "r", stdin);
    quickread();
    init();
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_) {
        cout << "Case #" << _ << ": ";
        work();
    }
    return 0;
}