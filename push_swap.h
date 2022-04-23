#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "./libft/libft.h"

typedef struct s_dlst t_dlst;
struct s_dlst {
    t_dlst *prev;
    t_dlst *next;
    bool is_dummy;
    long num;
};

// number_list.c


// swap.c
void sa(t_dlst *a, t_dlst *b);
void sb(t_dlst *a, t_dlst *b);
void ss(t_dlst *a, t_dlst *b);

// push.c
void pa(t_dlst *a, t_dlst *b);
void pb(t_dlst *a, t_dlst *b);

// rotate.c
void ra(t_dlst *a, t_dlst *b);
void rb(t_dlst *a, t_dlst *b);
void rr(t_dlst *a, t_dlst *b);

// rrotate.c
void rra(t_dlst *a, t_dlst *b);
void rrb(t_dlst *a, t_dlst *b);
void rrr(t_dlst *a, t_dlst *b);

// dlst.c
t_dlst *dlst_new_dummy();
t_dlst *dlst_new(t_dlst *prev, t_dlst *next, long num);
void dlst_add_back(t_dlst *dummy, long num);
void dlst_add_front(t_dlst *dummy, long num);
void dlst_del_back(t_dlst *dummy);
void dlst_del_front(t_dlst *dummy);
long dlst_size(t_dlst *dummy);
void print_dlst(char *dlst_name, t_dlst *dummy);

// utils.c
void error(char *str);

#endif