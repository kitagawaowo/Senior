#include <bits/stdc++.h>
#define MAXN 2001
using namespace std;
int pd[MAXN], max_nivel = 0;
vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int u, int niv) {
    vis[u] = 1;
    max_nivel = max(max_nivel, niv);
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v, niv + 1);
    }
}
int main() {
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        cin >> pd[i];
        pd[i]--;
        if (pd[i] >= 0) adj[pd[i]].push_back(i);
    }
    int comp = 0;
    for (size_t i = 0; i < n; i++) {
        if (pd[i] == -2) {
            dfs(i, 1);
            comp++;
        }
    }
    cout << max_nivel << '\n';
}