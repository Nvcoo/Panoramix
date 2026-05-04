/*
** EPITECH PROJECT, 2026
** Panoramix
** File description:
** main
*/

#include <pthread.h>
#include <stdlib.h>
#include "panoramix.h"

int main(int ac, char **av)
{
    int value = 0;
    int nb_villagers = 0;
    int nb_fights = 0;
    pot_t pot;
    pthread_t druid_thread;

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
    pthread_mutex_init(&pot.mutex, NULL);
    pthread_cond_init(&pot.wake_druid, NULL);
    pthread_cond_init(&pot.pot_refilled, NULL);
    pot.pot_size = atoi(av[2]);
    pot.portion = pot.pot_size;
    pot.pot_refills = atoi(av[4]);
    nb_villagers = atoi(av[1]);
    nb_fights = atoi(av[3]);
    pthread_t villager_threads[nb_villagers];
    villager_t villagers[nb_villagers];
    for (int i = 0; i < nb_villagers; i++) {
        villagers[i].id = i;
        villagers[i].nb_fights = nb_fights;
        villagers[i].pot = &pot;
    }
    for (int i = 0; i < nb_villagers; i++)
        pthread_create(&villager_threads[i], NULL, villager_routine, &villagers[i]);
    pthread_create(&druid_thread, NULL, druid_routine, &pot);
    for (int i = 0; i < nb_villagers; i++)
        pthread_join(villager_threads[i], NULL);
    pthread_join(druid_thread, NULL);
    pthread_mutex_destroy(&pot.mutex);
    pthread_cond_destroy(&pot.wake_druid);
    pthread_cond_destroy(&pot.pot_refilled);
    return 0;
}
