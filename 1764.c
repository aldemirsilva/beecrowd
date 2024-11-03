#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UGraph Graph
#define UGRAPHinit GRAPHinit

typedef struct node *link;

struct node {
  int w;
  int c;
  link next;
};

struct graph {
  int V;
  int A;
  link *adj;
};

typedef struct graph *Graph;

typedef struct {
  int v, w;
  int c;
  link next;
} edge;

static int ch[40000];
static int sz[40000];
static edge mst[40000];
static edge e[40000];

static link NEWnode(int w, link l, int c) {
  link a = (link) malloc(sizeof(struct node));
  a->w = w;
  a->c = c;
  a->next = l;
  return a;
}

Graph GRAPHinit(int V) {
  Graph G = (Graph) malloc(sizeof(G));
  G->V = V;
  G->A = 0;
  G->adj = (link *) malloc(V * sizeof(link));
  for (int v = 0; v < V; v++)
    G->adj[v] = NULL;
  return G;
}

void UGRAPHinsertEdge(Graph G, int v, int w, int c) {
  for (link a = G->adj[v]; a != NULL; a = a->next)
    if (a->w == w) return;
  G->adj[v] = NEWnode(w, G->adj[v], c);
  G->adj[w] = NEWnode(v, G->adj[w], c);
  G->A += 2;
}

static edge EDGE(int v, int w, int c) {
  edge e;
  e.v = v, e.w = w;
  e.c = c;
  return e;
}


void GRAPHshow(Graph G) {
  if (G->adj != NULL) {
    for (int i = 0; i < G->V; i++) {
      printf("%d: ", i);
      for (link current = G->adj[i]; current != NULL; current = current->next)
        printf("%2d.%2d ", current->w, current->c);
      printf("\n");
    }
  }
}

void GRAPHdestroy(Graph G) {
  link current = NULL, next = NULL;
  for (int i = 0; i < G->V; i++) {
    current = G->adj[i];
    while (current != NULL) {
      next = current->next;
      free(current);
      current = next;
    }
  }
  free(G->adj);
  free(G);
}

void UFinit(int V) {
  for (int v = 0; v < V; ++v) {
    ch[v] = v;
    sz[v] = 1;
  }
}

int UFfind(int v) {
  int v0 = v;
  while (v0 != ch[v0])
    v0 = ch[v0];
  return v0;
}

void UFunion(int v0, int w0) {
  if (sz[v0] < sz[w0]) {
    ch[v0] = w0;
    sz[w0] += sz[v0];
  } else {
    ch[w0] = v0;
    sz[v0] += sz[w0];
  }
}

int __compare(const void *a, const void *b) {
  edge l = *(edge *) a;
  edge r = *(edge *) b;
  return l.c - r.c;
}

static void UGRAPHedges(UGraph G, edge e[]) {
  int i = 0;
  for (int v = 0; v < G->V; ++v)
    for (link a = G->adj[v]; a != NULL; a = a->next)
      if (v < a->w)
        e[i++] = EDGE(v, a->w, a->c);
}


int UGRAPHmstK1(UGraph G, edge mst[]) {
  int soma = 0;

  UGRAPHedges(G, e);
  const int E = G->A / 2;
  qsort(e, E, sizeof(edge), __compare);

  UFinit(G->V);
  int k = 0;
  for (int i = 0; k < G->V - 1; ++i) {
    int v0 = UFfind(e[i].v);
    int w0 = UFfind(e[i].w);
    if (v0 != w0) {
      UFunion(v0, w0);
      mst[k++] = e[i];
      soma += mst[k - 1].c;
    }
  }
  return soma;
}


int main() {
  int m, n, u, v, w;
  while (scanf("%d %d", &m, &n), m && n) {
    Graph G = GRAPHinit(m);
    for (size_t i = 0; i < n; i++) {
      scanf("%d %d %d", &u, &v, &w);
      UGRAPHinsertEdge(G, u, v, w);
    }
    printf("%d\n", UGRAPHmstK1(G, mst));
    GRAPHdestroy(G);
  }
  return 0;
}