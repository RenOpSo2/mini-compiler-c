#include <stdio.h>

// Forward declarations
void run_lexer_tests();
void run_parser_tests();
void run_compiler_tests();

int main() {
    printf("=== Running Mini Compiler Tests ===\n\n");
    
    run_lexer_tests();
    run_parser_tests();
    run_compiler_tests();
    
    printf("=== All tests completed successfully! ===\n");
    return 0;
}
