#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// トークンの種類
typedef enum {
  TK_RESERVED, // 記号
  TK_NUM,      // 整数トークン
  TK_EOF,      // 入力の終わりを表すトークン
} TokenKind;

typedef struct Token Token;

// トークン型
struct Token {
  TokenKind kind; // トークンの型
  Token *next;    // 次の入力トークン
  int val;        // kindがTK_NUMの場合、その数値
  char *str;      // トークン文字列
};

// parse.c

extern Token *token;

bool consume(char op);
void expect(char op);
int expect_number();
bool at_eof();

// token.c

Token *new_token(TokenKind kind, Token *cur, char *str);
Token *tokenize(char *p);

// util.c

extern char *user_input;

void error(char *fmt, ...);
void error_at(char *loc, char *fmt, ...);
