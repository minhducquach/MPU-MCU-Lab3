/*
 * software_timer.h
 *
 *  Created on: Nov 2, 2022
 *      Author: Minh Duc Quach
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "global.h"

#define NO_OF_COUNTERS	2
#define PERIOD			10

extern int timerFlag[NO_OF_COUNTERS];
extern int timer7SEG;
extern int timerSecond;

void setTimer7SEG(int);
void setTimerSecond(int);
void setTimer(int, int);

void timerRun();
void timerRun7SEG();
void timerRunSecond();

#endif /* INC_SOFTWARE_TIMER_H_ */
