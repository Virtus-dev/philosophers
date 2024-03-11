/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:28:11 by arigonza          #+#    #+#             */
/*   Updated: 2024/03/11 16:28:13 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_PHILOSOPHERS 100
#define MAX_NAME_LENGTH 50
#define MAX_TIME_LENGTH 50

pthread_mutex_t forks[MAX_PHILOSOPHERS];
pthread_t philosophers[MAX_PHILOSOPHERS];
int num_philosophers;

struct Philosopher {
    int id;
    char name[MAX_NAME_LENGTH];
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
};

void* philosopher_thread(void* arg) {
    struct Philosopher* philosopher = (struct Philosopher*)arg;
    int id = philosopher->id;
    char* name = philosopher->name;
    int time_to_die = philosopher->time_to_die;
    int time_to_eat = philosopher->time_to_eat;
    int time_to_sleep = philosopher->time_to_sleep;

    while (1) {
        printf("%s is thinking\n", name);
        usleep(1000000); // Thinking

        // Attempt to acquire left fork
        pthread_mutex_lock(&forks[id]);
        printf("%s has taken fork %d\n", name, id);

        // Attempt to acquire right fork
        pthread_mutex_lock(&forks[(id + 1) % num_philosophers]);
        printf("%s has taken fork %d\n", name, (id + 1) % num_philosophers);

        printf("%s is eating\n", name);
        usleep(time_to_eat * 1000); // Eating

        pthread_mutex_unlock(&forks[id]);
        pthread_mutex_unlock(&forks[(id + 1) % num_philosophers]);

        printf("%s is sleeping\n", name);
        usleep(time_to_sleep * 1000); // Sleeping
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 6) {
        printf("Usage: %s number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n", argv[0]);
        return 1;
    }

    num_philosophers = atoi(argv[1]);
    int time_to_die = atoi(argv[2]);
    int time_to_eat = atoi(argv[3]);
    int time_to_sleep = atoi(argv[4]);

    struct Philosopher philosophers[MAX_PHILOSOPHERS];

    // Initialize mutexes (forks)
    for (int i = 0; i < num_philosophers; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }

    // Create philosopher threads
    for (int i = 0; i < num_philosophers; i++) {
        philosophers[i].id = i;
        snprintf(philosophers[i].name, MAX_NAME_LENGTH, "Philosopher %d", i);
        philosophers[i].time_to_die = time_to_die;
        philosophers[i].time_to_eat = time_to_eat;
        philosophers[i].time_to_sleep = time_to_sleep;
        pthread_create(&philosophers[i], NULL, philosopher_thread, &philosophers[i]);
    }

    // Join philosopher threads (not implemented yet)

    // Clean up resources (not implemented yet)

    return 0;
}
