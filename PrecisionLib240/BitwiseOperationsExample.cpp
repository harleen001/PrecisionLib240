#include "BitwiseOperations.h"

int bitwiseAnd(int a, int b) {
    return a & b;
}

int bitwiseOr(int a, int b) {
    return a | b;
}

int bitwiseXor(int a, int b) {
    return a ^ b;
}

int bitwiseNot(int num) {
    return ~num;
}

int leftShift(int num, int shiftAmount) {
    return num << shiftAmount;
}

int rightShift(int num, int shiftAmount) {
    return num >> shiftAmount;
}

bool isBitSet(int num, int position) {
    return (num & (1 << position)) != 0;
}

int setBit(int num, int position) {
    return num | (1 << position);
}

int clearBit(int num, int position) {
    return num & (~(1 << position));
}

int toggleBit(int num, int position) {
    return num ^ (1 << position);
}
