#include <stdio.h>
#include <stdbool.h>

char stack[30];
int top = 0;

bool spec = 0;
void push(char x){
    if (top == 30)
        printf("Full\n");
    else{
        stack[top] = x;
        top++;
    }
}

void pop(char x){
    if (top == 0)
        spec = 1;
    else{
        if (x == stack[top-1])
            top--;
    }
}

int main()
{
    char temp[30];
    scanf("%s", temp);

    for (int i = 0; temp[i] != '\0'; i++)
    {
        if (temp[i] == '(' || temp[i] == '{' || temp[i] == '[')
            push(temp[i]);
        else if (temp[i] == ')' || temp[i] == '}' || temp[i] == ']')
            pop(temp[i]);
    }

    for (int i = 0; i < top; i++){
        printf("%c", stack[i]);
    }
    if (top != 0)
        printf("Unbalanced");
    else
        printf("Balanced");
    return 0;
}
