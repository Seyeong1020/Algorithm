#include <stdio.h>
int stack[21];
int top = -1;
void push(char c){
    stack[++top] = c;
}

void pop(){
    printf("%c", stack[top--]);
}

void solve(){
    char str[1000];
    fgets(str, 1000, stdin);

    int i = 0;
    while(str[i]!='\n'){
        if (str[i]==' '){
            //stack 프린트하고 스택 비우기
            while(top > -1){
                pop();
            }
            printf(" ");
            i++;
            continue;
        }
        // 스택에 넣기
        push(str[i++]);
    }
    while(top > -1){
        pop();
    }
    printf("\n");
}

int main(){
    int T;
    char c;
    scanf("%d", &T);
    getchar();

    while(T >0){
        solve();
        T--;
    }
    
}