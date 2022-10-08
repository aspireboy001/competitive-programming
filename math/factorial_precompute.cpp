// MOD = 1e9+7
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

const int N = 200005 ;

ll *fact = new ll[N];
ll *ifact = new ll[N];

void factorial() {
    fact[0] = 1, ifact[0] = 1;
    for (ll i = 1; i <= N; i++) {
        fact[i] = mod_mul(fact[i - 1], i, MOD);
        ifact[i] = mminvprime(fact[i], MOD);
    }
}
