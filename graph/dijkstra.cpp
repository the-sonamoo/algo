void dijkstra(int s) {
    pq.push({0 , s});
    dist[s] = 0;

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost) continue;

        for (auto next : graph[here]) {
            int there = next.first;
            int nCost = next.second+cost;

            if (dist[there] > nCost) {
                dist[there] = nCost;
                pq.push({-nCost , there});
            }
        }
    }
}
