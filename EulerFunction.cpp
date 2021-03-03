int Euler(int n) {
	int ans = n;
	for(int i = 1; prime[i] <= n; ++i) {
		int p = prime[i];
		if(n % p == 0) {
			while(n % p == 0) n /= p;
			ans = ans / p * (p-1);
		}
	}
	return ans;
}

//20.10.14
int phi[MAXN];
void EulerSieve(int n) {
	phi[1] = 1;
	for(int i = 2; i <= n; ++i) if(!phi[i])
		for(int j = i; j <= n; j += i) {
			if(!phi[j]) phi[j] = j;
			phi[j] = phi[j] * (i-1) / i;
		}
}
