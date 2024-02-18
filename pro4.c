//Simulate the working of distance vector routing algorithm using Bellman-Ford’s algorithm

#include <stdio.h>
#include <stdbool.h>

#define INF 1000000000

int main() {
    int n, e;
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &e);

    int edges[e][3];

    int source = 0;
    for (int i = 0; i < e; i++) {
        int u, v, cost;
        printf("Enter u, v, and cost between u and v: ");
        scanf("%d %d %d", &u, &v, &cost);
        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = cost;
    }

    printf("Enter Source: ");
    scanf("%d", &source);

    int ans[n];
    for (int i = 0; i < n; i++) {
        ans[i] = INF;
    }
    ans[source] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < e; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int c = edges[j][2];
            if (ans[u] != INF && ans[u] + c < ans[v]) {
                ans[v] = ans[u] + c;
            }
        }
    }

    bool negative_cycle = false;
    for (int j = 0; j < e; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int c = edges[j][2];
        if (ans[u] != INF && ans[u] + c < ans[v]) {
            negative_cycle = true;
            break;
        }
    }

    if (negative_cycle) {
        printf("Graph contains a negative cycle\n");
    } else {
        printf("Shortest distances from source node %d:\n", source);
        for (int i = 0; i < n; i++) {
            printf("Node %d: %d\n", i, ans[i]);
        }
    }

    return 0;
}
