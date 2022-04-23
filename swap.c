#include "push_swap.h"

void sa(t_dlst *a, t_dlst *b, bool flag) {
    (void)b;
    if (a->next->next->is_dummy)
        return;
    t_dlst *first = a->next;
    t_dlst *second = first->next;
    long tmp = first->num;
    first->num = second->num;
    second->num = tmp;
    if (flag)
        ft_putstr_fd("sa\n", 1);
}

void sb(t_dlst *a, t_dlst *b, bool flag) {
    (void)a;
    if (b->next->next->is_dummy)
        return;
    t_dlst *first = b->next;
    t_dlst *second = first->next;
    long tmp = first->num;
    first->num = second->num;
    second->num = tmp;
    if (flag)
        ft_putstr_fd("sb\n", 1);
}

void ss(t_dlst *a, t_dlst *b, bool flag) {
    sa(a, b, false);
    sb(a, b, false);
    if (flag)
        ft_putstr_fd("ss\n", 1);
}
