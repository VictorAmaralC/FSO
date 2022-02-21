#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex;
int MAX = 100000;
int v1[100000], v2[100000];
int s1, s2, M, B, contador;

void calc1(int i)
{
  if ((v1[i] % M) == B)
  {
    sem_wait(&mutex);
    contador++;
    sem_post(&mutex);
  }
}

void calc2(int i)
{
  if ((v2[i] % M) == B)
  {
    sem_wait(&mutex);
    contador++;
    sem_post(&mutex);
  }
}

void *criaVet1(void *a)
{
  for (int i = 0; i < MAX; i++)
    v1[i] = rand_r(&s1);
}

void *criaVet2(void *a)
{
  for (int i = 0; i < MAX; i++)
    v2[i] = rand_r(&s2);
}

void *verifica1(void *a)
{
  for (int i = 0; i < MAX; i++)
  {
    calc1(i);
  }
}

void *verifica2(void *a)
{
  for (int i = 0; i < MAX; i++)
  {
    calc2(i);
  }
}

int modifica()
{
  if (scanf("%d %d", &M, &B) != 2)
  {
    return -1;
  }
  return 1;
}

int main()
{
  pthread_t tid1, tid2;

  sem_init(&mutex, 0, 1);
  scanf("%d %d", &s1, &s2);

  pthread_create(&tid1, NULL, &criaVet1, NULL);
  pthread_create(&tid2, NULL, &criaVet2, NULL);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);

  while (modifica() == 1) {
    pthread_create(&tid1, NULL, &verifica1, NULL);
    pthread_create(&tid2, NULL, &verifica2, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("%d\n", contador);
    contador = 0;
  }

  return 0;
} 