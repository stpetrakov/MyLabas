#include <assert.h>
#include <stdio.h>
#include <stdlib.h> 
#include "Tests/tests.h"

int main(int argc, char *argv[]) {
    assert (argc == 2);

    int arg = atoi (argv[1]); 
    test (arg);

    return 0;
}