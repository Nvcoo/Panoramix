# Panoramix

A multithreaded simulation of villagers drinking magic potions and fighting enemies.

## Usage

```bash
./panoramix
```

## Arguments

- 'nb_villagers': Number of villagers.
- 'pot_size': Maximum servings in the pot.
- 'nb_fights': Number of fights per villager.
- 'nb_refills': Number of times the druid can refill the pot.

## Build

```bash
make
```

## Run

Example
```bash
./panoramix 3 5 3 1
```

## Error Handling

The program returns:
- '0' on success
- '84' on invalid arguments

## Concepts

- Threads (one per villager and one for the druid)
- Mutexes for shared data protection
- Semaphores for pot access control
- Condition variables for villager/druid communication

## Synchronization Strategy

- A mutex protects access to the potion pot state.
- A semaphore is used to wake the druid when the pot becomes empty.
- Villagers block while waiting for a refill.
- The druid thread exits when no refills remain.

## Project Goals

This project focuses on:
- Multithreading in C
- Synchronization primitives
- race condition prevention
- thread-safe resource sharing
- concurrent simulation design

## Concurrency Challenges

- race conditions on the potion counter
- multiple villagers waking the druid simultaneously
- deadlocks during shutdown
- villagers waiting indefinitely after the druid runs out of refills