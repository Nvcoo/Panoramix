/*
** File: main.c
** main file
*/

#include "panoramix.h"

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
    sem_destroy(&pot.sync.sem);
    return 0;
}
