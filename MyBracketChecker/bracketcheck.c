#include <stdio.h>
#include <string.h>
#include "stack.h"

char closingBracket(char bracket)
{
    if(bracket == '(')
        return ')';
    if(bracket == '{')
        return '}';
    if(bracket == '[')
        return ']';    
}

int main()
{
    char str[100];
    int i, isBalanced = 1;

    Stack *S = newStack();  // Allocate a new stack
    if(S == NULL)
    {
        printf("\nStack could not be allocated.\n");
        return;
    }

    printf("\n\tARE YOUR BRACKETS BALANCED?\n");

    printf("\n\tEnter a set of parenthesis (or 'exit' to stop): \n\t");
    scanf("%s", str);
    
    while(strcmp(str, "exit") && strcmp(str, "EXIT"))
    {
        clear(S);   // Clear the stack contents
        isBalanced = 1;     // Set isBalanced flag to 1
        
        /* Loop to traverse the string */
        for(i = 0; str[i]; i++)
        {
            if(str[i] == '(' || str[i] == '{' || str[i] == '[') // If an opening bracket comes, push directly
                push(S, &str[i]);
            
            else    // Else a closing bracket comes
            {
                if(isEmpty(S))
                {
                    isBalanced = 0;
                    break;
                }

                char topElem = *(char *)peek(S);

                if(str[i] == closingBracket(topElem))
                    pop(S);
                else
                {
                    isBalanced = 0;
                    break;
                }
            }          
        }

        if(isBalanced == 0 || !isEmpty(S))
            printf("\n\tNot balanced. Need to work on that!\n\n");
        else
            printf("\n\tBalanced. That's good!\n\n");

        printf("\n\n\tEnter a set of parenthesis (or 'exit' to stop): \n\t");
        scanf("%s", str);
    }
}
