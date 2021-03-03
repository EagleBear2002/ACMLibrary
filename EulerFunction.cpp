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
