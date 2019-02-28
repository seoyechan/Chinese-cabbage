#include <stdio.h>
#include <queue>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int nfiled[51][51];
int nRet, n, m, k;

typedef struct pos{
	int x, y;
};

pos position;
pos next_pos;

queue <pos> bfs_q;

const int dirx[] = { 0, 0, 1, -1 };
const int diry[] = { 1, -1, 0, 0 };

void bfs(int x, int y)
{
	bfs_q.push({ x, y });
	nfiled[y][x] = 0;

	while (!bfs_q.empty())
	{
		position = bfs_q.front();
		bfs_q.pop();

		for (int i = 0; i < 4; i++){
			next_pos.x = position.x + dirx[i];
			next_pos.y = position.y + diry[i];

			if (next_pos.x >= 0 && next_pos.y >= 0 && next_pos.x < m && next_pos.y < n
				&& nfiled[next_pos.y][next_pos.x]){
				bfs_q.push(next_pos);
				nfiled[next_pos.y][next_pos.x] = 0;
			}
		}
	}
	nRet++;
}

void dfs(int crtx, int crty)
{
	nfiled[crty][crtx] = 0;

	for (int i = 0; i < 4; i++){
		next_pos.x = crtx + dirx[i];
		next_pos.y = crty + diry[i];

		if (next_pos.x >= 0 && next_pos.y >= 0 && next_pos.x < m && next_pos.y < n
			&& nfiled[next_pos.y][next_pos.x]){
			dfs(next_pos.x, next_pos.y);
		}
	}
}


int main()
{
	int t;
	int test_case;

	freopen("sample_input.txt", "r", stdin);
	scanf("%d", &t);

	for (test_case = 1; test_case <= t; ++test_case)
	{
		scanf("%d %d %d", &m, &n, &k);

		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				nfiled[i][j] = 0;
			}
		}
		
		for (int i = 0; i < k; i++){
			scanf("%d %d", &position.x, &position.y);
			nfiled[position.y][position.x] = 1;
		}

		nRet = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (nfiled[i][j] == 1){
					bfs(j,i);
					//dfs(j, i);
					//nRet++;
				}
			}
		}

		printf("%d\n", nRet);
	}

	return 0;
}