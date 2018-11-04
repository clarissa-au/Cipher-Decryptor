/*
 * TrivialTools.h
 *
 *  Created on: 30 Jan 2018
 *      Author: sunnyau
 */

#ifndef TRIVIALTOOLS_H_
#define TRIVIALTOOLS_H_

#include"main.h"

struct args ArgsGet();
void ClearScreen();
void Read(char filec[]);
void Stat(char filec[]);
int LargestElement26(int array[26]);
void Swap(int *xp, int *yp);
void BubbleSort(int arr[], int n);
int Element26(int array[26], int place);

#endif /* TRIVIALTOOLS_H_ */
