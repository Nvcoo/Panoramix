/*
** EPITECH PROJECT, 2026
** Panoramix
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
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
    pot.pot_size = atoi(av[2]);
    pot.portion = pot.pot_size;
    pot.pot_refills = atoi(av[4]);
    return 0;
}
