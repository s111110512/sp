#include <stdio.h>
#include <pthread.h>

#define LOOPS 10000000
int money = 100;

void *ATM1()
{
  for (int i=0; i<LOOPS; i++) {
    money = money + 1;
  }
  return NULL;
}

void *ATM2()
{
  for (int i=0; i<LOOPS; i++) {
    money = money - 1;
  }
  return NULL;
}

int main() 
{
    int counter=0;
    while (1)
    {
        pthread_t thread1, thread2;

        pthread_create(&thread1, NULL, ATM1, NULL);
        pthread_create(&thread2, NULL, ATM2, NULL);

        pthread_join( thread1, NULL);
        pthread_join( thread2, NULL);
        if(money<0){
            printf("Error");
            break;
        }
        else
        {
            printf("money=%d\n", money);
        }
    }
}