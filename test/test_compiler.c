#include "../header/compiler.h"
#include <stdio.h>
#include <assert.h>

void test_compile_simple() {
    int result = compile("2 + 3");
    assert(result == 5);
    
    printf("✓ test_compile_simple passed\n");
}

void test_compile_with_parentheses() {
    int result = compile("(5 + 3) * 2");
    assert(result == 16);
    
    printf("✓ test_compile_with_parentheses passed\n");
}

void test_compile_complex() {
    int result = compile("10 + 2 * 3 - 1");
    assert(result == 15); // 10 + (2*3) - 1 = 10 + 6 - 1 = 15
    
    printf("✓ test_compile_complex passed\n");
}

void test_compile_division() {
    int result = compile("20 / 4 + 3");
    assert(result == 8); // (20/4) + 3 = 5 + 3 = 8
    
    printf("✓ test_compile_division passed\n");
}

void test_compile_multiplication() {
    int result = compile("2 * 3 * 4");
    assert(result == 24);
    
    printf("✓ test_compile_multiplication passed\n");
}

void run_compiler_tests() {
    printf("Running compiler tests...\n");
    test_compile_simple();
    test_compile_with_parentheses();
    test_compile_complex();
    test_compile_division();
    test_compile_multiplication();
    printf("All compiler tests passed!\n\n");
}
