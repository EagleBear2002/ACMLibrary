//Baby Step Giant Step 
//a ^ x == b (mod p)
//a and p relatively-prime 
int BSGS(int a, int b, int p) {
	std::map<int, int> hash;
	a %= p, b %= p;
	int t = std::ceil(std::sqrt(p));
	
	for(int r = 0; r < t; ++r) {
		int key = b * 1LL * Power(a, r, p) % p;
		hash[key] = r;
	}
	
	if(!a) return b == 0 ? 1 : -1;
	for(int k = 0; k <= t; ++k) {
		int key = Power(a, t*k, p);
		int r = -1;
		if(hash.count(key)) r = hash[key];
		if(r >= 0 && t * k - r >= 0) return t * k - r;
	}
	return -1;
}
