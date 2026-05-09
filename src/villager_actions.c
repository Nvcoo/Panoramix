/*
** EPITECH PROJECT, 2026
** panoramix
** File description:
** villager_actions
*/

#include "panoramix.h"

void wait_for_refill(villager_t *vill)
{
    while (vill->pot->portion == 0 && !vill->pot->druid_done) {
        printf("Villager %d: Hey Pano wake up! We need more potion.\n",
            vill->id);
        while (!vill->pot->druid_ready)
            pthread_cond_wait(&vill->pot->pot_refilled, &vill->pot->mutex);
        pthread_cond_signal(&vill->pot->wake_druid);
        pthread_cond_wait(&vill->pot->pot_refilled, &vill->pot->mutex);
    }
}

int do_fight(villager_t *villager)
{
    villager->pot->portion--;
    pthread_mutex_unlock(&villager->pot->mutex);
    sem_get(&villager->pot->sem);
    villager->nb_fights--;
    printf("Villager %d: Take that roman scum! Only %d left.\n",
        villager->id, villager->nb_fights);
    sem_release(&villager->pot->sem);
    if (villager->nb_fights == 0) {
        printf("Villager %d: I'm going to sleep now.\n", villager->id);
        return 1;
    }
    return 0;
}
