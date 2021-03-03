void Gauss(double a[][MAXN], int n) {
	for(int i = 1; i <= n; ++i) {
		int r = i;
		for(int j = i+1; j <= n; ++j)
			if(fabs(a[j][i]) > fabs(a[r][i])) r = j;
		for(int j = 1; j <= n+1; ++j)
			std::swap(a[i][j], a[r][j]);
		for(int j = 1; j <= n; ++j) if(j != i) {
			double rate = a[j][i] / a[i][i];
			for(int k = i; k <= n+1; ++k)
				a[j][k] -= a[i][k] * rate;
		}
	}
	for(int i = 1; i <= n; ++i)
		a[i][n+1] /= a[i][i];
}
