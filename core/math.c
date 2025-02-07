/*
 * math.c
 *
 *  Created on: 5 feb. 2025
 *      Author: geert
 */

#include "math.h"

int scale_int(int x, int in_min, int in_max, int out_min, int out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
