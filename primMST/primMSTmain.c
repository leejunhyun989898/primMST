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

// �ּ� �Ÿ��� ���� ��ȯ �Լ�
int get_min_vertex(int n)
{
	int v, i;
	// ���� ���õ��� ���� ù��° ���� ����
	for (i = 0; i < n; i++)
	{
		if (!selected[i]) {
			v = i;
			break;
		}
	}
	// ���õ��� ���� ������ �� �ּ� �Ÿ��� ���� ���� ����
	for (i = 0; i < n; i++)
	{
		if (!selected[i] && (distance[i] < distance[v]))v = i;
	}
	return (v);
}

// prim �˰��� �Լ�
void prim(GraphType* g, int s)
{
	int i, u, v;
	// distance �迭 �ʱ�ȭ
	for (u = 0; u < g->n; u++)
		distance[u] = INF;
	distance[s] = 0;
	// ��� ���� ���õ� ������ �ݺ�
	for (i = 0; i < g->n; i++)
	{
		// ���õ��� ���� ������ �� �ּ� �Ÿ��� ���� ���� ����
		u = get_min_vertex(g->n);
		// ���õ� �������� ǥ��
		selected[u] = TRUE;
		// ���õ� �������� �� �� �ִ� �ٸ� ����������� �Ÿ� ���
		if (distance[u] == INF) return;
		printf("���� %d �߰�\n", u);
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
	// ���� ������ 0���� �����ϰ� prim �˰��� ȣ��
	prim(&g, 0);
	return 0;
}