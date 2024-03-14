/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:28:11 by arigonza          #+#    #+#             */
/*   Updated: 2024/03/14 13:11:33 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_PHILOSOPHERS 9
#define MAX_TIME 50

pthread_mutex_t forks[MAX_PHILOSOPHERS];
pthread_t philosophers_thrd[MAX_PHILOSOPHERS];
int num_philosophers;

struct Philosopher {
    int id;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
};

void* philosopher_thread(void* arg) {
    struct Philosopher* philosopher = (struct Philosopher*)arg;
    int id = philosopher->id;
   // int time_to_die = philosopher->time_to_die;
    int time_to_eat = philosopher->time_to_eat;
    int time_to_sleep = philosopher->time_to_sleep;
    usleep(1);
    while (1) {
        printf("%d is thinking\n", id);
        usleep(time_to_sleep / 1000); // Thinking

        // Attempt to acquire left fork
        pthread_mutex_lock(&forks[id - 1]);
        printf("%d has taken fork %d\n", id, id);

        // Attempt to acquire right fork
        pthread_mutex_lock(&forks[id % num_philosophers]);
        printf("%d has taken fork %d\n", id, (id % num_philosophers) + 1);

        printf("%d is eating\n", id);
        usleep(time_to_eat / 1000); // Eating

        pthread_mutex_unlock(&forks[id - 1]);
        pthread_mutex_unlock(&forks[id % num_philosophers]);

        printf("%d is sleeping\n", id);
        usleep(time_to_sleep / 1000); // Sleeping

    }

    return NULL;
}

int main(int argc, char *argv[]) {
    
    int i = 0;
    
    if (argc < 6) {
        printf("Usage: %s number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n", argv[0]);
        return 1;
    }

    num_philosophers = atoi(argv[1]);
    int time_to_die = atoi(argv[2]);
    int time_to_eat = atoi(argv[3]);
    int time_to_sleep = atoi(argv[4]);

    struct Philosopher philosophers[MAX_PHILOSOPHERS];
    
    i = 0;
    // Initialize mutexes (forks)
    while (i <= num_philosophers) {
        pthread_mutex_init(&forks[i++], NULL);
    }

    i = 1;

    // Create philosopher threads
    while (i <= num_philosophers) {
        philosophers[i].id = i;
        printf("Philosopher %d\n", i);
        philosophers[i].time_to_die = time_to_die;
        philosophers[i].time_to_eat = time_to_eat;
        philosophers[i].time_to_sleep = time_to_sleep;
        pthread_create(&philosophers_thrd[i], NULL, philosopher_thread, &philosophers[i]);
        i++;
    }

    // Join philosopher threads (not implemented yet)

    // Clean up resources (not implemented yet)

    return 0;
}
