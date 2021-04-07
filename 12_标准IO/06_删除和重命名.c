#include "stdio.h"


void f_remove(){
    remove("../test5-1.txt");
}

void f_rename(){
    rename("../test5.txt","../test5-1.txt");
}

int main(int argc, char const *argv[]) {
    // f_rename();
    f_remove();
}
