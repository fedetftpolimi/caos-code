#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutexCharge;
int charge = 0;

void *charging_station(void *arg) {
  for (;;) {
    pthread_mutex_lock(&mutexCharge);
    charge += 10; // Adding charge
    printf("Charging station: Added 15 units. Total charge: %d\n", charge);
    pthread_mutex_unlock(&mutexCharge);
    sleep(3); // Simulate charging time
  }
  return NULL;
}

void *bike(void *arg) {
  for (;;) {
    pthread_mutex_lock(&mutexCharge);
    while (charge < 25) { // Check if enough charge is available
      printf("Bike: Not enough charge. Waiting...\n");
      sleep(1);
    }
    charge -= 25; // Consume charge
    printf("Bike: Discharged battery, remaining: %d\n", charge);
    pthread_mutex_unlock(&mutexCharge);
    sleep(2); // Simulate discharging time
  }
  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t threads[2];
  pthread_mutex_init(&mutexCharge, NULL);

  // Create threads for bike and charging station
  if (pthread_create(&threads[0], NULL, &bike, NULL) != 0) {
    perror("Failed to create bike thread");
  }
  if (pthread_create(&threads[1], NULL, &charging_station, NULL) != 0) {
    perror("Failed to create charging station thread");
  }

  // Wait for both threads to complete
  for (int i = 0; i < 2; i++) {
    if (pthread_join(threads[i], NULL) != 0) {
      perror("Failed to join thread");
    }
  }

  pthread_mutex_destroy(&mutexCharge);
  return 0;
}
