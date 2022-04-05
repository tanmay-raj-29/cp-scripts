#include <bits/stdc++.h>
#ifdef ON_PC
    #include </Users/tanmayraj/Documents/CP/Library/Debug.h>
#else
  #define deb(x...)
#endif
using namespace std;

#define int long long
#define accuracy chrono::steady_clock::now().time_since_epoch().count()
#define rep(i,a,n) for (int i = a; i <= n; ++i)

const int N = 1e6 + 4;

int32_t permutation[N];

mt19937 rng(accuracy);

const int inf = 1e18;

int rnd(int l = -inf, int r = inf) {
  uniform_int_distribution<int> ludo(l, r); return ludo(rng);
}

using pii = pair<int,int>;

namespace generator {
  string gen_string(int len = 0, bool upperCase = false, int l = 1, int r = 26) {
    assert(len >= 0 && len <= 5e6);
    string str(len, (upperCase ? 'A' : 'a'));
    for (char &ch: str) {
      ch += rnd(l, r) - 1;
    }
    return str;
  }
  vector<int> gen_array(int len = 0, int minRange = 0, int maxRange = inf){
   assert(len >= 0 and len <= 5e6);
    vector<int> a(len);
    for (int &x: a) x = rnd(minRange, maxRange);
    return a;
  }
  vector<pair<int, int>> gen_tree(int n = 0){
    assert(n >= 0);
    vector<pii> res(n ? n - 1 : 0);
    // if you like to have bamboo like tree or star like tree uncomment below 8 lines
    /*if (rng() % 5 == 0) { // bamboo like tree
      for (int i = 1; i < n; ++i) res[i-1] = {i, i + 1};
      return res;
    }
    if (rng() % 7 == 0) { // star tree
      for (int i = 2; i <= n; ++i) res[i-2] = {1, i};
      return res;
    }*/
    iota(permutation, permutation + 1 + n, 0);
    shuffle(permutation + 1, permutation + 1 + n, rng);
    for(int i = 2; i <= n; ++i){
      int u = i, v = rnd(1 , i-1);
      u = permutation[u], v = permutation[v];
      res[i-2] = minmax(u, v); // u < v, just for convenience while debugging
    }
    shuffle(res.begin() , res.end() , rng);
    return res;
  }
  vector<pair<int, int>> simple_graph(int n = 0, int m = 0) {
    assert(n > 0 && m >= n);
    int max_edges = n * (n - 1) / 2;
    assert(m <= max_edges);
    vector<pii> res = gen_tree(n);
    set<pii> edge(res.begin(), res.end());
    for (int i = n; i <= m; ++i) {
      while (true) {
        int u = rnd(1, n), v = rnd(1, n);
        if (u == v) continue;
        auto it = edge.insert(minmax(u, v));
        if (it.second) break;
      }
    }
    res.assign(edge.begin(), edge.end());
    return res;
  }
}

using namespace generator;

template<typename T = int>
ostream& operator<< (ostream &other, const vector<T> &v) {
    for (const T &x: v) other << x << " ";
    other << endl;
    return other;
}

ostream& operator<< (ostream &other, const vector<pair<int,int>> &v) {
    for (const auto &x: v) other << x.first << ' ' << x.second << '\n';
    return other;
}

// complete this function according to the requirements
void generate_test() {
  cout << "1\n";
  int L = rnd(0, 10), R = rnd(L, L + 100);
  cout << L << " " << R << "\n";
  int n = R - L + 1;
  vector<int> v(n);
  iota(v.begin(), v.end(), L);
  int x = rnd(1, 1000);
  for (int val : v) cout << (x ^ val) << " ";
  cout << "\n";
}

signed main() {
  	srand(accuracy);
  	generate_test();
	// interactor
	// cout << "OK" << endl; 
  	return 0;
}
