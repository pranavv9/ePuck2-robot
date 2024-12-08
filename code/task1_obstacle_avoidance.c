#include "task1_obstacle_avoidance.h"
#include "motors.h"
#include "sensors.h"
#include "leds.h"

// Function to perform Task 1: Obstacle Avoidance and Space Exploration
void task1_obstacle_avoidance(void) {
    int proximity_reading[8] = {0};
    for (int i = 0; i < 8; i++) {
        proximity_reading[i] = get_calibrated_prox(i);
    }

    int threshold = 300;
    
    // Obstacle avoidance logic
    if (proximity_reading[0] > threshold || proximity_reading[1] > threshold || proximity_reading[2] > 500) {
        left_motor_set_speed(-800);
        right_motor_set_speed(800); // Turn left
        set_led(LED7, 1);
    } else if (proximity_reading[7] > threshold || proximity_reading[6] > threshold || proximity_reading[5] > 500) {
        left_motor_set_speed(800);
        right_motor_set_speed(-800); // Turn right
        set_led(LED3, 1);
    } else {
        left_motor_set_speed(800);
        right_motor_set_speed(800); // Move forward
        set_led(LED1, 1);
    }
    
    // Additional task-specific logic for Task 1 can be added here
}
