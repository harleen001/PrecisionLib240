#ifndef BITWISE_OPERATIONS_H
#define BITWISE_OPERATIONS_H

int bitwiseAnd(int a, int b);
int bitwiseOr(int a, int b);
int bitwiseXor(int a, int b);
int bitwiseNot(int num);
int leftShift(int num, int shiftAmount);
int rightShift(int num, int shiftAmount);
bool isBitSet(int num, int position);
int setBit(int num, int position);
int clearBit(int num, int position);
int toggleBit(int num, int position);

#endif  // BITWISE_OPERATIONS_H
