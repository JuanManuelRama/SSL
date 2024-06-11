#include <stdio.h>
typedef enum{
    OUT,
    IN
}estados;
int main(){
    int c, length;
    length = 0;
    contar:
    while ((c = getchar( )) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t')
            goto out;
        else
            goto in;
    }
    return 0;
    out:
    if(length>0)
        printf("%d ", length);
    length = 0;
    
    
    goto contar;
    in:
    ++length;
    goto contar;
}

