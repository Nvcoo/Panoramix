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

    printf("Villager %d thread started\n", villager->id);
    return NULL;
}
