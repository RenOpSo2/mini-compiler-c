#include "../header/lexer.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

void test_lexer_number() {
    init_lexer("123");
    Token token = get_next_token();
    
    assert(token.type == TOKEN_NUMBER);
    assert(token.value == 123);
    assert(strcmp(token.text, "123") == 0);
    
    printf("✓ test_lexer_number passed\n");
}

void test_lexer_operator() {
    init_lexer("+");
    Token token = get_next_token();
    
    assert(token.type == TOKEN_PLUS);
    
    init_lexer("-");
    token = get_next_token();
    assert(token.type == TOKEN_MINUS);
    
    init_lexer("*");
    token = get_next_token();
    assert(token.type == TOKEN_MUL);
    
    init_lexer("/");
    token = get_next_token();
    assert(token.type == TOKEN_DIV);
    
    printf("✓ test_lexer_operator passed\n");
}

void test_lexer_parentheses() {
    init_lexer("(");
    Token token = get_next_token();
    assert(token.type == TOKEN_LPAREN);
    
    init_lexer(")");
    token = get_next_token();
    assert(token.type == TOKEN_RPAREN);
    
    printf("✓ test_lexer_parentheses passed\n");
}

void test_lexer_whitespace() {
    init_lexer("   456   ");
    Token token = get_next_token();
    
    assert(token.type == TOKEN_NUMBER);
    assert(token.value == 456);
    
    printf("✓ test_lexer_whitespace passed\n");
}

void test_lexer_multiple_tokens() {
    init_lexer("123 + 456");
    
    Token token = get_next_token();
    assert(token.type == TOKEN_NUMBER && token.value == 123);
    
    token = get_next_token();
    assert(token.type == TOKEN_PLUS);
    
    token = get_next_token();
    assert(token.type == TOKEN_NUMBER && token.value == 456);
    
    token = get_next_token();
    assert(token.type == TOKEN_EOF);
    
    printf("✓ test_lexer_multiple_tokens passed\n");
}

void test_lexer_eof() {
    init_lexer("");
    Token token = get_next_token();
    assert(token.type == TOKEN_EOF);
    
    printf("✓ test_lexer_eof passed\n");
}

void run_lexer_tests() {
    printf("Running lexer tests...\n");
    test_lexer_number();
    test_lexer_operator();
    test_lexer_parentheses();
    test_lexer_whitespace();
    test_lexer_multiple_tokens();
    test_lexer_eof();
    printf("All lexer tests passed!\n\n");
}
