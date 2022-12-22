#include <stdio.h>
#include <stdlib.h>

const int GOOGOL = 999999999;
 int f(int x, int *b, int n, int *cache) {
    if (x < 0) return GOOGOL;
    if (x == 0) return 0;
    if (cache[x] >= 0) return cache[x];
    int min = GOOGOL;
    for (int i = 0; i < n; i++) {
       int r = f(x - b[i], b, n, cache);
       if (r < min) min = r;
    }
    return cache[x] = min + 1;
 }

void buildSolution(int x, int *b, int n, int *cache){

   for (int k = cache[x]; k >= 0; k--) {
      for (int i = 0; i < n; i++) {
         int r = x - b[i];
         if (r >= 0 && cache[r] == k-1) {
            x = r;
            printf("%d ", b[i]);
            break;
	}    
      }
   }
   printf("\n");
   return; 
}

int main() {
    int n; scanf("%d", &n);
    int *b = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", b+i);
    int x; scanf("%d", &x);
    int *cache = calloc(x+1, sizeof (int));
    for (int i = 0; i <= x; i++) cache[i] = -1;
    int min = f(x, b, n, cache);
    if (min > 1000000)
    {
            printf("-1\n");
            return 0;
    }
    printf("%d\n", min);
    buildSolution(x, b, n, cache);
    free(cache);
    free(b);
    return 0;
}