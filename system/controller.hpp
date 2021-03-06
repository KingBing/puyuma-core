#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>

#include <ros/ros.h>

#define THROTTLE_BASE 35 //35% of the throttle

using namespace std;

enum ControllerMode {
	STOP_MODE,
	SELF_DRIVING_MODE,
	PRE_INTERSECTION,
	INTERSECTION,
	JOYSTICK_MODE
};

enum Direction {
	STRAIGHT,
	RIGHT,
	LEFT
};

typedef struct {
	float kp, ki, kd;

	bool been_halted;
	bool been_init;

	float previous_error;
	float previous_i_term;

	ros::Time previous_time; //XXX:This is not realtime!
} pid_control_t;

bool load_pid_param(string _yaml_path);
void self_driving_controller(float d, float phi);
void pid_halt();
void intersection_controller(enum Direction direction, bool get_pose, float d, float phi);

void bound(int min, int max, int& x);

#endif
