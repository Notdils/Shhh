#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define ll long long
#define db double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define sc second
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define ppb pop_back()
#define pf push_front
#define ppf pop_front()
#define all(x) x.begin(),x.end()
#define forn(i,n) for(long long i = 1; i<= n; i++)
#define for0(i,n) for(long long i = 0; i < n; i++)

#define INF 1e9 
#define LLINF 1e18
#define nl '\n'
#define tab '\t'
#define cesp ' '

#define flushmanual ios_base::sync_with_stdio(false); cin.tie(NULL)

ll binpow(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod; 
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

string dectobin(ll n) {
    if (n == 0) return "0";
    string s = bitset<64>(n).to_string();
    size_t first_one = s.find('1');
    if (first_one != string::npos) return s.substr(first_one);
    return "0";
}

ll bintodec(string s) {
    return stoll(s, nullptr, 2);
}

template<typename T> T maxs(T val) { return val; }
template<typename T, typename... Args> auto maxs(T first, Args... args) { return std::max(first, maxs(args...)); }
template<typename T> T mins(T val) { return val; }
template<typename T, typename... Args> auto mins(T first, Args... args) { return std::min(first, mins(args...)); }

template<typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2>& p) {
    is >> p.first >> p.second;
    return is;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    os << "{" << p.first << " " << p.second << "}";
    return os;
}

const ll MOD = 1e9+7;
ll tambah(ll a, ll b){ return (a+b)%MOD; }
ll kurang(ll a, ll b){ return (((a - b) % MOD) + MOD) % MOD; }
ll mul(ll a, ll b){ return ((a%MOD) * (b%MOD))%MOD; }

#define debugl cout<<"Here\n"
#define debug(awok) cout<<(awok)<<endl
#define dar(a) for(auto amogus : a)cout << amogus << ' '; cout << nl;

int up[200005][19], d[200005];

int lca(int u, int v) {
    if(d[u] < d[v]) swap(u, v);
    int df = d[u] - d[v];
    for0(j, 19) if((df >> j) & 1) u = up[u][j];
    if(u == v) return u;
    for(int j = 18; j >= 0; j--) if(up[u][j] != up[v][j]) u = up[u][j], v = up[v][j];
    return up[u][0];
}

void solve(){
    int n, q;
    if(!(cin >> n >> q)) return;
    d[1] = 0;
    for0(j, 19) up[1][j] = 1;
    forn(i, n - 1) {
        int u = i + 1, p;
        cin >> p;
        up[u][0] = p;
        d[u] = d[p] + 1;
        forn(j, 18) up[u][j] = up[up[u][j-1]][j-1];
    }
    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << nl;
    }
}

int main(){
    flushmanual;
    int t = 1;
    while(t--) solve();
    return 0;
}