#include <stdio.h>
#include <stdlib.h>
void dfs (int a[][100], int *visit, int s, int n)
{
	int i;
	visit[s] = 2;
	for (i = 1; i <= n; i++) {
		if (a[s][i] == 1 && visit[i] == 1) {
			dfs (a, visit, i, n);
		}
	}
	visit[s] = 3;
}
void dfs_traversal (int a[][100], int *visit, int n)
{
	int s;
	scanf ("%d", &s);
	int i;
}
void articulation (int a[][100], int *visit, int n)
{
	int i, j;
	int b[100][100];
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			b[i][j] = a[i][j];
		}
	}
	int k, l;
//	printf ("hello\n");
	for (i = 1; i < n; i++) {
		for (j = 1; j <= n; j++) {
			if (b[i][j] == 1) {
				b[i][j] = 0;
				b[j][i] = 0;
			}
		}
		int count = 0;
//		printf ("sghj\n");
		dfs (b, visit, i+1, n);
		for (k = 1; k <= n; k++) {
//			printf ("gdjh\n");
			if (k != i && visit[k] == 1) {
				count ++;
			}
		}
		if (count != 0) {
			printf ("%d ", i);
		}
		for (l = 1; l <= n; l++) {
			b[i][l] = a[i][l];
			b[l][i] = a[l][i];
			visit[l] = 1;
		}
	}
}
int main ()
{
	int a[100][100];
	int n;
	scanf ("%d", &n);
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf ("%d", &a[i][j]);
		}
	}
	int visit[100];
	for (i = 1; i <= n; i++) {
		visit[i] = 1;
	}
	articulation (a, visit, n);
	printf ("\n");
	return 0;
}
