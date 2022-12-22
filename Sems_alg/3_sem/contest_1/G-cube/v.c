#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
 int N;
 unsigned long long M;
 scanf("%d", &N);
 scanf("%llu", &M);

 if (M < N)
 {
  printf("0\n");
  return 0;
 }

 const double one_of_six = 1.0/6;

 double **dp = calloc((N+1), sizeof(double *));
 assert(dp != NULL);
 for (int i = 0; i <= N; i++)
 {
  dp[i] = calloc((M+1), sizeof(double));
  assert(dp[i] != NULL);
 }

 for (int i = 1; i <= 6; i++)
 {
  dp[1][i] = one_of_six;
 }

 for (int i = 2; i <= N; i ++)
 {
  for (unsigned long long j = i; j <= M; j ++)
  {
   for (int t = 1; (t <= 6) && (j - t >= i - 1); t++)
   {
    dp[i][j] += one_of_six * dp[i-1][j - t];
   }
  }
 }

 for (int i = 0; i < M + 1; i++)
    {
        for (int j = 0; j < N + 1; j++)
        {
            printf("%.10lf ", dp[j][i]);
        }
        printf("\n");
    }

 printf("%.9lf\n", dp[N][M]);

 for (int i = 0; i <= N; i++)
 {
  free(dp[i]);
 }
 free(dp);

 return 0;
}
