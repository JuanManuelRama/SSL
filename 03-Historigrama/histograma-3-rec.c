#include <stdio.h>
typedef enum{
    OUT,
    IN
}estados;
int nl, nw, nc;

void contar(int);


int main(){
    nl = nw = nc = 0 ;
    contar(OUT);
    printf ("%d %d %d \n", nl, nw, nc);
    return 0;
}

void contar(int state){
    int c;
    if((c = getchar()) == EOF)
        return;
   ++nc;
  if (c=='\n')
        ++nl;
    if (c == ' ' || c == '\n' || c == '\t')
        return (contar(OUT));
     else if (state == OUT){
            nw++;
            return (contar(IN));
        }
    }