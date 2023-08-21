#include <stdio.h>

#define MAX(a, b, c) ((a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c))
#define MIN(a, b, c) ((a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c))
#define SET_BIT(mask, bit) ((mask) |= (1U << (bit)))
#define CLEAR_BIT(mask, bit) ((mask) &= ~(1U << (bit)))
#define CHECK_BIT(mask, bit) ((mask) & (1U << (bit)))
#define INVERSE_BIT(mask, bit) ((mask) ^= (1U << (bit)))

#define SWAP(a, b) do { typeof(a) temp = (a); (a) = (b); (b) = temp; } while (0)