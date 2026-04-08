#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
    TOKEN_NUMBER,
    TOKEN_PLUS, TOKEN_MINUS, TOKEN_MUL, TOKEN_DIV,
    TOKEN_LPAREN, TOKEN_RPAREN,
    TOKEN_EOF,
    TOKEN_ERROR
} TokenType;

typedef struct {
    TokenType type;
    int value;
    char text[32];
} Token;

#endif
