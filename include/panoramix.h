/*
** EPITECH PROJECT, 2026
** Panoramix
** File description:
** panoramix
*/

#ifndef INCLUDED_PANORAMIX_H
    #define INCLUDED_PANORAMIX_H

    #include <pthread.h>

typedef struct {
    int portion;
    int pot_size;
    int pot_refills;
    pthread_mutex_t mutex;
    pthread_cond_t wake_druid;
    pthread_cond_t pot_refilled;
} pot_t;

typedef struct {
    int id;
    int nb_fights;
    pot_t *pot;
} villager_t;

void print_usage(void);

void *villager_routine(void *arg);
void *druid_routine(void *arg);

#endif
