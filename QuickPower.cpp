int Power(int a, int k, int MOD) {
	int ans = 1;
	while(k) {
		if(k & 1) ans = ans * 1LL * a %MOD;
		a = a * 1LL * a % MOD, k >>= 1;
	}
	return ans;
}
