// author: Aldemir Silva | date: November 3rd 2024

#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;

int cnt;
int pre[100];
link head, tail;

struct node {
    int w;
    link next;
};

struct graph {
    int V;
    int A;
    link *adj;
};

typedef struct graph *Graph;

link NEWnode(int w, link l) {
    link a = malloc(sizeof(link));
    a->w = w;
    a->next = l;
    return a;
}

Graph GRAPHinit(int V) {
    Graph G = malloc(sizeof(Graph));
    G->V = V;
    G->A = 0;
    G->adj = malloc(V * sizeof(link));
    for (int v = 0; v < V; v++) {
        G->adj[v] = NULL;
    }
    return G;
}

void GRAPHinsertArc(Graph G, int v, int w) {
    for (link a = G->adj[v]; a != NULL; a = a->next) {
        if (a->w == w) {
            return;
        }
    }
    G->adj[v] = NEWnode(w, G->adj[v]);
    G->A++;
}

void GRAPHfree(Graph G) {
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

static void dfsR(Graph G, int v) {
    pre[v] = cnt++;
    for (link a = G->adj[v]; a != NULL; a = a->next) {
        int w = a->w;
        if (pre[w] == -1) {
            dfsR(G, w);
        }
    }
}

int GRAPHdfs(Graph G) {
    cnt = 0;
    for (int v = 0; v < G->V; ++v) {
        pre[v] = -1;
    }
    for (int v = 0; v < G->V; ++v) {
        if (G->adj[v] != NULL && pre[v] == -1) {
            dfsR(G, v);
        }
    }
    return (cnt - 1) * 2;
}

int main() {
    Graph G;
    int T, N, V, A, v1, v2;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        scanf("%d", &V);
        scanf("%d", &A);
        G = GRAPHinit(V);
        for (int j = 0; j < A; j++) {
            scanf("%d", &v1);
            scanf("%d", &v2);
            GRAPHinsertArc(G, v1, v2);
        }
        printf("%d\n", GRAPHdfs(G));
        GRAPHfree(G);
    }
    return 0;
}