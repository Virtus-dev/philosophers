/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:04:32 by arigonza          #+#    #+#             */
/*   Updated: 2024/03/13 15:26:52 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

#define NUM_PHILOSOPHERS 5
#define MAX_TIME_SEC 3 // Maximum time in seconds for each action

pthread_mutex_t forks[NUM_PHILOSOPHERS];
pthread_t philosophers[NUM_PHILOSOPHERS];

void *philosopher(void *arg) {
    int philosopher_id = (int)arg;
    int left_fork = philosopher_id;
    int right_fork = (philosopher_id + 1) % NUM_PHILOSOPHERS;

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    while (1) {
        // Think for a while
        printf("Philosopher %d is thinking.\n", philosopher_id);
        while (1) {
            gettimeofday(&end_time, NULL);
            long long elapsed_time = (end_time.tv_sec - start_time.tv_sec) +
                                  (end_time.tv_usec - start_time.tv_usec) / 1000000;
            if (elapsed_time >= MAX_TIME_SEC) {
                break;
            }
        }
        gettimeofday(&start_time, NULL);

        // Attempt to acquire both forks
        printf("Philosopher %d is hungry.\n", philosopher_id);
        pthread_mutex_lock(&forks[left_fork]);
        pthread_mutex_lock(&forks[right_fork]);

        // Eating
        printf("Philosopher %d is eating.\n", philosopher_id);
        while (1) {
            gettimeofday(&end_time, NULL);
            double elapsed_time = (end_time.tv_sec - start_time.tv_sec) +
                                  (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
            if (elapsed_time >= MAX_TIME_SEC) {
                break;
            }
        }
        gettimeofday(&start_time, NULL);

        // Release forks
        pthread_mutex_unlock(&forks[left_fork]);
        pthread_mutex_unlock(&forks[right_fork]);
    }

    return NULL;
}

int main() {
    //srand(time(NULL));

    int i = 0;

    // Initialize mutexes (forks)
    while (i < NUM_PHILOSOPHERS) {
        pthread_mutex_init(&forks[i++], NULL);
    }
    
    // Create philosopher threads
    for (int j = 1; j <= NUM_PHILOSOPHERS; j++) {
        pthread_create(&philosophers[i], NULL, philosopher, &j);
    }

    // Join philosopher threads
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Destroy mutexes
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}
