/*
** EPITECH PROJECT, 2026
** Panoramix
** File description:
** druid_actions
*/

#include "panoramix.h"

void do_refill(pot_t *pot)
{
    pot->data.pot_refills--;
    pot->data.portion = pot->data.pot_size;
    printf("Druid: Ah! Yes, yes, I'm awake! Working on it! ");
    printf("Beware I can only make %d more refills after this one.\n",
        pot->data.pot_refills);
    pot->flags.druid_ready = false;
    pthread_cond_broadcast(&pot->sync.pot_refilled);
    pot->flags.druid_ready = true;
    pthread_cond_broadcast(&pot->sync.pot_refilled);
}
