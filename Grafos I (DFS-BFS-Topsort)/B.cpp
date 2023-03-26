#include <bits/stdc++.h>
#define MAXN 50001
using namespace std;

vector<int> adj[MAXN];
bool vis[MAXN];
int pd[MAXN];

void dfs(int u, int p) {
    vis[u] = 1;
    pd[u] = p;
    for (int v : adj[u]) {
        if (!vis[v])
            dfs(v, u);
    }
}

int main() {
    int n, p, r1, r2;
    cin >> n >> r1 >> r2;
    r1--, r2--;
    for (size_t i = 0; i < n; i++) {
        if (i == r1) continue;
        cin >> p;
        p--;

        // arista p - i
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    // Cambio de capital, obtenemos nuevos p para cada i
    dfs(r2, -1);
    bool first = 1;
    for (size_t i = 0; i < n; i++) {
        if (i == r2) continue;
        if (first) cout << pd[i] + 1, first = 0;
        else cout << " " << pd[i] + 1;
    }
}