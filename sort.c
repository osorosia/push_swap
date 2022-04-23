#include "push_swap.h"

void sort(t_dlst *a, t_dlst *b) {
    if (dlst_size(a) <= 5)
        sort_5(a, b);
    else
        quick_sort(a, b);
}
