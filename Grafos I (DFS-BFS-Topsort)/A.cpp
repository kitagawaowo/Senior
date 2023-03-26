#include <bits/stdc++.h>
#define MAXN 101
using namespace std;

int M[MAXN][MAXN], dishes = 0;
bool vis[MAXN][MAXN];
int R, C;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void dfs(int x, int y) {
	dishes++;
	vis[x][y] = 1;
	for (size_t i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < R && ny >= 0 && ny < C &&
			!vis[nx][ny] && M[nx][ny] > M[x][y])
			dfs(nx, ny);
	}
}
void clean() {
	for (size_t i = 0; i < R; i++) {
		for (size_t j = 0; j < C; j++) {
			vis[i][j] = 0;
		}
	}
}
int main() {
	cin >> R >> C;
	for (size_t i = 0; i < R; i++) {
		for (size_t j = 0; j < C; j++) {
			cin >> M[i][j];
		}
	}

	int max_dishes = 0;
	for (size_t i = 0; i < R; i++) {
		for (size_t j = 0; j < C; j++) {
			clean();
			dishes = 0;
			dfs(i, j);
			max_dishes = max(max_dishes, dishes);
		}
	}

	cout << max_dishes << '\n';


	return 0;
}
