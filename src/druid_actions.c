/*
** EPITECH PROJECT, 2026
** panoramix
** File description:
** druid_actions
*/

#include "panoramix.h"

void do_refill(pot_t *pot)
{
    pot->pot_refills--;
    pot->portion = pot->pot_size;
    printf("Druid: Ah! Yes, yes, I'm awake! Working on it! ");
    printf("Beware I can only make %d more refills after this one.\n",
        pot->pot_refills);
    pot->druid_ready = false;
    pthread_cond_broadcast(&pot->pot_refilled);
    pot->druid_ready = true;
    pthread_cond_broadcast(&pot->pot_refilled);
}
