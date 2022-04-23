#include "push_swap.h"

int main(int argc, char **argv) {
    // if (argc < 2)
    //     error("usage: ./push_swap [number_list]");

    // char **number_list = create_number_list(argc, argv);
    // check_number_list(number_list);

    t_dlst *a = dlst_new_dummy();
    t_dlst *b = dlst_new_dummy();
    dlst_add_back(a, 10);
    dlst_add_back(a, 20);
    dlst_add_back(a, 30);
    print_dlst("a", a);
    print_dlst("b", b);
}
