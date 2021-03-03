//20.11.04
//print bits of a data
void printbyte(char ch)  {
	int n = ch;
	for(int i = 7; i >= 0; --i)
		printf("%d", n >> i & 1);
	putchar(' ');
}

template<typename Type>
void display(Type a) {
	char s[MAXN];
	memcpy(s, &a, sizeof a);
	
	std::cout << "display: " << a << std::endl;
	for(int i = sizeof a - 1; i >= 0; --i)
		printbyte(s[i]);
}
