/*
 * display.h
 *
 *  Created on: Nov 2, 2022
 *      Author: Minh Duc Quach
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

void clearLEDs(int);
void clear7SEGs();
void clearEN();
void clearAllLEDs();

void openAllLEDs();
void blinkLEDs(int, int);

void setLEDs(int, int);
//void set7SEGs_Timer(int, int);
//void set7SEGs_Mode(int, int);

void display7SEG(int, int);
void update7SEG(int);

//void loadBuffer(int, int);
void updateBuffer(int, int);
#endif /* INC_DISPLAY_H_ */
