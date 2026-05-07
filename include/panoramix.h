/*
** EPITECH PROJECT, 2026
** Panoramix
** File description:
** panoramix
*/

#ifndef INCLUDED_PANORAMIX_H
    #define INCLUDED_PANORAMIX_H

    #include <pthread.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

typedef struct {
    int portion;
    int pot_size;
    int pot_refills;
    pthread_mutex_t mutex;
    pthread_cond_t wake_druid;
    pthread_cond_t pot_refilled;
    bool druid_done;
} pot_t;

typedef struct {
    int id;
    int nb_fights;
    pot_t *pot;
} villager_t;

typedef struct {
    int count;
    int max;
    pthread_mutex_t mtx;
    pthread_cond_t cond;
} sem_t;

void print_usage(void);

void *villager_routine(void *arg);
void *druid_routine(void *arg);

void sem_get(sem_t *s);
void sem_release(sem_t *s);
void sem_setup(sem_t *s);
void sem_cleanup(sem_t *s);

#endif
