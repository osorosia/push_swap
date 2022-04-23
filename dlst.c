#include "push_swap.h"

t_dlst *dlst_new_dummy() {
    t_dlst *dlst = ft_calloc(1, sizeof(t_dlst));
    if (dlst == NULL)
        error("malloc error");
    dlst->prev = dlst;
    dlst->next = dlst;
    dlst->is_dummy = true;
    return dlst;
}

t_dlst *dlst_new(t_dlst *prev, t_dlst *next, long num) {
    t_dlst *dlst = ft_calloc(1, sizeof(t_dlst));
    if (dlst == NULL)
        error("malloc error");
    dlst->prev = prev;
    dlst->next = next;
    dlst->num = num;
    dlst->is_dummy = false;
    return dlst;
}

void dlst_add_numbers(t_dlst *dummy, char **numbers) {
    long i;

    i = 0;
    while (numbers[i]) {
        dlst_add_back(dummy, atoi_or_err(numbers[i]));
        i++;
    }
}

void dlst_add_back(t_dlst *dummy, long num) {
    t_dlst *prev = dummy->prev;
    t_dlst *next = dummy;

    t_dlst *new = dlst_new(prev, next, num);
    prev->next = new;
    next->prev = new;
}

void dlst_add_front(t_dlst *dummy, long num) {
    t_dlst *prev = dummy;
    t_dlst *next = dummy->next;

    t_dlst *new = dlst_new(prev, next, num);
    prev->next = new;
    next->prev = new;
}

void dlst_del_back(t_dlst *dummy) {
    if (dummy->next->is_dummy)
        return;
    t_dlst *target = dummy->prev;
    t_dlst *prev = target->prev;
    t_dlst *next = target->next;
    free(target);
    prev->next = next;
    next->prev = prev;
}

void dlst_del_front(t_dlst *dummy) {
    if (dummy->next->is_dummy)
        return;
    t_dlst *target = dummy->next;
    t_dlst *prev = target->prev;
    t_dlst *next = target->next;
    free(target);
    prev->next = next;
    next->prev = prev;
}

long dlst_size(t_dlst *dummy) {
    long size;
    dummy = dummy->next;
    size = 0;
    while (!dummy->is_dummy) {
        size++;
        dummy = dummy->next;
    }
    return size;
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
