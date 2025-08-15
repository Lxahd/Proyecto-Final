#include <stdio.h>
using namespace std;

int main() {
    int n, m, i, j, k;
    scanf("%d %d", &n, &m);
    int a[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                for (k = 0; k < m; k++) {
                    a[i][k] = 1;
                }
                for (k = 0; k < n; k++) {
                    a[k][j] = 1;
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}