/*
** EPITECH PROJECT, 2026
** Panoramix
** File description:
** villager
*/

#include "panoramix.h"

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
        if (do_fight(villager))
            return NULL;
    }
    return NULL;
}
