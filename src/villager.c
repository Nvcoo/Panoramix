/*
** EPITECH PROJECT, 2026
** Panoramix
** File description:
** villager
*/

#include "panoramix.h"
#include <pthread.h>
#include <stdio.h>

void *villager_routine(void *arg)
{
    villager_t *villager = (villager_t *)arg;

    pthread_mutex_lock(&villager->pot->display_mutex);
    printf("Villager %d: Going into battle!\n", villager->id);
    pthread_mutex_unlock(&villager->pot->display_mutex);
    while (villager->nb_fights > 0) {
        sem_get(&villager->pot->sem);
        pthread_mutex_lock(&villager->pot->display_mutex);
        printf("Villager %d: I need a drink... I see %d servings left.\n", villager->id, villager->pot->portion);
        pthread_mutex_unlock(&villager->pot->display_mutex);
        while (villager->pot->portion == 0 && !villager->pot->druid_done) {
            pthread_mutex_lock(&villager->pot->display_mutex);
            printf("Villager %d: Hey Pano wake up! We need more potion.\n", villager->id);
            pthread_mutex_unlock(&villager->pot->display_mutex);
            sem_release(&villager->pot->sem);
            pthread_mutex_lock(&villager->pot->mutex);
            pthread_cond_signal(&villager->pot->wake_druid);
            pthread_cond_wait(&villager->pot->pot_refilled, &villager->pot->mutex);
            pthread_mutex_unlock(&villager->pot->mutex);
            sem_get(&villager->pot->sem);
        }
        if (villager->pot->portion == 0 && villager->pot->druid_done) {
            sem_release(&villager->pot->sem);
            pthread_mutex_lock(&villager->pot->display_mutex);
            printf("Villager %d: I'm going to sleep now.\n", villager->id);
            pthread_mutex_unlock(&villager->pot->display_mutex);
            return NULL;
        }
        villager->pot->portion--;
        sem_release(&villager->pot->sem);
        villager->nb_fights--;
        pthread_mutex_lock(&villager->pot->display_mutex);
        printf("Villager %d: Take that roman scum! Only %d left.\n", villager->id, villager->nb_fights);
        pthread_mutex_unlock(&villager->pot->display_mutex);
        if (villager->nb_fights == 0) {
            pthread_mutex_lock(&villager->pot->display_mutex);
            printf("Villager %d: I'm going to sleep now.\n", villager->id);
            pthread_mutex_unlock(&villager->pot->display_mutex);
            return NULL;
        }
    }
    return NULL;
}
