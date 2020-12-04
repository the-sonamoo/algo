
void dfs(int here) {
    visited[here] = 1;
    for (int i = 0; i < v[here].size(); i++) {
        int next = v[here][i];
        if (visited[next]) continue;
        dfs(next);
    }
    st.push(here);
}

void rdfs(int here) {
    visited[here] = 1;
    scc[idx].push_back(here);
    for (int i = 0; i < rv[here].size(); i++) {
        int next = rv[here][i];
        if (visited[next]) continue;
        rdfs(next);
    }
}

void scc() {
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        dfs(i);
    }

    memset(visited , 0 , sizeof(visited));
    while(!st.empty()) {
        int x = st.top();
        st.pop();
        if (visited[x]) continue;
        idx++;
        rdfs(x);
    }
}
