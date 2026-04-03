#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <ctype.h>  
#include <string.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

// 스택 초기화
void initStack(Stack* s) {
    s->top = -1;
}

// 스택이 비었는지 확인
int isEmpty(Stack* s) {
    return s->top == -1;
}

// 스택에 요소 추가
void push(Stack* s, int value) {
    s->data[++(s->top)] = value;
}

// 스택에서 요소 제거
int pop(Stack* s) {
    if (isEmpty(s)) return '\0';
    return s->data[(s->top)--];
}

// 스택 최상단 요소 반환
int peek(Stack* s) {
    if (isEmpty(s)) return '\0';
    return s->data[s->top];
}

void display(Stack* s) {
    if (isEmpty(s)) {
        printf("스택이 비어 있습니다!\n");
        return;
    }
    printf("스택 내용: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

// 괄호 쌍이 일치하는지 확인
int isMatching(char open, char close) {
        if (open == '(' && close == ')') 
			return 1;
        if (open == '{' && close == '}') 
			return 1;
        if (open == '[' && close == ']')
			return 1;
        return 0;
}
    
int main() {
    Stack s;
    char str[MAX];
    initStack(&s);
    int isValid = 1; 

    printf("문자열을 입력하시오: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            // 스택이 비어있거나 팝한 여는 괄호와 현재 닫는 괄호가 매칭되지 않으면 유효하지 않음
            if (isEmpty(&s) || !isMatching(pop(&s), ch)){
                isValid = 0;
                break;
            }
        }
    }

    // 모든 문자를 처리한 후 스택이 비어있지 않으면 유효하지 않음
    if (!isEmpty(&s)) isValid = 0;

    if (isValid) printf("괄호가 올바르게 짝지어져 있습니다.\n");
    else printf("괄호가 올바르지 않습니다.\n");

    return 0;
}
