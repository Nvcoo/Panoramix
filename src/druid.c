/*
** EPITECH PROJECT, 2026
** Panoramix
** File description:
** druid
*/

#include "panoramix.h"
#include <pthread.h>
#include <stdio.h>

void *druid_routine(void *arg)
{
    pot_t *pot = (pot_t *)arg;

    printf("Druid: I'm ready... but sleepy...\n");
    while (pot->pot_refills > 0) {
        pthread_mutex_lock(&pot->mutex);
        pthread_cond_wait(&pot->wake_druid, &pot->mutex);
        pot->pot_refills--;
        pot->portion = pot->pot_size;
        printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can only make %d more refills after this one.\n", pot->pot_refills);
        pthread_cond_broadcast(&pot->pot_refilled);
        pthread_mutex_unlock(&pot->mutex);
    }
    pot->druid_done = true;
    pthread_cond_broadcast(&pot->pot_refilled);
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    return NULL;
}
