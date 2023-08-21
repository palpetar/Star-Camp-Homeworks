#include <stdio.h>

#define MAX(a, b, c) ((a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c))
#define MIN(a, b, c) ((a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c))
