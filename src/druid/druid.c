/*
** File: druid.c
** druid routine
*/

#include "panoramix.h"

void *druid_routine(void *arg)
{
    pot_t *pot = (pot_t *)arg;

    printf("Druid: I'm ready... but sleepy...\n");
    pthread_mutex_lock(&pot->sync.mutex);
    pot->flags.druid_ready = true;
    pthread_cond_broadcast(&pot->sync.pot_refilled);
    while (pot->data.pot_refills > 0) {
        pthread_cond_wait(&pot->sync.wake_druid, &pot->sync.mutex);
        if (pot->flags.villagers_done)
            break;
        do_refill(pot);
    }
    pot->flags.druid_done = true;
    pthread_cond_broadcast(&pot->sync.pot_refilled);
    pthread_mutex_unlock(&pot->sync.mutex);
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    return NULL;
}
