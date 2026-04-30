/*Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target.*/
#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort (sort by position descending)
int cmp(const void *a, const void *b) {
    int *x = (int*)a;
    int *y = (int*)b;
    return y[0] - x[0];  // descending by position
}

int carFleet(int target, int pos[], int speed[], int n) {
    // Pair positions and speeds into intervals
    int cars[n][2];
    for (int i = 0; i < n; i++) {
        cars[i][0] = pos[i];
        cars[i][1] = speed[i];
    }

    // Sort cars by position descending
    qsort(cars, n, sizeof(cars[0]), cmp);

    int fleets = 0;
    double lastTime = -1.0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i][0]) / cars[i][1];
        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
        // If time <= lastTime, this car joins the fleet ahead
    }
    return fleets;
}

int main() {
    int target, n;
    printf("Enter target distance: ");
    scanf("%d", &target);

    printf("Enter number of cars: ");
    scanf("%d", &n);

    int pos[n], speed[n];
    printf("Enter positions: ");
    for (int i = 0; i < n; i++) scanf("%d", &pos[i]);

    printf("Enter speeds: ");
    for (int i = 0; i < n; i++) scanf("%d", &speed[i]);

    int fleets = carFleet(target, pos, speed, n);
    printf("Number of car fleets: %d\n", fleets);

    return 0;
}
