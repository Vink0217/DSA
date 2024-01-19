#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int size;
    int *s;
};

struct StackChar
{
    int top;
    int size;
    char *s;
};

void push(struct Stack *s, int data) //O(1)
{
    if (s->top == s->size - 1)
        printf("Overflow\n");
    else
    {
        s->top++;
        s->s[s->top] = data;
        //printf("Pushed %d\n", data);
    }
}

void pushChar(struct StackChar *s, char data) //O(1)
{
    if (s->top == s->size - 1)
        printf("Overflow\n");
    else
    {
        s->top++;
        s->s[s->top] = data;
        //printf("Pushed %d\n", data);
    }
}

int pop(struct Stack *st) //O(1)
{
    int x = -1;
    if (st->top == -1)
        printf("Underflow Error\n");
    else
    {
        x =(st->s[st->top--]);
        //printf("Popped %d", x);
        return x;
    }
}

char popChar(struct StackChar *st) //O(1)
{
    int x = -1;
    if (st->top == -1)
        printf("Underflow Error\n");
    else
    {
        x =(st->s[st->top--]);
        //printf("Popped %d", x);
        return x;
    }
}

int currtop(struct Stack s) // O(1)
{
    if (s.top == -1)
        return -1;
    else
        return s.s[s.top];
}

char currtopchar(struct StackChar s) // O(1)
{
    if (s.top == -1)
        return -1;
    else
        return s.s[s.top];
}

int peek(struct Stack s, int pos) // O(1)
{
    int x = -1;
    if ((s.top)- pos + 1 < 0)
        printf("Invalid index \n");
    else
    {
        x = s.s[(s.top) - pos + 1];
    }
    return x;
}

int isEmpty(struct Stack s)
{
    if (s.top == -1)
    {
        return 1;
        printf("Stack is empty. \n");
    }
    else
        return 0;
}

int isEmptyChar(struct StackChar s)
{
    if (s.top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct Stack s)
{
    if (s.top == s.size - 1)
    {
        return 1;
        printf("Stack is full. \n");
    }
    else
        return 0;
}

int isFullChar(struct StackChar s)
{
    if (s.top == s.size - 1)
        return 1;
    else
        return 0;
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

void display(struct Stack st)
{
    if (st.top == -1)
        printf("Empty Stack\n");
    else
    {
        printf("Stack: ");
        for (int i = st.top; i >= 0; i--)
        {
            printf("%d ", st.s[i]);
        }
        printf("\n");
    }
}

void create(struct Stack *st)
{
    printf("Enter size of stack: ");
    scanf("%d", &st->size);
    st->s = (int *)malloc(st->size * sizeof(int));
    st->top = -1; // by default top does not point to anywhere within stack so -1
} 

int ParanthesesBalance(char *exp)
{
    char y; //storing the popped values during runtime
    struct StackChar stexp;
    stexp.size = strlen(exp);
    stexp.s = (char *)malloc(stexp.size * sizeof(char)); //string array creation
    stexp.top = -1;

    for (int i = 0; i < stexp.size;i++)
    {
        if (exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
        {
            pushChar(&stexp, exp[i]); // push opening bracket into stack
        }                   
        else if(exp[i] == ')' || exp[i]==']' || exp[i]=='}') // when closing brackets encountered
        {
            if (stexp.top == -1) // if stack already empty return False
                return 0;
            else if ((exp[i]== currtopchar(stexp)+1) || (exp[i]==currtopchar(stexp)+2)) // checking via ascii code +1, +2 with opening gives closing bracket
            {
                y = popChar(&stexp); // otherwise pop from stack
            }
        }
    }
    if(stexp.top==-1) // after the processing if stack is empty, balanced
        return 1;
    else
        return 0; // otherwise unbalanced
}

char *InfixtoPostfix(char *infix)
{
    struct StackChar st; // initialize stack for processing postfix
    st.size=strlen(infix);
    st.top=-1;
    st.s = (char *)malloc((st.size + 1) * sizeof(char));

    int i, j;
    i = j = 0;
    int size = strlen(infix);
    char *postfix = (char *)malloc((size + 1) * sizeof(char)); //string array creation

    while (infix[i]!='\0') // check until end of expression string [a+b*c]
    {
        if (isOperand(infix[i])) // check if operand (a,b etc) postfix:[a] infix:[+b*c]
            postfix[j++] = infix[i++]; // push operand directly to postfix expr postfix:[a]
        else
        {
            if(precedence(infix[i]) > precedence(currtopchar(st))) //if infix operator precedence > stack top operator, push st:[+<*]
                pushChar(&st,infix[i++]); // push operator from infix into st
            else
                postfix[j++]=popChar(&st); // if lower precedence then pop stack top into postfix expr [pop '+' from st into postfix]
        }        
    }
 
    while(!isEmptyChar(st)) // Add remaining operators left in st until none left to postfix
    {
        postfix[j++]=popChar(&st);
    }
    postfix[j]='\0'; // Add end string character to postfix
 
    return postfix;
}

int EvalPostfix(char *postfix) // O(n) where n=strlen
{
    struct Stack eval; // initialize eval stack for evaluating postfix calcs
    eval.size=strlen(postfix);
    eval.top=-1;
    eval.s = (int *)malloc((eval.size + 1) * sizeof(int)); // int array since calc done w/ integers

    int i, x1, x2, res;

    for (i = 0; postfix[i] != '\0'; i++) // check until end of expression string [a+b*c]
    {
        if (isOperand(postfix[i])) // check for operand (a,b, etc.)
        {       
            push(&eval, postfix[i]-'0'); // push operands directly to eval stack
        }
        else if (!isOperand(postfix[i])) // check if operator encountered
        {
            x2 = pop(&eval); // pop 2nd and 1st operand to perform the operation with where [1st operation 2nd]
            x1 = pop(&eval); 
            switch (postfix[i]) //switch case for the operators (+,-,*,/)
            {
                case '+':
                    res = x1 + x2;
                    break;

                case '-':
                    res = x1 - x2;
                    break;

                case '*':
                    res = x1 * x2;
                    break;

                case '/':
                    res = x1 / x2;
                    break;
            }
            push(&eval, res); // keep pushing operand pair's resultant into the eval stack after computing
                              // either the evaluated result of the operands will stay in stack or operands until an operator encountered
        }        
    }
    currtop(eval); // finally print the eval result
}

void main()
{
    //struct Stack st;
    //create(&st);

    //push(&st,10);
    //push(&st,20);
    //push(&st,30);
    //push(&st,40);

    //printf("%d \n",peek(st,2));

    // display(st);


    char *exp = "[(a+b)]*{{c-d}]";
    if (ParanthesesBalance(exp))
    {
        printf("Balanced\n");
    }
    else
        printf("Unbalanced\n"); // printing unbalanced for false return

    char infix[] = "a+b*c-d/e";
    printf("Postfix: %s\n", InfixtoPostfix(infix));

    char postfix[] = "6324+-*";
    printf("Evaluated Postfix Result: %d\n", EvalPostfix(postfix));
}
