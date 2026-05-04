/*
** EPITECH PROJECT, 2026
** Panoramix
** File description:
** main
*/

#include <stdlib.h>
#include "panoramix.h"

int main(int ac, char **av)
{
    int value = 0;

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
    return 0;
}
