

vll primes(1e6 + 1, 1) ;
vll prime;// stores prime numbers

void sieve() {

    primes[0] = primes[1] = 0 ;

    for (int i = 2; i * i <= 1e6; i++) {

        if (primes[i]) {
            prime.push_back(i);
            for (int j = i * i ; j <= 1e6 ; j += i)
                primes[j] = 0;
        }

    }

    for (int i = 1e3 + 1; i <= 1e6; i++) {
        if (primes[i])
            prime.push_back(i);
    }
}

// return vector of pair i.e.  { PrimeFactor , How many times it came in number n }  
vpll getPrimeFactorsWithPower(ll n) {

    vpll v ;

    ll nn = n ;

    for (int i = 0 ; i < prime.size() and prime[i]*prime[i] <= nn ; i++) {

        int ct = 0 ;

        while (n % prime[i] == 0) {
            n /= prime[i];
            ct++;
        }
        if (ct > 0) v.pb({prime[i], ct});
    }

    if (n > 1) v.pb({n, 1});

    return v ;
}
