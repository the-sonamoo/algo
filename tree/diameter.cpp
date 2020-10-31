parent[1] = 1;
dfs(1);

for (int i = 2; i <= n; i++) {
  if (dist[i] > res1) {
    res1 = dist[i];
    res2 = i;
  }
}

memset(dist , 0 , sizeof(dist));
memset(parent , 0 , sizeof(parent));

parent[res2] = 1;
dfs(res2);

for (int i = 1; i <= n; i++) ans = max(ans , dist[i]);
