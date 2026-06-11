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

    size_t firstone = s.find('1');
    
    if (firstone != string::npos) {
        return s.substr(firstone);
    }
    return "0";
}

ll bintodec(string s) {
    return stoll(s, nullptr, 2);
}

template<typename T>
T maxs(T val) {
    return val;
}
template<typename T, typename... Args>
auto maxs(T first, Args... args) {
    return std::max(first, maxs(args...));
}

template<typename T>
T mins(T val) {
    return val;
}
template<typename T, typename... Args>
auto mins(T first, Args... args) {
    return std::min(first, mins(args...));
}

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

ll tambah(ll a, ll b){
    return (a+b)%MOD;
}

ll kurang(ll a, ll b){
    return (((a - b) % MOD) + MOD) % MOD;
}

ll mul(ll a, ll b){
    return ((a%MOD) * (b%MOD))%MOD;
}

#define debugl cout<<"Here\n"
#define debug(awok) cout<<(awok)<<endl
#define dar(a) for(auto amogus : a)cout << amogus << ' '; cout << nl;

int n, d;
vi adj[2005];
int downdp[2005][2005];
int updp[2005][2005];
ll pairs[2005][2005];
int sz[2005];
ll ans;

void dfs1(int u, int p) {
    downdp[u][0] = 1;
    sz[u] = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u);

        for (int i = 0; i <= min(d - 1, 2 * sz[u]); ++i) {
            if (pairs[u][i] == 0) continue;
            int req = (d - 1) - i - 1;
            if (req >= 0 && req <= sz[v]) {
                ans += pairs[u][i] * downdp[v][req];
            }
        }

        for (int i = 0; i <= min(d - 1, sz[u]); ++i) {
            if (downdp[u][i] == 0) continue;
            for (int j = 0; j <= min(d - 1 - i - 1, sz[v]); ++j) {
                if (downdp[v][j] == 0) continue;
                pairs[u][i + j + 1] += 1LL * downdp[u][i] * downdp[v][j];
            }
        }

        for (int j = 0; j <= min(d - 2, sz[v]); ++j) {
            downdp[u][j + 1] += downdp[v][j];
        }
        sz[u] = max(sz[u], sz[v] + 1);
    }
}

void dfs2(int u, int p) {
    for (int i = 0; i <= min(d - 1, 2 * sz[u]); ++i) {
        if (pairs[u][i] == 0) continue;
        int req = (d - 1) - i;
        if (req >= 0 && req <= d - 1) {
            ans += pairs[u][i] * updp[u][req];
        }
    }

    for (int v : adj[u]) {
        if (v == p) continue;
        for (int i = 1; i <= d - 1; ++i) {
            updp[v][i] = updp[u][i - 1] + downdp[u][i - 1];
            if (i >= 2) {
                updp[v][i] -= downdp[v][i - 2];
            }
        }
        dfs2(v, u);
    }
}

void solve(){
    cin >> n >> d;
    forn(i, n) {
        adj[i].clear();
        sz[i] = 0;
        for0(j, n + 1) {
            downdp[i][j] = 0;
            updp[i][j] = 0;
            pairs[i][j] = 0;
        }
    }
    ans = 0;
    for0(i, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    dfs1(1, 0);
    dfs2(1, 0);
    
    cout << ans << nl;
}

int main(){
    flushmanual;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}