/*
** EPITECH PROJECT, 2026
** Panoramix
** File description:
** main
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

void simulate(pot_t *pot, char **av)
{
    int nb_villagers = atoi(av[1]);
    int nb_fights = atoi(av[3]);
    pthread_t villager_threads[nb_villagers];
    villager_t villagers[nb_villagers];
    pthread_t druid_thread;

    sem_setup(&pot->sem, 1);
    for (int i = 0; i < nb_villagers; i++) {
        villagers[i].id = i;
        villagers[i].nb_fights = nb_fights;
        villagers[i].pot = pot;
    }
    pthread_create(&druid_thread, NULL, druid_routine, pot);
    pthread_mutex_lock(&pot->mutex);
    while (!pot->druid_ready)
        pthread_cond_wait(&pot->pot_refilled, &pot->mutex);
    pthread_mutex_unlock(&pot->mutex);
    for (int i = 0; i < nb_villagers; i++)
        pthread_create(&villager_threads[i], NULL, villager_routine, &villagers[i]);
    for (int i = 0; i < nb_villagers; i++)
        pthread_join(villager_threads[i], NULL);
    pthread_mutex_lock(&pot->mutex);
    pot->villagers_done = true;
    pthread_cond_signal(&pot->wake_druid);
    pthread_mutex_unlock(&pot->mutex);
    pthread_join(druid_thread, NULL);
}

int main(int ac, char **av)
{
    int value = 0;
    pot_t pot;

    if (ac != 5) {
        print_usage();
        return 84;
    }
    for (int i = 1; i < ac; i++) {
        value = atoi(av[i]);
        if (value <= 0) {
            print_usage();
            return 84;
        }
    }
    pot_init(&pot, av);
    simulate(&pot, av);
    pot_destroy(&pot);
    sem_cleanup(&pot.sem);
    return 0;
}
