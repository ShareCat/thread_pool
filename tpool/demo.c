#include "tpool.h"
#include <stdio.h>
#include <unistd.h>
#include <time.h>

void* fun(void* args)
{
    printf("Thread #%u working on %d\n", (int)pthread_self(), (int) args);
    usleep(10);
    return NULL;
}

int main(int argc, char* args[])
{
    tpool_t* pool = NULL;

    if (0 != create_tpool(&pool, 5)) {
        printf("create_tpool failed!\n");
        return -1;
    }

    for (int i = 0; i < 100; i++) {
        add_task_2_tpool(pool, fun, (void*)i);
    }

    sleep(2);
    destroy_tpool(pool);
    return 0;
}