/*
** EPITECH PROJECT, 2026
** Panoramix
** File description:
** villager
*/

#include "panoramix.h"
#include <pthread.h>

void wait_for_refill(villager_t *villager)
{
    while (villager->pot->portion == 0 && !villager->pot->druid_done) {
        printf("Villager %d: Hey Pano wake up! We need more potion.\n",
            villager->id);
        while (!villager->pot->druid_ready)
            pthread_cond_wait(&villager->pot->pot_refilled, &villager->pot->mutex);
        pthread_cond_signal(&villager->pot->wake_druid);
        pthread_cond_wait(&villager->pot->pot_refilled, &villager->pot->mutex);
    }
}

void *villager_routine(void *arg)
{
    villager_t *villager = (villager_t *)arg;

    printf("Villager %d: Going into battle!\n", villager->id);
    while (villager->nb_fights > 0) {
        pthread_mutex_lock(&villager->pot->mutex);
        printf("Villager %d: I need a drink... I see %d servings left.\n",
            villager->id, villager->pot->portion);
        wait_for_refill(villager);
        if (villager->pot->druid_done && villager->pot->portion == 0) {
            pthread_mutex_unlock(&villager->pot->mutex);
            printf("Villager %d: I'm going to sleep now.\n", villager->id);
            return NULL;
        }
        villager->pot->portion--;
        pthread_mutex_unlock(&villager->pot->mutex);
        sem_get(&villager->pot->sem);
        villager->nb_fights--;
        printf("Villager %d: Take that roman scum! Only %d left.\n",
            villager->id, villager->nb_fights);
        sem_release(&villager->pot->sem);
        if (villager->nb_fights == 0) {
            printf("Villager %d: I'm going to sleep now.\n", villager->id);
            return NULL;
        }
    }
    return NULL;
}
