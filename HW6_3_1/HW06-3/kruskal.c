#include <stdio.h>
#include "minheap.h"
#include "unionfind.h"

#define MAX_VERTICES 100
#define INF 9999

typedef struct GraphType {
	int n;					// ������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// �׷��� �ʱ�ȭ 
void graph_init(GraphType *g)
{
	int r,c;
	g->n=0;
	for(r=0;r<MAX_VERTICES;r++)
		for(c=0;c<MAX_VERTICES;c++)
			g->adj_mat[r][c]=INF;
}

/*  */
void read_graph(GraphType *g, char *filename)
{
     int number, u, v, weight;
	 char ch;
     FILE *fp;
     fp = fopen(filename, "rt");
	if (fp == NULL) 
	{
		printf("file %s open error!\n", filename);
		return;
	}
     
	fscanf(fp, "%d\n", &number);
	g->n = number;
	while(fscanf(fp, "%d %d %d\n", &u, &v, &weight) != EOF)
	{
		g->adj_mat[u][v] = weight;
		g->adj_mat[v][u] = weight;
	}

    fclose(fp);
}

/*  */
void write_graph(GraphType *g, char *filename)
{
     int i, j;
     FILE *fp;
     
     if (filename == NULL) fp = stdout;
     else {
         fp = fopen(filename, "wt");
	     if (fp == NULL) 
	     {
		     printf("file %s open error!\n", filename);
	         return;
	     }
     }

     fprintf(fp, "%d\n", g->n);
	 for(i = 0; i < g->n; i++)
		 for(j = i; j < g->n; j++)
			if(g->adj_mat[i][j] != INF)
				fprintf(fp, "%d %d %d\n", i, j, g->adj_mat[i][j]);

     if (filename != NULL) fclose(fp);
}

// ���� ����̳� ���� ����Ʈ���� �������� �о �ּ� ������ ���� 
// ����� ���� �׷����� �������� �����Ѵ�.
void insert_all_edges(HeapType *h, GraphType *g)
{
	 int i, j;
     element e;

	 for(i = 0; i < g->n; i++)
		 for(j = i; j < g->n; j++)
			if(g->adj_mat[i][j] != INF) {
				e.u = i;
				e.v = j;
				e.key = g->adj_mat[i][j];
				insert_min_heap(h, e);
			}
}

// kruskal�� �ּ� ��� ���� Ʈ�� ���α׷�
void kruskal(GraphType *g, GraphType *t)
{
     int edge_accepted = 0;
	 HeapType h;
	 int uset, vset;
	 element e;
	 int n = g->n;

	 init(&h);
	 insert_all_edges(&h, g);
	 set_init(n);
	 while( edge_accepted < (n-1) )
	 {
		 e = delete_min_heap(&h);
		 uset = set_find(e.u);
		 vset = set_find(e.v);
		 if( uset != vset ) {
			 printf("(%d %d) %d\n", e.u, e.v, e.key);
			 t->adj_mat[e.u][e.v] = e.key;
			 edge_accepted++;
			 set_union(uset, vset);
		 }
	 }
}

void main()
{
	GraphType g, t;		// �Է� �׷���, ��� Ʈ��
	
	graph_init(&g);
	read_graph(&g, "input.txt");

	graph_init(&t);
	t.n = g.n;
	
	printf("���õ� ����(�������):\n");
	kruskal(&g, &t);
	printf("\n");

    printf("���Ϸ� ���:\n");
	write_graph(&t, "output.txt");	
	write_graph(&t, NULL);	// to stdout
}
