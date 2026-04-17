#include "../header/parser.h"
#include "../header/lexer.h"
#include <stdio.h>
#include <assert.h>

void test_parser_single_number() {
    init_lexer("42");
    init_parser();
    int result = parse_expression();
    assert(result == 42);
    
    printf("✓ test_parser_single_number passed\n");
}

void test_parser_addition() {
    init_lexer("10 + 20");
    init_parser();
    int result = parse_expression();
    assert(result == 30);
    
    printf("✓ test_parser_addition passed\n");
}

void test_parser_subtraction() {
    init_lexer("30 - 15");
    init_parser();
    int result = parse_expression();
    assert(result == 15);
    
    printf("✓ test_parser_subtraction passed\n");
}

void test_parser_multiplication() {
    init_lexer("6 * 8");
    init_parser();
    int result = parse_expression();
    assert(result == 48);
    
    printf("✓ test_parser_multiplication passed\n");
}

void test_parser_division() {
    init_lexer("24 / 4");
    init_parser();
    int result = parse_expression();
    assert(result == 6);
    
    printf("✓ test_parser_division passed\n");
}

void test_parser_complex_expression() {
    init_lexer("2 + 3 * 4"); // Should be 2 + (3 * 4) = 14
    init_parser();
    int result = parse_expression();
    assert(result == 14);
    
    init_lexer("(2 + 3) * 4"); // Should be (2 + 3) * 4 = 20
    init_parser();
    result = parse_expression();
    assert(result == 20);
    
    printf("✓ test_parser_complex_expression passed\n");
}

void test_parser_precedence() {
    init_lexer("10 + 5 * 2 - 8 / 4"); // 10 + (5*2) - (8/4) = 10 + 10 - 2 = 18
    init_parser();
    int result = parse_expression();
    assert(result == 18);
    
    printf("✓ test_parser_precedence passed\n");
}

void run_parser_tests() {
    printf("Running parser tests...\n");
    test_parser_single_number();
    test_parser_addition();
    test_parser_subtraction();
    test_parser_multiplication();
    test_parser_division();
    test_parser_complex_expression();
    test_parser_precedence();
    printf("All parser tests passed!\n\n");
}
