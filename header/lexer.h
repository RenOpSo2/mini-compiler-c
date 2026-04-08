#ifndef LEXER_H
#define LEXER_H

#include "token.h"

typedef struct {
    const char* input;
    int position;
} Lexer;

void init_lexer(const char* source);
Token get_next_token(void);

#endif
