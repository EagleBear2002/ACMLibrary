//untested
int dist[MAXN];
void SPFA(int s) {
	memset(dist, 0x3f, sizeof dist);
	std::queue<int> que;
	dist[s] = 0, que.push(s);
	while(!que.empty()) {
		int u = que.front();
		que.pop();
		for(Edge* edg = head[u]; edg; edg = edg->nxt) {
			int v = edg->to;
			if(dist[v] > dist[u] + edg->dist)
				dist[v] = dist[u] + edg->dist, que.push(v);
		}
	}
}
