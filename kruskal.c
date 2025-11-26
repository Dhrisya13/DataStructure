#include <stdio.h>

int i, j, u, v,rv,ru,n, ne = 1;
int min, mincost = 0;
int cost[10][10], parent[10];

//find the set reference
int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}
//union of two sets
void union_sets(int i, int j) {
    if (i != j)
        parent[j] = i;
}

int main() {

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;//if no of edge ,its weihht is infinite  
        }
    }

    printf("The edges of the Minimum Cost Spanning Tree are:\n");

    while (ne < n) {
        min = 999;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        ru = find(u);
        rv = find(v);

        if (ru != rv) {
            union_sets(ru, rv);
            printf("%d edge (%d, %d) = %d\n", ne++, u, v, min);
            mincost += min;
        }

        cost[u][v] = cost[v][u] = 999;
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}

