#include "push_swap.h"

void ra_no_print(t_dlst *a, t_dlst *b) {
    (void)b;
    if (a->next->next->is_dummy)
        return;
    dlst_add_back(a, a->next->num);
    dlst_del_front(a);
}

void rb_no_print(t_dlst *a, t_dlst *b) {
    (void)a;
    if (b->next->next->is_dummy)
        return;
    dlst_add_back(b, b->next->num);
    dlst_del_front(b);
}

void ra(t_dlst *a, t_dlst *b) {
    ra_no_print(a, b);
    ft_putstr_fd("ra\n", 1);
}

void rb(t_dlst *a, t_dlst *b) {
    rb_no_print(a, b);
    ft_putstr_fd("rb\n", 1);
}

void rr(t_dlst *a, t_dlst *b) {
    ra_no_print(a, b);
    rb_no_print(a, b);
    ft_putstr_fd("rr\n", 1);
}
