//  Team Members
//  Member 1: [Atah-Habibi], [ID:130699943]
//  Member 2: [Matthew-Press], [ID:129894281]



#include "threads.h"

// Semaphore to control access to the shared file
sem_t FLAG;

// Function executed by each thread
void* thread_function(void* arg) {
    // Extract thread ID from argument
    int thread_id = *((int*) arg);
    
    // Determine the quote based on the thread ID (even or odd)
    char* quote = (thread_id % 2 == 0) ? 
        "Controlling complexity is the essence of computer programming. --Brian Kernighan\n" : 
        "Computer science is no more about computers than astronomy is about telescopes. --Edsger Dijkstra\n";

    // Each thread runs this loop 8 times
    int i; 

    for (i = 0; i < 8; i++) {
        // Sleep based on whether the thread ID is even or odd
        if (thread_id % 2 == 0) {
            sleep(2);  // Even threads sleep for 2 seconds
        } else {
            sleep(3);  // Odd threads sleep for 3 seconds
        }

        // Lock the semaphore before writing to the file
        sem_wait(&FLAG);
        
        // Open the file and append the thread's message
        FILE* file = fopen("QUOTE.txt", "a");
        if (file == NULL) {
            // Print an error message and exit if the file cannot be opened
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
        // Write the thread ID and the quote to the file
        fprintf(file, "Thread %d: %s", thread_id, quote);
        // Close the file
        fclose(file);
        
        // Print the thread's running status to the console
        printf("Thread %d is running\n", thread_id);
        
        // Release the semaphore to allow other threads to access the file
        sem_post(&FLAG);
    }

    // Exit the thread
    pthread_exit(NULL);
}

int main() {
    // Create the QUOTE.txt file and write the process ID
    FILE* file = fopen("QUOTE.txt", "w");
    if (file == NULL) {
        // Print an error message and exit if the file cannot be created
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }
    // Write the process ID to the file
    fprintf(file, "PID: %d\n", getpid());
    // Close the file
    fclose(file);

    // Initialize the semaphore
    sem_init(&FLAG, 0, 1);

    // Array to hold thread IDs
    pthread_t threads[NUM_THREADS];
    // Array to hold thread numbers (1 to NUM_THREADS)
    int thread_ids[NUM_THREADS];
    
    // Create the threads
    int it;

    for (it = 0; it < NUM_THREADS; it++) {
        thread_ids[it] = it + 1;  // Thread IDs are 1-based
        // Print a message indicating thread creation
        printf("Creating thread, in main(): %d\n", thread_ids[it]);
        // Create the thread and check for errors
        if (pthread_create(&threads[it], NULL, thread_function, &thread_ids[it]) != 0) {
            // Print an error message and exit if the thread cannot be created
            perror("Error creating thread");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to complete

    int x; 

    for (x = 0; x < NUM_THREADS; x++) {
        pthread_join(threads[x], NULL);
    }

    // Destroy the semaphore
    sem_destroy(&FLAG);
    
    // Print a message indicating that all threads have completed
    printf("All threads completed. Exiting gracefully.\n");

    return 0;
}
