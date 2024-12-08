#include "task2_trailing_object.h"
#include "motors.h"
#include "sensors.h"
#include "leds.h"

// Function to perform Task 2: Trailing an Object
void task2_trailing_object(void) {
    int proximity_reading[8] = {0};
    for (int i = 0; i < 8; i++) {
        proximity_reading[i] = get_calibrated_prox(i);
    }

    int threshold_2 = 60;
    
    if (proximity_reading[0] < 50) {
        left_motor_set_speed(600);  // Go straight
        right_motor_set_speed(600);
        set_led(LED1, 1);
    } else if (proximity_reading[0] > 50) {
        left_motor_set_speed(-600);  // Move backward
        right_motor_set_speed(-600);
        set_led(LED5, 1);
    }
    
    // Object trailing logic based on proximity sensor readings
    if (proximity_reading[1] > threshold_2 || proximity_reading[2] > threshold_2 || proximity_reading[3] > threshold_2) {
        left_motor_set_speed(800); // Turn right
        right_motor_set_speed(-800);
        set_led(LED3, 1);
    } else if (proximity_reading[4] > threshold_2 || proximity_reading[5] > threshold_2 || proximity_reading[6] > threshold_2) {
        left_motor_set_speed(-800); // Turn left
        right_motor_set_speed(800);
        set_led(LED7, 1);
    }
}
