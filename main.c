#include "push_swap.h"

int main(int argc, char **argv) {
    // if (argc < 2)
    //     error("usage: ./push_swap [number_list]");

    // char **number_list = create_number_list(argc, argv);
    // check_number_list(number_list);

    t_dlst *a = dlst_new_dummy();
    t_dlst *b = dlst_new_dummy();
    dlst_add_back(a, 1);
    dlst_add_back(a, 11);
    dlst_add_back(a, 111);
    dlst_add_back(b, 2);
    dlst_add_back(b, 22);
    dlst_add_back(b, 222);
    print_dlst("a", a);
    print_dlst("b", b);
    pa(a, b); print_dlst("a", a); print_dlst("b", b);
    pb(a, b); print_dlst("a", a); print_dlst("b", b);
    ra(a, b); print_dlst("a", a); print_dlst("b", b);
    rra(a, b); print_dlst("a", a); print_dlst("b", b);
    rb(a, b); print_dlst("a", a); print_dlst("b", b);
    rrb(a, b); print_dlst("a", a); print_dlst("b", b);
    rr(a, b); print_dlst("a", a); print_dlst("b", b);
    rrr(a, b); print_dlst("a", a); print_dlst("b", b);
    sa(a, b); print_dlst("a", a); print_dlst("b", b);
    sb(a, b); print_dlst("a", a); print_dlst("b", b);
    dlst_free(a);
    dlst_free(b);
}
