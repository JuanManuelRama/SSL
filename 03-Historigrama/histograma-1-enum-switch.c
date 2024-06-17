#include "histograma.h"
extern const int MAX_LEN;
typedef enum{
    OUT,
    IN
}STATE;
int* contar(){
    int* longitudes = calloc(MAX_LEN+1, sizeof *longitudes);
    int c, length;
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
                    longitudes[length]++;
                    length = 0;
                    state = OUT;
                }
                else ++length;
        }
    }
    return longitudes;
}