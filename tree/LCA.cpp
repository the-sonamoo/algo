void maketree(int now) {
    for (int i = 0; i < graph[now].size(); i++) {
        int next = graph[now][i];
        if (depth[next] == 0) {
            depth[next] = depth[now]+1;
            parent[next][0] = now;
            maketree(next);
        }
    }
}

void sparse() {
    for (int j = 1; j < logMAX; j++) {
        for (int i = 1; i <= n; i++) {
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }
}

int LCA(int u , int v) {
    if (depth[u] < depth[v]) swap(u , v);
    int diff = depth[u]-depth[v] , k = 0;

    while(diff) {
        if (diff%2 == 1) u = parent[u][k];
        diff /= 2;
        k++;
    }

    if (u != v) {
        for (int k = logMAX-1; k >= 0; k--) {
            if (parent[u][k] != 0 && parent[u][k] != parent[v][k]) {
                u = parent[u][k];
                v = parent[v][k];
            }
        }
        u = parent[u][0];
    }

    return u;
}
