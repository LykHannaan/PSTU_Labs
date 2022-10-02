#include <pthread.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <windows.h>

using namespace std;

struct args
{
  char* threadName;
  char* buf;
  int count;
};

 int global = 0;
 sem_t semaphore1;

void *thread1(void* arg)
{
    for (int i = 0; i < ((args*)arg) -> count; i++)
    {
        Sleep(50);
        sem_wait(&semaphore1);
        cout << "Print: " << ((args*)arg)-> buf << " from first thread";
        global +=1;
        cout << " (global = " << global << ")" << endl;
        Sleep(100);
        sem_post(&semaphore1);
    }
    pthread_exit(NULL);
}

void *thread2(void* arg)
{
    for (int i = 0; i < ((args*)arg) -> count;i++)
    {
        Sleep(200);
        sem_wait(&semaphore1);
        cout << "Print: " << ((args*)arg)-> buf <<  " from second thread";
        global +=3;
        cout << " (global = " << global << ")" << endl;
        Sleep(100);
        sem_post(&semaphore1);
    }
    pthread_exit(NULL);
}

void *thread3(void* arg)
{
    for (int i = 0; i < ((args*)arg) -> count;i++)
    {
        Sleep(350);
        sem_wait(&semaphore1);
        cout << "Print: " << ((args*)arg)-> buf << " from third thread";
        global +=4;
        cout << " (global = " << global << ")" << endl;
        Sleep(100);
        sem_post(&semaphore1);
    }
    pthread_exit(NULL);
}


int main()
{
    pthread_t l_th, f_th, s_th;
    args f_args,  s_args, l_args;

    sem_init(&semaphore1, 0, 1);

    f_args.buf=(char*)"I WANNA ";           f_args.count=4;
    s_args.buf=(char*)"BREAK THE CODE!  ";  s_args.count=2;
    l_args.buf=(char*)"HAVE CONTROL! ";     l_args.count=2;

    int res;
    res = pthread_create(&f_th, NULL, thread1, &f_args);
    if (res) exit(-1);
    res = pthread_create(&s_th, NULL, thread2, &s_args);
    if (res) exit(-1);
    res = pthread_create(&l_th, NULL, thread3, &l_args);
    if (res) exit(-1);

    pthread_join(f_th, NULL);
    pthread_join(s_th, NULL);
    pthread_join(l_th, NULL);

    cout << "global var of: " << global << endl;
    cout << "returned process code: " << res << endl;
    sem_destroy(&semaphore1);
}
