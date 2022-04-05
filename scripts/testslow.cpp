#include <bits/stdc++.h>
#ifdef ON_PC
    #include </Users/tanmayraj/Documents/CP/Library/Debug.h>
#else
  #define deb(x...)
#endif
using namespace std;
// =================

const int MOD = 1e9 + 7;
const int N = 3e5 + 5;
const long long INF = 2e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    vector<long long> sum(n + m - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            sum[i + j] += v[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == n - 1 && j == m - 1) continue;
            int total = 0;
            if (i + 1 < n) total += v[i + 1][j];
            if (j + 1 < m) total += v[i][j + 1];
            if (v[i][j] > total) {
                cout << "NO\n";
                return;
            }
        }
    }
    for (int i = 1; i < m + n - 1; i++) {
        if (sum[i] != sum[i - 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TEST = 1;
    cin >> TEST;
    for (int i = 1; i <= TEST; i++) {
        // cout << "Case #" << i << ": ";
        solve();
        #ifdef ON_PC
            cout << "__________________________\n";
        #endif
    }
    #ifdef ON_PC
        cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}
