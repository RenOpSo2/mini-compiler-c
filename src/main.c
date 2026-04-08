#include "../header/compiler.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s \"expression\"\n", argv[0]);
        printf("Example: %s \"3 + 4 * 2\"\n", argv[0]);
        return 1;
    }
    
    int result = compile(argv[1]);
    printf("Result: %d\n", result);
    
    return 0;
}
