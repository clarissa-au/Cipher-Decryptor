/*
 * CiphertextFunctions.h
 *
 *  Created on: 5 Jan 2018
 *      Author: sunnyau
 */

#ifndef CIPHERTEXTFUNCTIONS_H_
#define CIPHERTEXTFUNCTIONS_H_

struct Ciphertext;

int initText(struct Ciphertext *text);
void insertText(struct Ciphertext *text, char c);
void resetText(struct Ciphertext *text);//please reset the bool Textexist if using.
void freeText(struct Ciphertext *text);//please reset the bool Textexist if using.

#endif /* CIPHERTEXTFUNCTIONS_H_ */
