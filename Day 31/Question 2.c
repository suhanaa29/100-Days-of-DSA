/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.*/

#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    char stack[10000];
    int top = -1;

    for(int i = 0; s[i] != '\0'; i++) {

        // push opening brackets
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        }
        else {
            if(top == -1) return false;

            char t = stack[top--];

            if((s[i] == ')' && t != '(') ||
               (s[i] == '}' && t != '{') ||
               (s[i] == ']' && t != '[')) {
                return false;
            }
        }
    }

    return top == -1;
}
