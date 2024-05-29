//  Team Members
//  Member 1: [Atah-Habibi], [ID:130699943]
//  Member 2: [Matthew-Press], [ID:129894281]

#ifndef THREADS_H
#define THREADS_H

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 7

// Function executed by each thread
void* thread_function(void* arg);

#endif // THREADS_H
