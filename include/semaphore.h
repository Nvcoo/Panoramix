/*
** EPITECH PROJECT, 2026
** panoramix
** File description:
** semaphore
*/

#ifndef INCLUDED_SEMAPHORE_H
    #define INCLUDED_SEMAPHORE_H

    #include <pthread.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

typedef struct {
    int count;
    int max;
    pthread_mutex_t mtx;
    pthread_cond_t cond;
} semaphore_t;

#endif
