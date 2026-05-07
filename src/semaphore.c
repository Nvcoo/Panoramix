/*
** EPITECH PROJECT, 2026
** Panoramix
** File description:
** semaphore
*/

#include "panoramix.h"
#include <pthread.h>

void sem_get(sem_t *s)
{
    pthread_mutex_lock(&s->mtx);
    while (s->count >= s->max)
        pthread_cond_wait(&s->cond, &s->mtx);
    s->count++;
    pthread_mutex_unlock(&s->mtx);
}

void sem_release(sem_t *s)
{
    pthread_mutex_lock(&s->mtx);
    s->count--;
    pthread_cond_signal(&s->cond);
    pthread_mutex_unlock(&s->mtx);
}
