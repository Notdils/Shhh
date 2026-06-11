#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

/* Pragmaaa */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

/* Primitive Data   */
#define ll long long
#define db double

/* Pair Macro */
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define sc second

/* Vector Macro */
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define ppb pop_back()
#define pf push_front
#define ppf pop_front()

/* All Rounder  */
#define all(x) x.begin(),x.end()
#define forn(i,n) for(long long i = 1; i<= n; i++)
#define for0(i,n) for(long long i = 0; i < n; i++)

#define INF 1e9 
#define LLINF 1e18
#define nl '\n'
#define tab '\t'
#define cesp ' '

// Hati-hati kalau mau ngeflush tapi endl jadi nya '\n'
#define flushmanual ios_base::sync_with_stdio(false); cin.tie(NULL)

// Templates

// Binpow

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

// Desimal to Biner

string dectobin(ll n) {
    if (n == 0) return "0";
    string s = bitset<64>(n).to_string();

    size_t first_one = s.find('1');
    
    if (first_one != string::npos) {
        return s.substr(first_one);
    }
    return "0";
}

ll bintodec(string s) {
    return stoll(s, nullptr, 2);
}


// Multiple Min
template<typename T>
T maxs(T val) {
    return val;
}
template<typename T, typename... Args>
auto maxs(T first, Args... args) {
    // std::max will handle type promotion (e.g., int and double)
    return std::max(first, maxs(args...));
}

// Multiple Max
template<typename T>
T mins(T val) {
    return val;
}
template<typename T, typename... Args>
auto mins(T first, Args... args) {
    // std::min will handle type promotion
    return std::min(first, mins(args...));
}

// Pair Input
template<typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2>& p) {
    is >> p.first >> p.second;
    return is;
}

// Pair Output
template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    os << "{" << p.first << " " << p.second << "}";
    return os;
}


/* Modulo Fuctions */
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

/* debuggin */
#define debugl cout<<"Here\n"
#define debug(awok) cout<<(awok)<<endl
#define dar(a) for(auto amogus : a)cout << amogus << ' '; cout << nl;

typedef tree<pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

map<ll, ll> mp;
ordered_set os;

void solve(){
//    cout << "new cycle"<<nl;
    string op;
    cin >> op;
    if(op == "ADD"){
        ll id, sc;
        cin >> id >> sc;
        if(mp.count(id)){
            cout << "FAIL" << nl;
        } else {
            mp[id] = sc;
            os.insert({-sc, id});
        }
    } 
    else if(op == "UPDATE"){
        ll id, sc;
        cin >> id >> sc;
        if(!mp.count(id)){
            cout << "FAIL" << nl;
        } else {
            os.erase({-mp[id], id});
            mp[id] = sc;
            os.insert({-sc, id});
        }
    } 
    else if(op == "REMOVE"){
        ll id;
        cin >> id;
        if(!mp.count(id)){
            cout << "FAIL" << nl;
        } else {
            os.erase({-mp[id], id});
            mp.erase(id);
        }
    } 
    else if(op == "RANK"){
        ll id;
        cin >> id;
        if(!mp.count(id)){
            cout << "FAIL" << nl;
        } else {
            cout << os.order_of_key({-mp[id], id}) + 1 << nl;
        }
    } 
    else if(op == "KTH"){
        ll k;
        cin >> k;
        if(k <= 0 || k > os.size()){
            cout << "INVALID" << nl;
        } else {
            auto it = os.find_by_order(k - 1);
            cout << it->sc << " " << -(it->fi) << nl;
        }
    } 
    else if(op == "MEDIAN"){
        if(os.empty()){
            cout << "EMPTY" << nl;
        } else {
            ll k = (os.size() + 1) / 2;
            auto it = os.find_by_order(k - 1);
            cout << it->sc << ' ' << -(it->fi) << nl;
        }
    }
}

int main(){
//	flushmanual;
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}