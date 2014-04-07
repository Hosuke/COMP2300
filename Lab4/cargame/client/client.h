#ifndef CLIENT_H_
#define CLIENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

typedef enum
{
	SEN_NONE,
	SEN_WALL,
	SEN_CAR,
	SEN_FINISH
} SensorType;

typedef struct
{
	double accelaration;
	double steering;
	double speed;
	int laps;
	// Sensors:
	double sen_mid_dist;
	double sen_close_left_dist;
	double sen_close_right_dist;
	double sen_left_dist;
	double sen_right_dist;
	SensorType sen_mid_type;
	SensorType sen_close_left_type;
	SensorType sen_close_right_type;
	SensorType sen_left_type;
	SensorType sen_right_type;
} InputPacket;

typedef struct
{
	double accelaration;
	double steering;
	int tintr;
	int tintg;
	int tintb;
} OutputPacket;

// Implement this function:
void control(const InputPacket* inpack, OutputPacket* outpack);

#endif /* CLIENT_H_ */
