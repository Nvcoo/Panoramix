/*
** File: print_usage.c
** prints the usage of the program
*/

#include "panoramix.h"

void print_usage(void)
{
    printf("USAGE: ./panoramix <nb_villagers> <pot_size> ");
    printf("<nb_fights> <nb_refills>\n");
    printf("Values must be >0.\n");
}
