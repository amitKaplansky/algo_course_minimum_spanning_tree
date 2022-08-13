#pragma once
#include "run.h"



int main(int argc, char* argv[]) {
    string from(argv[1]);
    string to(argv[2]);


    run(from, to);

    return 1;

}
