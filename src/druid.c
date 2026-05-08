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

    pthread_mutex_lock(&pot->display_mutex);
    printf("Druid: I'm ready... but sleepy...\n");
    pthread_mutex_unlock(&pot->display_mutex);
    pthread_mutex_lock(&pot->mutex);
    pot->druid_ready = true;
    pthread_cond_broadcast(&pot->pot_refilled);
    pthread_mutex_unlock(&pot->mutex);
    while (pot->pot_refills > 0) {
        pthread_mutex_lock(&pot->mutex);
        pthread_cond_wait(&pot->wake_druid, &pot->mutex);
        pot->pot_refills--;
        pot->portion = pot->pot_size;
        pot->druid_ready = false;
        pthread_mutex_lock(&pot->display_mutex);
        printf("Druid: Ah! Yes, yes, I'm awake! Working on it! ");
        printf("Beware I can only ");
        printf("make %d more refills after this one.\n", pot->pot_refills);
        pthread_mutex_unlock(&pot->display_mutex);
        pthread_cond_broadcast(&pot->pot_refilled);
        pthread_mutex_unlock(&pot->mutex);
        pthread_mutex_lock(&pot->mutex);
        pot->druid_ready = true;
        pthread_cond_broadcast(&pot->pot_refilled);
        pthread_mutex_unlock(&pot->mutex);
    }
    pot->druid_done = true;
    pthread_cond_broadcast(&pot->pot_refilled);
    pthread_mutex_lock(&pot->display_mutex);
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    pthread_mutex_unlock(&pot->display_mutex);
    return NULL;
}
