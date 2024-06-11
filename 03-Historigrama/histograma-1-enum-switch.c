#include <stdio.h>
typedef enum{
    OUT,
    IN
}estados;
int main(){
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        switch (c){
            case '\n':
                nl++;
            case ' ':
            case '\t':
                state = OUT;
                break;
            default:
                if(state == OUT){
                    state = IN;
                    nw++;
                }
                break;
        }
    }
    printf("%d, %d, %d \n", nl, nw, nc);
    return 0;
}