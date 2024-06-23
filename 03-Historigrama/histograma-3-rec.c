#include "histograma.h"
typedef enum{
    OUT,
    IN
}estados;
int wl;
int* longitudes;

void out(int);
void in();

int* contar(){
    longitudes = calloc(MAX_LEN+1, sizeof *longitudes);
    int c;
    while((c=getchar()) != EOF)
        out(c);
    return longitudes;
}

void out(int c){
    if(c == ' ' || c == '\n' || c == '\t'){
        wl = 0;
        return;
    }
    else{
        ++wl;
        return in();
    }
}

void in(){
    int c = getchar();
        if(c == ' ' || c == '\n' || c == '\t'){
            if(wl>MAX_LEN)
                ++longitudes[MAX_LEN];
            else 
                ++longitudes[wl];
        wl = 0;
        return;
    }
    else{
        ++wl;
        return in();
    }
        
}