#include "mystring.h"

void File(work_string p);

int main(void) {
    work_string *p[100] = {NULL};
    int flag =1, i = 0;
    while (flag){
        if (p[i] == NULL){
                std::cout << "Input put file: ";
                char path_file[256];
                std::cin >> path_file;
                p[i] = new work_string(path_file);
        }
        p[i]->output_path();
        char ch;
        std::cin >> ch;
        switch (ch){
            case ('1'):{
                std::cout << "Input put file: ";
                char path_file[256];
                std::cin >> path_file;
                p[i]->input_path(path_file);
                break;
            }
            case('2'):{
                if (i<99){
                    i++;
                }
                break;
            }
            case('3'):{
                if (i>0){
                    i--;
                }
                break;
            }
            case('4'):{
                File(*p[i]);
                break;
            }
            case('5'):{
                flag=0;
                break;
            }
            default:{
                break;
            }
        }
    }
    i=0;
    while ((p[i]!=NULL) && (i<100)){
        p[i]->delete_path();
        delete(p[i]);
        i++;
    }
    return 0;
}

void File(work_string p){
    int flag =1;
    while (flag){
        p.output_path();
        char ch;
        std::cin >> ch;
        switch (ch){
            case ('1'):{
                p.output_file();
                break;
            }
            case ('2'):{
                int n;
                std::cin >> n;
                p.output_file(n);
                break;
            }
            case ('3'):{
                int n, k;
                std::cin >> n;
                std::cin >> k;
                p.cat_string(n, k);
                break;
            }
            case('5'):{
                flag=0;
                break;
            }
            default:{
                break;
            }
        }
    }
}