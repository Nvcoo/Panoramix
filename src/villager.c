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

    printf("Villager %d: Going into battle!\n", villager->id);
    while (villager->nb_fights > 0) {
        pthread_mutex_lock(&villager->pot->mutex);
        printf("Villager %d: I need a drink... I see %d servings left.\n", villager->id, villager->pot->portion);
        while (villager->pot->portion == 0) {
            printf("Villager %d: Hey Pano wake up! We need more potion.\n", villager->id);
            pthread_cond_signal(&villager->pot->wake_druid);
            pthread_cond_wait(&villager->pot->pot_refilled, &villager->pot->mutex);
        }
        villager->pot->portion--;
        pthread_mutex_unlock(&villager->pot->mutex);
        villager->nb_fights--;
        printf("Villager %d: Take that roman scum! Only %d left.\n", villager->id, villager->nb_fights);
        if (villager->nb_fights == 0) {
            printf("Villager %d: I'm going to sleep now.\n", villager->id);
            return NULL;
        }
    }
    return NULL;
}
