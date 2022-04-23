#include "push_swap.h"

long get_border(long min, long size, long index) {
    if (index == 0)
        return size / 3 + ((size % 3) > 0) + min - 1;
    if (index == 1)
        return size / 3 * 2 + size % 3 + min - 1;
}

long get_size(long min, long size, long index) {
    if (index == 0)
        return get_border(min, size, 0) - min + 1;
    else if (index == 1)
        return get_border(min, size, 1) - get_border(min, size, 0);
    else
        return size - (get_border(min, size, 1) - min + 1);
}

long get_min(long min, long size, long index) {
    if (index == 0)
        return min;
    if (index == 1)
        return get_border(min, size, 0) + 1;
    if (index == 2)
        return get_border(min, size, 1) + 1;
}
