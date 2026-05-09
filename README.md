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

## Compilation

```bash
make
```

## Concepts

- Threads (one per villager and one for the druid)
- Mutexes for shared data protection
- Semaphores for pot access control
- Condition variables for villager/druid communication