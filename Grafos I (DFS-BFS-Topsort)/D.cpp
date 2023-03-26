#include <bits/stdc++.h>
#define N 1000001
using namespace std;

int in_deg[N];
int n, m;
vector<int> adj[N], top_sort;

bool kahn() { // O(V + E)
    deque<int> Q;
    for (int i = 0; i < n; i++) {
        if (in_deg[i] == 0) Q.push_back(i);
    }

    while (!Q.empty()) {
        int u = Q.front();
        top_sort.push_back(u);
        Q.pop_front();
        for (int v : adj[u]) {
            in_deg[v]--;
            if (in_deg[v] == 0) Q.push_back(v);
        }
    }
    return (top_sort.size() == n);
}

void clean() {
    top_sort.clear();
    for (int i = 0; i < n ;i++) {
        adj[i].clear();
        in_deg[i] = 0;
    }

}
int main() {
    while (cin >> n >> m) {
        int u, v;
        if (n == 0 && m == 0) break;
        clean();
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            u--, v--;
            in_deg[v]++;
            adj[u].push_back(v);
        }

        if(kahn()) {
            for (auto a : top_sort)
                cout << a + 1 << '\n';

        } else cout << "IMPOSSIBLE\n";
    }
}