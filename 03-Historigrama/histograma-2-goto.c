#include <stdio.h>
typedef enum{
    OUT,
    IN
}estados;
int main(){
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0 ;

    contar:
    while ((c = getchar( )) != EOF) {
        ++nc;
        if (c=='\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            goto out;
        else if (state == OUT) 
            goto in;
    }
    printf ("%d %d %d \n", nl, nw, nc);
    return 0;
    out:
    state = OUT;
    goto contar;
    in:
    state = IN;
    nw++;
    goto contar;
}

