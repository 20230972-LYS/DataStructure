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
