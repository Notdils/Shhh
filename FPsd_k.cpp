#include<bits/stdc++.h>

using namespace std;

/* Pragmaaa */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

/*  Primitive Data   */
#define ll long long
#define db double

/*  Pair Macro */
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

/*  All Rounder  */
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


/* stuff you should look for

	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH (TRY DP INSTEAD OF GREEDY AND VICE VERSA)(DONT FORGET SORTING)
	* TRY ALL STRATEGIES
	* DO NOT READ EDITORIALS BEFORE TRYING REALLY HARD!
	* careful references in recursion
	* careful copying when doing vectors esp in loops and functions
	* careful long long int and mod always OMG
	* careful return types of std such as int(ceil)
	* WATCH OUT GOING OVER MAX thru operations spam mod
	* vectors overflow arrays do NOT
	* cout endl lol
	* lower bound is first greater or equal
	* upper is first greater
	* if TLE play around with compiler
	* use static is helpful!!
	* take note of test stuff that need to be changed before submission
	* careful when u use garbage from abroad
	* careful modeling stuff as num going below 0 above n
	* number theory infinite due to multple of each other
	* careful not finding stuff in dictionaries
	* stupid cout precision and sci notations
	* in sets, rbegin() or --end() for last
	* careful multiset removal just use heapp
	* no segment trees if partial mins are needed, use sparse table
	* in combinatorics log matters esp in that dp, and think v carefully
	* NEVER INPUT DOUBLES
	* fraction class or multiplication tricks?
	* omg dont forget to flush when debugging
	* watch out for bitwise operations order of operations
	* PQ Greater top is smallest and Less top is largest
	* IF MOD JUST MINUS IF NOT MUCH INCREASE
	* IF MOD REQUIRED THEN USE CONST LL
*/   





void solve(){
	
	ll n;
	cin >> n;
	ll sz[n+9];
	map<string,ll> mpV;
	map<string,ll> idxv;
	map<string,ll> pulauv;
	vector<string> V;
	vector<string> v[n+9];
	
	string s;
	forn(i,n){
		sz[i] = 0;
		cin >> s;
		V.pb(s);
		mpV[s] = i;
		string g;
		ll idxx = 1;
		while(cin >> g){
			if(g == "end")break;
			v[i].pb(g);
			pulauv[g] = i;
			idxv[g] = idxx;
			idxx++;
		}
		sz[i] = idxx-1;
		
	}
	
	ll q;
	cin >> q;
	forn(qq,q){
		string a,b;
		ll c;
		cin >> a >> b >> c;
		ll pa,pb,idxa,idxb;
		pa = pulauv[a];
		pb = pulauv[b];
		idxa = idxv[a];
		idxb = idxv[b];
		
		ll isledist = min(abs(pa-pb),n-abs(pa-pb));
		ll dista1 = min(abs(idxa-1),sz[pa] - abs(idxa-1));
		ll distb1 = min(abs(idxb-1),sz[pb] - abs(idxb-1));
		ll dist;
		if(pa == pb){
			dist = min(abs(idxa-idxb),sz[pa] - abs(idxa-idxb));
			
		}else{
			dist = isledist + dista1 + distb1 + 2;
			
		}
		if(c > dist)cout << "Connected on " << dist << " second" << nl;
		else {
			cout << "Signal lost" << nl;
		}
	}
	
}






int main(){
	int t = 1;
//	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}          

             