#include "mystring.h"

int main(void) {
    std::cout << "Input put file: ";
    char path_file[256];
    std::cin >> path_file;
    path p[100];
    p[0].input_path(path_file);
    p[0].output_path();
    p[1].input_path(path_file);
    p[1].output_path();
    p[0].delete_path();
    return 0;
}