#include "push_swap.h"

void sa_no_print(t_dlst *a, t_dlst *b) {
    (void)b;
    if (a->next->next->is_dummy)
        return;
    t_dlst *first = a->next;
    t_dlst *second = first->next;
    long tmp = first->num;
    first->num = second->num;
    second->num = tmp;
}

void sb_no_print(t_dlst *a, t_dlst *b) {
    (void)a;
    if (b->next->next->is_dummy)
        return;
    t_dlst *first = b->next;
    t_dlst *second = first->next;
    long tmp = first->num;
    first->num = second->num;
    second->num = tmp;
}

void sa(t_dlst *a, t_dlst *b) {
    sa_no_print(a, b);
    ft_putstr_fd("sa\n", 1);
}

void sb(t_dlst *a, t_dlst *b) {
    sb_no_print(a, b);
    ft_putstr_fd("sb\n", 1);
}

void ss(t_dlst *a, t_dlst *b) {
    sa_no_print(a, b);
    sb_no_print(a, b);
    ft_putstr_fd("sb\n", 1);
}
