#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Stack {
    int top;
    int size;
    int* a; 
};

void stack_create(struct Stack * s)
{
    s->size = 1;

    s->a = (int*)malloc(s->size * sizeof(int));
    
    s->top = -1;
    return;
}

void push(struct Stack * s, int x)
{
    assert((int*)realloc(s->a, sizeof(int) * s->size) != NULL);

    s->size = s->size + 1;
    
    s->a = (int*)realloc(s->a, sizeof(int) * s->size);
    
    s->top++;
    s->a[s->top] = x;
    return;
}

int pop(struct Stack * s)
{
    if (s->top >= 0)
    {
        s->top--;
        return 1;
    }

    return -1;
}
int getlast(struct Stack * s)
{
    if (s->top >= 0)
    {
        int last = s->a[s->top];
        return last;
    }

    return -1;
}

int main()
{
    struct Stack s;
    stack_create(&s);
    char* str = calloc(102400, sizeof(char));
    scanf("%s", str);
    int co = 0, cc = 0;
    if (str[0] == ']' || str[0] == ')' || str[0] == '>' || str[0] == '}')
    {
        printf("NO");
        return 0;
    }
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '<' || str[i] == '{' || str[i] == '[' || str[i] == '(')
        {
            push(&s, str[i]);
            co++;
        }
        else if (str[i] == '>' || str[i] == '}' || str[i] == ']' || str[i] == ')')
        {
            cc++;
            if (getlast(&s) == '<' && str[i] == '>')
            {
                pop(&s);
            }
            else if (getlast(&s) == '[' && str[i] == ']')
            {
                pop(&s);
            }
            else if (getlast(&s) == '{' && str[i] == '}')
            {
                pop(&s);
            }
            else if (getlast(&s) == '(' && str[i] == ')')
            {
                pop(&s);
            }
        }
    }
    if ((getlast(&s) == -1) && (co == cc)) 
    {
        printf("YES");
        return 0;
    }
    else
    {
        printf("NO");
        return 0;
    }
    free(&s);
}