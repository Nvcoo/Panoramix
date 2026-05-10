# Panoramix

A multithreaded simulation of villagers drinking magic potions and fighting enemies.

## Usage

```bash
./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>
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


For all available build rules:
```bash
make help
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
- A semaphore controls access to the pot, limiting 1 villager at a time.
- Villagers block while waiting for a refill.
- The druid thread exits when no refills remain or all villagers have finished.

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