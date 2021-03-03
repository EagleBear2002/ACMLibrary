//20.10.25 
int dfn[MAXN], low[MAXN], clk = 0;
int bel_cnt[MAXN];
bool cut[MAXN];
std::stack<int> st;
void Tarjan(int u, int p)  {
	dfn[u] = low[u] = ++clk;
	if(!head[u]) return;
	
	st.push(u);
	int flag = 0;
	for(Edge* edg = head[u]; edg; edg = edg->nxt) {
		int v = edg->to;
		if(!dfn[v]) {
			Tarjan(v, u);
			low[u] = std::min(low[u], low[v]);
			if(low[v] >= dfn[u]) {
				++flag;
				if(u != p || flag > 1) cut[u] = true;
				int t;
				do t = st.top(), st.pop(), ++bel_cnt[t];
				while(t != v);
				++bel_cnt[u];
			}
		}
		else low[u] = std::min(low[u], dfn[v]);
	}
}
