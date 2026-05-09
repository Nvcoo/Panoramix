/*
** EPITECH PROJECT, 2026
** panoramix
** File description:
** pot
*/

#include "panoramix.h"

void pot_init(pot_t *pot, char **av)
{
    pthread_mutex_init(&pot->mutex, NULL);
    pthread_cond_init(&pot->wake_druid, NULL);
    pthread_cond_init(&pot->pot_refilled, NULL);
    pot->pot_size = atoi(av[2]);
    pot->portion = pot->pot_size;
    pot->pot_refills = atoi(av[4]);
    pot->druid_done = false;
    pot->druid_ready = false;
    pot->villagers_done = false;
}

void pot_destroy(pot_t *pot)
{
    pthread_mutex_destroy(&pot->mutex);
    pthread_cond_destroy(&pot->wake_druid);
    pthread_cond_destroy(&pot->pot_refilled);
}
