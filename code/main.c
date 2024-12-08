#include "ch.h"
#include "hal.h"
#include "motors.h"
#include "sensors.h"
#include "VL53L0X.h"
#include "leds.h"
#include "spi_comm.h"
#include "proximity.h"

int main(void) {
    // Initialize the hardware and communication systems
    halInit();
    chSysInit();
    mpu_init();
    messagebus_init(&bus, &bus_lock, &bus_condvar);

    // Initialize motors, proximity sensors, and distance sensors
    motors_init();
    proximity_start();
    calibrate_ir();
    VL53L0X_start();

    // Main loop
    while (1) {
        task1_obstacle_avoidance();
        task2_trailing_object();
        chThdSleepMilliseconds(100);  // Adjust based on your task's time interval
    }
}
