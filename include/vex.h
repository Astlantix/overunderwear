#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)