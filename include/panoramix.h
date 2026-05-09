/*
** EPITECH PROJECT, 2026
** Panoramix
** File description:
** panoramix
*/

#ifndef INCLUDED_PANORAMIX_H
    #define INCLUDED_PANORAMIX_H

    #include <pthread.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

typedef struct {
    int count;
    int max;
    pthread_mutex_t mtx;
    pthread_cond_t cond;
} semaphore_t;

typedef struct {
    int portion;
    int pot_size;
    int pot_refills;
    pthread_mutex_t mutex;
    pthread_cond_t wake_druid;
    pthread_cond_t pot_refilled;
    bool druid_done;
    bool druid_ready;
    bool villagers_done;
    semaphore_t sem;
} pot_t;

typedef struct {
    int id;
    int nb_fights;
    pot_t *pot;
} villager_t;

void print_usage(void);
void *villager_routine(void *arg);
void *druid_routine(void *arg);
void sem_get(semaphore_t *s);
void sem_release(semaphore_t *s);
void sem_setup(semaphore_t *s, int max);
void sem_cleanup(semaphore_t *s);
void pot_init(pot_t *pot, char **av);
void pot_destroy(pot_t *pot);
void start_villagers(pot_t *pot, pthread_t *threads, villager_t *vill,
    int nb_vill);
void simulate(pot_t *pot, char **av);
void wait_for_refill(villager_t *vill);
int do_fight(villager_t *villager);
void do_refill(pot_t *pot);

#endif
