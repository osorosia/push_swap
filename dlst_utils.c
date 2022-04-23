#include "push_swap.h"

long dlst_size(t_dlst *dummy) {
    return dummy->size;
}

long dlst_all_size(t_dlst *a, t_dlst *b) {
    return dlst_size(a) + dlst_size(b);
}

void dlst_free(t_dlst *dummy) {
    t_dlst *next;
    t_dlst *now;

    now = dummy->next;
    while (!now->is_dummy) {
        next = now->next;
        free(now);
        now = next;
    }
    free(dummy);
}

void print_dlst(char *dlst_name, t_dlst *dummy) {
    ft_putstr_fd(dlst_name, 2);
    ft_putstr_fd(": ", 2);
    dummy = dummy->next;
    while (!dummy->is_dummy) {
        ft_putnbr_fd(dummy->num, 2);
        ft_putstr_fd(" ", 2);
        dummy = dummy->next;
    }
    ft_putstr_fd("\n", 2);
}
