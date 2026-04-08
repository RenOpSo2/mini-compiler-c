#include "../header/compiler.h"
#include "../header/lexer.h"
#include "../header/parser.h"

int compile(const char* source) {
    init_lexer(source);
    init_parser();
    int result = parse_expression();
    return result;
}
