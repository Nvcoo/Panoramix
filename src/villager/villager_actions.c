/*
** EPITECH PROJECT, 2026
** Panoramix
** File description:
** villager_actions
*/

#include "panoramix.h"
#include <semaphore.h>

void wait_for_refill(villager_t *vill)
{
    while (vill->pot->data.portion == 0 && !vill->pot->flags.druid_done) {
        printf("Villager %d: Hey Pano wake up! We need more potion.\n",
            vill->id);
        while (!vill->pot->flags.druid_ready)
            pthread_cond_wait(&vill->pot->sync.pot_refilled,
                &vill->pot->sync.mutex);
        pthread_cond_signal(&vill->pot->sync.wake_druid);
        pthread_cond_wait(&vill->pot->sync.pot_refilled,
            &vill->pot->sync.mutex);
    }
}

int do_fight(villager_t *villager)
{
    villager->pot->data.portion--;
    pthread_mutex_unlock(&villager->pot->sync.mutex);
    sem_wait(&villager->pot->sync.sem);
    villager->nb_fights--;
    printf("Villager %d: Take that roman scum! Only %d left.\n",
        villager->id, villager->nb_fights);
    sem_post(&villager->pot->sync.sem);
    if (villager->nb_fights == 0) {
        printf("Villager %d: I'm going to sleep now.\n", villager->id);
        return 1;
    }
    return 0;
}
