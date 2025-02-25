struct Flow{
    const int n, s, t;
    vector<int> nxt, to, head, w, now, dep, cnt;
    int maxflow = 0;
    Flow(int n, int s, int t) : n(n), s(s), t(t), head(n + 1, -1), now(n + 1, 0), dep(n + 1, 0), cnt(n + 2, 0){
        cnt[0] = n;
    }
    void addedge(int x, int y, int v){
        nxt.push_back(head[x]);
        to.push_back(y);
        w.push_back(v);
        head[x] = nxt.size() - 1;
        now[x] = head[x];

        nxt.push_back(head[y]);
        to.push_back(x);
        w.push_back(0);
        head[y] = nxt.size() - 1;
        now[y] = head[y];
        return;
    }
    int dfs(int p, int flow){
        if(p == t){
            maxflow += flow;
            return flow;
        }
        int re = 0;
        for(; now[p] != -1; now[p] = nxt[now[p]]){
            int x = to[now[p]];
            if(!w[now[p]] || dep[x] != dep[p] - 1) continue;
            int use = dfs(x, min(w[now[p]], flow));
            w[now[p]] -= use;
            w[now[p] ^ 1] += use;
            re += use;
            flow -= use;
            if(!flow) break;
        }
        if(flow){
            cnt[dep[p]]--;
            if(!cnt[dep[p]]) dep[s] = n;
            dep[p]++;
            cnt[dep[p]]++;
            now[p] = head[p];
        }
        return re;
    }
    int run(){
        while(dep[s] < n) dfs(s, INF);
        return maxflow;
    }
};
