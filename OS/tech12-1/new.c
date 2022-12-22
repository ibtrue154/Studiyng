#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
void* summer(void* param);

void thread_creator(int N, pthread_t* tid, void* summer, int* part_sums);

int main(int argc, char* argv[]) 
{
    int N = atoi(argv[1]);
    int* part_sums = malloc(N * sizeof(int));
    pthread_t* tid = malloc(N * sizeof(pthread_t));
 
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    thread_creator(N, tid, summer, part_sums);
    pthread_attr_destroy(&attr);
 
    int ans = 0;
    for (int i = 0; i < N; i++) 
    {
        pthread_join(tid[i], NULL);
        ans += part_sums[i];
    }
    free(tid);
    free(part_sums);
 
    printf("%d\n", ans);
 
    return 0;
}

void* summer(void* param) 
{
    int x = 0;
    int* sum = param;
    while (scanf("%d", &x) > 0) 
    {
        *sum += x;
    }

    pthread_exit(0);
}

void thread_creator(int N, pthread_t* tid, void* summer, int* part_sums)
{
    for (int i = 0; i < N; i++) 
        pthread_create(&tid[i], NULL, (void*)summer, &part_sums[i]);
}