/*
** File: panoramix.h
** header for the panoramix project
*/

#ifndef INCLUDED_PANORAMIX_H
    #define INCLUDED_PANORAMIX_H

    #include <pthread.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include "pot.h"

typedef struct {
    int id;
    int nb_fights;
    pot_t *pot;
} villager_t;

void print_usage(void);
void *villager_routine(void *arg);
void *druid_routine(void *arg);
void pot_init(pot_t *pot, char **av);
void pot_destroy(pot_t *pot);
void start_villagers(pot_t *pot, pthread_t *threads, villager_t *vill,
    int nb_vill);
void simulate(pot_t *pot, char **av);
void wait_for_refill(villager_t *vill);
int do_fight(villager_t *villager);
void do_refill(pot_t *pot);

#endif
