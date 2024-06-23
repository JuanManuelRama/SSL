#include "histograma.h"

typedef enum{
    OUT,
    IN
}STATE;
int* contar(){
    int* longitudes = calloc(MAX_LEN+1, sizeof *longitudes);
    int c, wl;
    STATE state;
    state = OUT;
    wl = 0;
    while ((c = getchar()) != EOF) {
        switch(state){
            case OUT:
                if(!(c == ' ' || c == '\n' || c == '\t')){
                    ++wl;
                    state = IN;
               }
              break;
            case IN:
                if(c == ' ' || c == '\n' || c == '\t'){
                    if(wl>MAX_LEN)
                        ++longitudes[MAX_LEN];
                    else 
                        longitudes[wl]++;
                    wl = 0;
                    state = OUT;
                }
                else ++wl;
        }
    }
    return longitudes;
}