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