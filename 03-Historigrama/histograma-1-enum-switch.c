#include <stdio.h>
typedef enum{
    OUT,
    IN
}STATE;
int main(){
    int length, c;
    STATE state;
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
                    printf("%d ", length);
                    length = 0;
                    state = OUT;
                }
                else ++length;
        }
    }
}