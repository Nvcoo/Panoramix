/*
** File: simulation.c
** handles the simulation
*/

#include "panoramix.h"

void start_villagers(pot_t *pot, pthread_t *threads, villager_t *vill,
    int nb_vill)
{
    for (int i = 0; i < nb_vill; i++)
        pthread_create(&threads[i], NULL, villager_routine, &vill[i]);
    for (int i = 0; i < nb_vill; i++)
        pthread_join(threads[i], NULL);
    pthread_mutex_lock(&pot->sync.mutex);
    pot->flags.villagers_done = true;
    pthread_cond_signal(&pot->sync.wake_druid);
    pthread_mutex_unlock(&pot->sync.mutex);
}

void simulate(pot_t *pot, char **av)
{
    int nb_villagers = atoi(av[1]);
    int nb_fights = atoi(av[3]);
    pthread_t villager_threads[nb_villagers];
    villager_t villagers[nb_villagers];
    pthread_t druid_thread;

    sem_init(&pot->sync.sem, 0, 1);
    for (int i = 0; i < nb_villagers; i++) {
        villagers[i].id = i;
        villagers[i].nb_fights = nb_fights;
        villagers[i].pot = pot;
    }
    pthread_create(&druid_thread, NULL, druid_routine, pot);
    pthread_mutex_lock(&pot->sync.mutex);
    while (!pot->flags.druid_ready)
        pthread_cond_wait(&pot->sync.pot_refilled, &pot->sync.mutex);
    pthread_mutex_unlock(&pot->sync.mutex);
    start_villagers(pot, villager_threads, villagers, nb_villagers);
    pthread_join(druid_thread, NULL);
}
