int getint() {
	char ch;
	while(('9' < (ch = getchar()) || ch < '0') && ch != '-');
	bool neg = ch == '-';
	int ans = neg ? 0 : ch - '0';
	while('0' <= (ch = getchar()) && ch <= '9')
		ans = (ans << 1) + (ans << 3) + ch - '0';
	return neg ? -ans : ans;
}
