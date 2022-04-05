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
    int l, r;
    cin >> l >> r;
    int n = r - l + 1;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x;
    cin >> x;
    for (int& v : a) {
        v ^= x;
    }
    sort(a.begin(), a.end());
    for (int i = 0, j = l; i < n; i++, j++) {
        if (a[i] != j) {
            cout << "BAD" << endl;
            return;
        }
    }
    cout << "OK" << endl;
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