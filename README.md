### Compiler Template With C Language

 mini compiler for education and learning about compilers
 you can modify it by adding something like codegen


## Components

| File | Description |
|------|-------------|
| `src/main.c` | Entry point – orchestrates compilation steps. |
| `src/lexer.c` + `header/lexer.h` | Tokenizes input source code. |
| `src/parser.c` + `header/parser.h` | Parses tokens and builds an AST (Abstract Syntax Tree). |
| `src/compiler.c` + `header/compiler.h` | Performs code generation / output transformation. |
| `header/token.h` | Defines token types and structures used across modules. |
| `Makefile` | Build automation – compile, clean, and run targets. |

## Requirements

- C compiler (GCC, Clang, or MSVC)
- `make` (optional, but recommended)

## Build & Run

### Build with Make

```bash
make
```

```bash
make test
```

## Refrensi
- [tutorial-build-compiler-part1](https://www.google.com/url?sa=t&source=web&rct=j&opi=89978449&url=https://norasandler.com/2017/11/29/Write-a-Compiler.html&ved=2ahUKEwjjhe-Sj92TAxUgTWwGHbl8FrYQFnoECBcQAQ&usg=AOvVaw30y4sHSOCf-sg_I0rZq2Km)

- [compiler-theory](https://en.wikipedia.org/wiki/Compiler)
