/*
** EPITECH PROJECT, 2026
** Panoramix
** File description:
** druid
*/

#include "panoramix.h"
#include <stdio.h>

void *druid_routine(void *arg)
{
    (void)arg;
    printf("Druid thread started\n");
    return NULL;
}
