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

    if (ac != 5) {
        printf("USAGE: ./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>\n");
        printf("Values must be >0.\n");
        return 84;
    }
    for (int i = 1; i < ac; i++) {
        value = atoi(av[i]);
        if (value <= 0) {
            printf("USAGE: ./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>\n");
            printf("Values must be >0.\n");
            return 84;
        }
    }
    return 0;
}
