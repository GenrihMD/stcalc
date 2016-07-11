#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int *ptr;
int *ts;
int *bs;
void push(int i);
int pop(void);
int main(void)
{
  int x, y;
  char str[50];
  ptr = (int *) malloc(MAX*sizeof(int));
  if(!ptr) exit(1);
  ts = ptr;
  bs = ptr + MAX-1;
  do {
    printf(": ");
    fgets(str,sizeof(str), stdin);
    switch(*str) {
      case '+':
        x = pop();
        y = pop();
        printf("%d\n", x+y);
        push(x+y);
        break;
      case '-':
        x = pop();
        y = pop();
        printf("%d\n", y-x);
        push(y-x);
        break;
      case '*':
        x = pop();
        y = pop();
        printf("%d\n", y*x);
        push(y*x);
        break;
      case '/':
        x = pop();
        y = pop();
        if(x==0) {
        printf("Деление на 0.\n");
        break;
    }
      printf("%d\n", y/x);
      push(y/x);
      break;
      case '.':
      x = pop();
      push(x);
      printf("На вершине стека: %d\n", x);
      break;
      default:
      push(atoi(str));
      }
    } while(*str != 'q');
    return 0;
  }
    void push(int i)
  {
    if(ptr > bs) {
    printf("Стек полон\n");
    return;
  }
    *ptr = i;
    ptr++;
  }
  int pop(void)
  {
    ptr--;
    if(ptr < ts) {
    printf("Стек пуст\n");
    return 0;
  }
  return *ptr;
}
