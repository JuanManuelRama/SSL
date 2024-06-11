#include <stdio.h>
typedef enum{
    OUT,
    IN
}estados;
int length;

void out(int);
void in();


int main(){
    int c;
    while((c=getchar()) != EOF)
        out(c);
    return 0;
}

void out(int c){
    if(c == ' ' || c == '\n' || c == '\t'){
        length = 0;
        return;
    }
    else{
        ++length;
        return in();
    }
}

void in(){
    int c;
    if((c=getchar()) == EOF){
        length = 0;
        return;
    }

    else if(c == ' ' || c == '\n' || c == '\t'){
        length = 0;
        return;
    }
    else{
        ++length;
        return in();
    }
        
}