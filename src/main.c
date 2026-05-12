/*
** EPITECH PROJECT, 2026
** Panoramix
** File description:
** main
*/

#include "panoramix.h"
#include <semaphore.h>

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
    //sem_cleanup(&pot.sync.sem);
    sem_destroy(&pot.sync.sem);
    return 0;
}
