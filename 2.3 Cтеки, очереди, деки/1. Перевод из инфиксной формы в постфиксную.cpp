#include <iostream>

using namespace std;

#define MAX 2000

typedef struct stek {
  int data[MAX];
  int top;
} stek;

int lead(char x) {
  if (x == '(') return (0);
  if (x == '+' || x == '-') return (1);
  if (x == '*' || x == '/' || x == '%') return (2);

  return (3);
}

void init(stek* s) { s->top = -1; }

int nul(stek* s) {
  if (s->top == -1) return (1);

  return (0);
}

int full(stek* s) {
  if (s->top == MAX - 1) return (1);

  return (0);
}

int pop(stek* s) {
  int x;
  x = s->data[s->top];
  s->top = s->top - 1;
  return (x);
}

void push(stek* s, int x) {
  s->top = s->top + 1;
  s->data[s->top] = x;
}

int first(stek* p) { return (p->data[p->top]); }

void to_post(char infix[], char postfix[]) {
  stek s;
  char x, token;
  int i, j;
  init(&s);
  j = 0;

  for (i = 0; infix[i] != '\0'; i++) {
    token = infix[i];
    if (isalnum(token))
      postfix[j++] = token;
    else if (token == '(')
      push(&s, '(');
    else if (token == ')')
      while ((x = pop(&s)) != '(') postfix[j++] = x;
    else {
      while (lead(token) <= lead(first(&s)) && !nul(&s)) {
        x = pop(&s);
        postfix[j++] = x;
      }
      push(&s, token);
    }
  }

  while (!nul(&s)) {
    x = pop(&s);
    postfix[j++] = x;
  }

  postfix[j] = '\0';
}

int main() {
  char infix[2000], postfix[2000];
  gets_s(infix);
  to_post(infix, postfix);
  cout << (postfix);
  return 0;
}