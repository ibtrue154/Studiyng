#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
typedef struct {
    int N;
    int k;
    double *mas;
    int ind;
    pthread_t thread;
    pthread_mutex_t *mutex;
} st;
 
void func(void* arg);

int main(int argc, char* argv[]) 
{
    int N = atoi(argv[1]), k = atoi(argv[2]);
    double* mas = malloc(k * sizeof(double));
 
    st threads[k];
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
    for (int i = 0; i < k; i++) 
    {
        threads[i].k = k;
        threads[i].N = N;
        threads[i].mas = mas;
        threads[i].ind = i;
        threads[i].mutex = &mutex;
        pthread_create(&threads[i].thread, &attr, (void*)func, &threads[i]);
    }
    pthread_attr_destroy(&attr);
    for (int i = 0; i < k; ++i) {
        pthread_join(threads[i].thread, NULL);
    }
 
    for (int i = 0; i < k; ++i) {
        printf("%.10g\n", mas[i]);
    }
    free(mas);
 
    return 0;
}

void func(void* arg) 
{
    st *data = arg;
    int cur = 0, left = 0, right = 0;
    cur = data->ind;

    if (cur == 0)
        left = data->k - 1;
    else
        left = cur - 1;

    if (cur == data->k - 1)
        right = 0;
    else
        right = cur + 1;
    
    for (int i = 0; i < data->N; i++) 
    {
        pthread_mutex_lock(data->mutex);
        data->mas[left] += 0.99;
        data->mas[cur] += 1.00;
        data->mas[right] += 1.01;
        pthread_mutex_unlock(data->mutex);
    }
}