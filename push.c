#include "push_swap.h"

void pa(t_dlst *a, t_dlst *b) {
    if (b->next->is_dummy)
        return;
    dlst_add_front(a, b->next->num);
    dlst_del_front(b);
    ft_putstr_fd("pa\n", 1);
}

void pb(t_dlst *a, t_dlst *b) {
    if (a->next->is_dummy)
        return;
    dlst_add_front(b, a->next->num);
    dlst_del_front(a);
    ft_putstr_fd("pb\n", 1);
}
