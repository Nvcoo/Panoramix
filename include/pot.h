/*
** File: pot.h
** header for the pot
*/

#ifndef INCLUDED_POT_H
    #define INCLUDED_POT_H

    #include <pthread.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <semaphore.h>

typedef struct {
    int portion;
    int pot_size;
    int pot_refills;
} pot_data_t;

typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t wake_druid;
    pthread_cond_t pot_refilled;
    sem_t sem;
} pot_threading_t;

typedef struct {
    bool druid_done;
    bool druid_ready;
    bool villagers_done;
} pot_flags_t;

typedef struct {
    pot_data_t data;
    pot_threading_t sync;
    pot_flags_t flags;
} pot_t;


#endif
