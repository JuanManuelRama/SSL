#include <stdio.h>
typedef enum{
    OUT,
    IN
}estados;
int main(){
    int length, state, c;
    state = OUT;
    length = 0;
    while ((c = getchar()) != EOF) {
        switch(state){
            case OUT:
                if(!(c == ' ' || c == '\n' || c == '\t')){
                    ++length;
                    state = IN;
               }
              break;
            case IN:
                if(c == ' ' || c == '\n' || c == '\t'){
                    length = 0;
                    state = OUT;
                }
                else ++length;
        }
    }
}