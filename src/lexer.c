#include "../header/lexer.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

static Lexer lexer;

static char peek_char() {
    return lexer.input[lexer.position];
}

static char get_char() {
    return lexer.input[lexer.position++];
}

static void skip_whitespace() {
    while (isspace(peek_char()))
        get_char();
}

void init_lexer(const char* source) {
    lexer.input = source;
    lexer.position = 0;
}

Token get_next_token() {
    Token token;
    skip_whitespace();
    
    char current = peek_char();
    
    if (current == '\0') {
        token.type = TOKEN_EOF;
        return token;
    }
    
    if (isdigit(current)) {
        token.type = TOKEN_NUMBER;
        token.value = 0;
        int i = 0;
        while (isdigit(peek_char())) {
            int digit = get_char() - '0';
            token.value = token.value * 10 + digit;
            token.text[i++] = digit + '0';
        }
        token.text[i] = '\0';
        return token;
    }
    
    switch (current) {
        case '+': token.type = TOKEN_PLUS; get_char(); break;
        case '-': token.type = TOKEN_MINUS; get_char(); break;
        case '*': token.type = TOKEN_MUL; get_char(); break;
        case '/': token.type = TOKEN_DIV; get_char(); break;
        case '(': token.type = TOKEN_LPAREN; get_char(); break;
        case ')': token.type = TOKEN_RPAREN; get_char(); break;
        default:
            token.type = TOKEN_ERROR;
            sprintf(token.text, "Unknown char: %c", current);
            get_char();
            break;
    }
    return token;
}
