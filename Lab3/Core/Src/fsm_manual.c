/*
 * fsm_manual.c
 *
 *  Created on: Nov 3, 2022
 *      Author: Minh Duc Quach
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch(status){
	case RED_MOD:
		if (timerFlag[TOP_BOTTOM] == 1){
			blinkLEDs(TOP_BOTTOM, RED);
			setTimer(TOP_BOTTOM, 500);
		}
		if (timerFlag[LEFT_RIGHT] == 1){
			blinkLEDs(LEFT_RIGHT, RED);
			setTimer(LEFT_RIGHT, 500);
		}
		if (isButtonPressed(0)){
			clearAllLEDs();
			status = AMBER_MOD;
			updateBuffer(amber_s, 3);
			setLEDs(TOP_BOTTOM, AMBER);
			setLEDs(LEFT_RIGHT, AMBER);
			setTimer(TOP_BOTTOM, 500);
			setTimer(LEFT_RIGHT, 500);
		}
		if (isButtonPressed(1)){
			red_s++;
			if (red_s >= 100){
				red_s = 1;
			}
			updateBuffer(red_s, 2);
		}
		if (isButtonPressed(2)){
			red_duration = red_s * 1000;
		}
		break;
	case AMBER_MOD:
		if (timerFlag[TOP_BOTTOM] == 1){
			blinkLEDs(TOP_BOTTOM, AMBER);
			setTimer(TOP_BOTTOM, 500);
		}
		if (timerFlag[LEFT_RIGHT] == 1){
			blinkLEDs(LEFT_RIGHT, AMBER);
			setTimer(LEFT_RIGHT, 500);
		}
		if (isButtonPressed(0)){
			clearAllLEDs();
			status = GREEN_MOD;
			updateBuffer(green_s, 4);
			setLEDs(TOP_BOTTOM, GREEN);
			setLEDs(LEFT_RIGHT, GREEN);
			setTimer(TOP_BOTTOM, 500);
			setTimer(LEFT_RIGHT, 500);
		}
		if (isButtonPressed(1)){
			amber_s++;
			if (amber_s >= 100){
				amber_s = 1;
			}
			updateBuffer(amber_s, 3);
		}
		if (isButtonPressed(2)){
			amber_duration = amber_s * 1000;
		}
		break;
	case GREEN_MOD:
		if (timerFlag[TOP_BOTTOM] == 1){
			blinkLEDs(TOP_BOTTOM, GREEN);
			setTimer(TOP_BOTTOM, 500);
		}
		if (timerFlag[LEFT_RIGHT] == 1){
			blinkLEDs(LEFT_RIGHT, GREEN);
			setTimer(LEFT_RIGHT, 500);
		}
		if (isButtonPressed(0)){
			clearAllLEDs();
			status = NORMAL;
		}
		if (isButtonPressed(1)){
			green_s++;
			if (green_s >= 100){
				green_s = 1;
			}
			updateBuffer(green_s, 4);
		}
		if (isButtonPressed(2)){
			green_duration = green_s * 1000;
		}
		break;
	default:
		break;
	}
}
