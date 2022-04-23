#include "push_swap.h"

void sort_b(t_dlst *a, t_dlst *b, long min, long size) {
    long i;
    long tmp;

    if (size == 2) {
        if (dlst_front_num(b, 0) < dlst_front_num(b, 1))
            sb(a, b, true);
        pa(a, b, true);
        pa(a, b, true);
    }
    if (size == 1)
        pa(a, b, true);
    if (size <= 2)
        return;

    tmp = 0;
    i = 0;
    while (i < size) {
        // rb
        if (dlst_front_num(b, 0) <= get_border(min, size, 0)) {
            if (tmp > 0) {
                rr(a, b, true);
                tmp--;
            }
            else
                rb(a, b, true);
        }
        // pa ra
        else if (dlst_front_num(b, 0) <= get_border(min, size, 1)) {
            pa(a, b, true);
            // ra(a, b, true);
            tmp++;
        }
        // pa
        else {
            while (tmp > 0) {
                ra(a, b, true);
                tmp--;
            }
            pa(a, b, true);
        }
        i++;
    }
    while (tmp-- > 0)
        ra(a, b, true);

    sort_a(a, b, get_min(min, size, 2), get_size(min, size, 2));
    
    i = 0;
    while (i < get_size(min, size, 0) || i < get_size(min, size, 1)) {
        if (i < get_size(min, size, 0) && i < get_size(min, size, 1))
            rrr(a, b, true);
        else if (i < get_size(min, size, 0))
            rrb(a, b, true);
        else
            rra(a, b, true);
        i++;
    }
    sort_a(a, b, get_min(min, size, 1), get_size(min, size, 1));
    sort_b(a, b, get_min(min, size, 0), get_size(min, size, 0));
}