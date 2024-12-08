CC = gcc
CFLAGS = -std=c99 -Wall
SRC = main.c motors.c sensors.c task1_obstacle_avoidance.c task2_trailing_object.c
OBJ = $(SRC:.c=.o)
EXEC = epuck2_control

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(EXEC)

