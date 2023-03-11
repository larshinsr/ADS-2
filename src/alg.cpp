// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cstdint>

double pown(double value, uint16_t n) {
    if (n == 0) {
        return 1;
    }
    if (value == 0) {
        return 0;
    } else {
        return value * pown(value, n - 1);
    }
}
uint64_t fact(uint16_t n) {
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}
double calcItem(double x, uint16_t n) {
    double result = pown(x,n) / fact(n);
    return result;
}
double expn(double x, uint16_t count) {
    double result = 0;
    for (uint16_t i = 0; i <= count; i++) {
        result += calcItem(x, i);
    }
    return result;
}
double sinn(double x, uint16_t count) {
    double result = 0;
    for (uint64_t i = 1; i <= count; i++) {
        result += pown(-1, i - 1) * calcItem(x, 2 * i - 1);
    }
    return result;
}
double cosn(double x, uint16_t count) {
    double result = 1.0;
    for (uint64_t i = 2; i <= count; i++) {
        result += pown(-1, i - 1) * calcItem(x, 2 * i - 2);
    }
    return result;
}
