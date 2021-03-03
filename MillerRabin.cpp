//20.10.08 
bool MillerRabin(int n) {
	if(n == 2) return true;
	if(n < 2 || (n & 1) == 0) return false;
	
	int cnt = 8;
	int k = 0, t = n-1;
	while((t & 1) == 0) ++k, t >>= 1;
	while(cnt--) {
		int s = Power(rand() % (n-1) + 1, t, n);
		for(int j = 1; j <= k; ++j) {
			int tmp = s * 1LL * s % n;
			if(s == 1 && tmp != 1 && tmp != n-1)
				return false;
			s = tmp;
		}
		if(s != 1) return false;
	}
	return true;
}
