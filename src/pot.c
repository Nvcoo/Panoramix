/*
** File: pot.c
** handles the pot
*/

#include "panoramix.h"

void pot_init(pot_t *pot, char **av)
{
    pthread_mutex_init(&pot->sync.mutex, NULL);
    pthread_cond_init(&pot->sync.wake_druid, NULL);
    pthread_cond_init(&pot->sync.pot_refilled, NULL);
    pot->data.pot_size = atoi(av[2]);
    pot->data.portion = pot->data.pot_size;
    pot->data.pot_refills = atoi(av[4]);
    pot->flags.druid_done = false;
    pot->flags.druid_ready = false;
    pot->flags.villagers_done = false;
}

void pot_destroy(pot_t *pot)
{
    pthread_mutex_destroy(&pot->sync.mutex);
    pthread_cond_destroy(&pot->sync.wake_druid);
    pthread_cond_destroy(&pot->sync.pot_refilled);
}
