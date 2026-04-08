#include "../header/parser.h"
#include "../header/lexer.h"
#include <stdio.h>
#include <stdlib.h>

static Token current_token;

static void advance() {
    current_token = get_next_token();
}

static void match(TokenType expected) {
    if (current_token.type == expected)
        advance();
    else {
        fprintf(stderr, "Syntax error: expected %d got %d\n", expected, current_token.type);
        exit(1);
    }
}

void init_parser(void) {
    advance();
}

int parse_expression() {
    int value = parse_term();
    while (current_token.type == TOKEN_PLUS || current_token.type == TOKEN_MINUS) {
        TokenType op = current_token.type;
        advance();
        int right = parse_term();
        if (op == TOKEN_PLUS)
            value += right;
        else
            value -= right;
    }
    return value;
}

int parse_term() {
    int value = parse_factor();
    while (current_token.type == TOKEN_MUL || current_token.type == TOKEN_DIV) {
        TokenType op = current_token.type;
        advance();
        int right = parse_factor();
        if (op == TOKEN_MUL)
            value *= right;
        else
            value /= right;
    }
    return value;
}

int parse_factor() {
    if (current_token.type == TOKEN_NUMBER) {
        int value = current_token.value;
        advance();
        return value;
    } else if (current_token.type == TOKEN_LPAREN) {
        advance();
        int value = parse_expression();
        match(TOKEN_RPAREN);
        return value;
    } else {
        fprintf(stderr, "Syntax error: expected number or (\n");
        exit(1);
    }
}
