#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* routine(){
    printf("Hello from thread\n");
    sleep(3);
    printf("Exiting thread\n");
}


int main(int argc, char *argv[])
{
    pthread_t t1,t2;
    //init thread;
    if(pthread_create(&t1, NULL, &routine, NULL) != 0) { //pointer to pthread obj; attributs, NULL==default; fun; arguments to fun;
        return 1; // return 1 if coudnt create thread
    }
    if(pthread_create(&t2, NULL, &routine, NULL) != 0){
        return 2;
    }
    // wait for thread to finish execution
    pthread_join(t1, NULL);  //pthread obj; pointer to result data
    pthread_join(t2, NULL);

    return 0;
}