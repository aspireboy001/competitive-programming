
#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD1 998244353
#define inf 1e18
#define iinf INT_MIN
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define parity_check __builtin_parity //1=odd,0=even
#define set_bits __builtin_popcountll
#define leading_zeros __builtin_clzll //00010 = 3
#define trailing_zeros __builtin_ctzll //00010 = 1
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define vii vector<int>
#define pll pair<ll,ll>
#define vpii vector<pair<int,int>>
#define vll vector<ll>
#define eb emplace_back
#define vpll vector<pair<ll,ll>>
#define vch vector<char>
#define vvll vector<vector<ll>>
#define min_heap priority_queue <int, vector<int>, greater<int>>
#define max_heap priority_queue <int>
#define rep(var , start , end) for(int var = start ; var < end ; var++)
#define rrep(var , start , end) for(int var = start ; var >= end ; var--)
#define py cout<<"YES"<<nline
#define pn cout<<"NO"<<nline

typedef long long ll;
typedef long double lld;


/*-----------------Debug-------------------*/

#ifndef ONLINE_JUDGE
#define deb(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define deb(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*-----------------Debug-------------------*/

void solve() {

}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    int test_cases = 1 ;
    cin >> test_cases ;

    while (test_cases--) {
        solve();
    }

}
