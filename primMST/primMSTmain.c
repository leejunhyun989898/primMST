#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX 100
#define INF 1000L

typedef struct GraphType {
	int n;
	int weight[MAX][MAX];
}GraphType;

int selected[MAX];
int distance[MAX];

// 최소 거리의 정점 반환 함수
int get_min_vertex(int n)
{
	int v, i;
	// 아직 선택되지 않은 첫번째 정점 선택
	for (i = 0; i < n; i++)
	{
		if (!selected[i]) {
			v = i;
			break;
		}
	}
	// 선택되지 않은 정점들 중 최소 거리를 갖는 정점 선택
	for (i = 0; i < n; i++)
	{
		if (!selected[i] && (distance[i] < distance[v]))v = i;
	}
	return (v);
}

// prim 알고리즘 함수
void prim(GraphType* g, int s)
{
	int i, u, v;
	// distance 배열 초기화
	for (u = 0; u < g->n; u++)
		distance[u] = INF;
	distance[s] = 0;
	// 모든 정점 선택될 때까지 반복
	for (i = 0; i < g->n; i++)
	{
		// 선택되지 않은 정점들 중 최소 거리를 갖는 정점 선택
		u = get_min_vertex(g->n);
		// 선택된 정점으로 표시
		selected[u] = TRUE;
		// 선택된 정점에서 갈 수 있는 다른 정점들까지의 거리 계산
		if (distance[u] == INF) return;
		printf("정점 %d 추가\n", u);
		for (v = 0; v < g->n; v++)
		{
			if (g->weight[u][v] != INF)
				if (!selected[v] && g->weight[u][v] < distance[v])
					distance[v] = g->weight[u][v];
		}
	}
}

int main(void)
{
	GraphType g = { 6,
	{{INF,1,0,INF,INF,1},
	{3,0,1,INF,INF,2},
	{INF,2,1,7,9,0},
	{0,3,INF,2,4,INF},
	{2,4,INF,0,5,7},
	{4,INF,INF,5,0,9}}
	};
	// 시작 정점을 0으로 설정하고 prim 알고리즘 호출
	prim(&g, 0);
	return 0;
}