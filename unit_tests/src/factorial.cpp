/*
 * factorial.cpp
 *
 *  Created on: 31-Oct-2020
 *      Author: anantha
 */

#include "factorial.h"


int factorial(int n) {
        int result = 1;
        for (int i = 1; i <= n; i++) {
                result *= i;
         }
        return result;
}
