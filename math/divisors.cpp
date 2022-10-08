const int N = 2001 ;

vector<int> divisors[N] ;

void cal_divisors() {
    for (int i = 1 ; i <= N - 1 ; i++) {
        int bound = sqrt(i) ;
        for (int j = 1 ; j <= bound ; j++) {
            if (i % j == 0) {
                if (j * j == i)
                    divisors[i].push_back(j) ;
                else {
                    divisors[i].push_back(j) ;
                    divisors[i].push_back(i / j) ;
                }
            }
        }
    }
}
