#include <stdio.h>

#include <stack> // stack을 사용하기 위한 헤더파일

std::stack<int> stack;

int main(){
    char str[1000000];
    fgets(str, 1000000, stdin);

    int i = 0;
    while(str[i]!='\n'){
        if (str[i]=='<'){
            if (!stack.empty()){
                while(!stack.empty()){
                    printf("%c", stack.top());
                    stack.pop();
                }
            }
            while(str[i]!='>'){
                printf("%c", str[i++]);
            }
            printf(">");
            i++;
            continue;
        }

        if (str[i]==' '){
            while(!stack.empty()){
                printf("%c", stack.top());
                stack.pop();
            }
            printf(" ");
            i++;
            continue;
        }
        stack.push(str[i++]);
    }

    if (str[--i] != '>'){
        while(!stack.empty()){
            printf("%c", stack.top());
            stack.pop();
        }
    }

}