#include "push_swap.h"

void rra_no_print(t_dlst *a, t_dlst *b) {
    (void)b;
    if (a->prev->prev->is_dummy)
        return;
    dlst_add_front(a, a->prev->num);
    dlst_del_back(a);
}

void rrb_no_print(t_dlst *a, t_dlst *b) {
    (void)a;
    if (b->prev->prev->is_dummy)
        return;
    dlst_add_front(b, b->prev->num);
    dlst_del_back(b);
}

void rra(t_dlst *a, t_dlst *b) {
    rra_no_print(a, b);
    ft_putstr_fd("rra\n", 1);
}

void rrb(t_dlst *a, t_dlst *b) {
    rrb_no_print(a, b);
    ft_putstr_fd("rrb\n", 1);
}

void rrr(t_dlst *a, t_dlst *b) {
    rra_no_print(a, b);
    rrb_no_print(a, b);
    ft_putstr_fd("rrr\n", 1);
}
