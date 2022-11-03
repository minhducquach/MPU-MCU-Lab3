/*
 * fsm.c
 *
 *  Created on: Nov 2, 2022
 *      Author: Minh Duc Quach
 */


#include "global.h"
#include "fsm_automatic.h"

int flagAmber = 0;

void fsm_automatic_run(){
	switch(status){
		case INIT:
			red_s = red_duration/1000;
			amber_s = amber_duration/1000;
			green_s = green_duration/1000;
			clear7SEGs();
			clearEN();
			clearLEDs(TOP_BOTTOM);
			clearLEDs(LEFT_RIGHT);
			if (isButtonPressed(0)){
				status = NORMAL;
			}
			break;
		case NORMAL:
			flagAmber = 0;
			status = RED;
			clearLEDs(TOP_BOTTOM);
			clearLEDs(LEFT_RIGHT);
			setTimer(TOP_BOTTOM, red_duration);
			setTimer(LEFT_RIGHT, green_duration);
			updateBuffer(red_s, 1);
			setTimerSecond(1000);
			setTimer7SEG(50);
			if (isButtonPressed(0)){
				clearAllLEDs();
				status = RED_MOD;
				red_s = red_duration/1000;
				updateBuffer(red_s, 2);
				setLEDs(TOP_BOTTOM, RED);
				setLEDs(LEFT_RIGHT, RED);
				setTimer(TOP_BOTTOM, 500);
				setTimer(LEFT_RIGHT, 500);
			}
			break;
		case RED:
			setLEDs(TOP_BOTTOM, RED);
			if (flagAmber == 0) setLEDs(LEFT_RIGHT, GREEN);
			else if (flagAmber == 1){
				setLEDs(LEFT_RIGHT, AMBER);
			}
			if (timerFlag[LEFT_RIGHT] == 1){
				flagAmber = 1;
				clearLEDs(LEFT_RIGHT);
				setLEDs(LEFT_RIGHT, AMBER);
				setTimer(LEFT_RIGHT, amber_duration);
			}
			if (timerFlag[TOP_BOTTOM] == 1){
				clearLEDs(TOP_BOTTOM);
				setTimer(TOP_BOTTOM, green_duration);
				status = GREEN;
				clearLEDs(LEFT_RIGHT);
				setTimer(LEFT_RIGHT, red_duration);
				flagAmber = 0;
				red_s = red_duration/1000;
				updateBuffer(green_s, 1);
				setTimerSecond(1000);
			}
			if (timerSecond == 1){
				updateBuffer(--red_s, 1);
				setTimerSecond(1000);
			}
			if (isButtonPressed(0)){
				clearAllLEDs();
				status = RED_MOD;
				red_s = red_duration/1000;
				updateBuffer(red_s, 2);
				setLEDs(TOP_BOTTOM, RED);
				setLEDs(LEFT_RIGHT, RED);
				setTimer(TOP_BOTTOM, 500);
				setTimer(LEFT_RIGHT, 500);
			}
			break;
		case AMBER:
			setLEDs(TOP_BOTTOM, AMBER);
			if (timerFlag[TOP_BOTTOM] == 1){
				clearLEDs(TOP_BOTTOM);
				setTimer(TOP_BOTTOM, red_duration);
				status = RED;
				clearLEDs(LEFT_RIGHT);
				setTimer(LEFT_RIGHT, green_duration);
				amber_s = amber_duration/1000;
				updateBuffer(red_s, 1);
				setTimerSecond(1000);
			}
			if (timerSecond == 1){
				updateBuffer(--amber_s, 1);
				setTimerSecond(1000);
			}
			if (isButtonPressed(0)){
				clearAllLEDs();
				status = RED_MOD;
				red_s = red_duration/1000;
				updateBuffer(red_s, 2);
				setLEDs(TOP_BOTTOM, RED);
				setLEDs(LEFT_RIGHT, RED);
				setTimer(TOP_BOTTOM, 500);
				setTimer(LEFT_RIGHT, 500);
			}
			break;
		case GREEN:
			setLEDs(TOP_BOTTOM, GREEN);
			setLEDs(LEFT_RIGHT, RED);
			if (timerFlag[TOP_BOTTOM] == 1){
				clearLEDs(TOP_BOTTOM);
				setTimer(TOP_BOTTOM, amber_duration);
				status = AMBER;
				green_s = green_duration/1000;
				updateBuffer(amber_s, 1);
				setTimerSecond(1000);
			}
			if (timerSecond == 1){
				updateBuffer(--green_s, 1);
				setTimerSecond(1000);
			}
			if (isButtonPressed(0)){
				clearAllLEDs();
				status = RED_MOD;
				red_s = red_duration/1000;
				updateBuffer(red_s, 2);
				setLEDs(TOP_BOTTOM, RED);
				setLEDs(LEFT_RIGHT, RED);
				setTimer(TOP_BOTTOM, 500);
				setTimer(LEFT_RIGHT, 500);
			}
			break;
		default:
			break;
	}
}
