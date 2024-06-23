#include <pthread.h>
#include <semaphore.h>
#include "histograma.h"

int* longitudes;
sem_t binIN;
sem_t binOUT;
int wl;
void in();
void out();
int* contar(){
    pthread_t hiloIN;
    pthread_t hiloOUT;
    longitudes = calloc(MAX_LEN, sizeof *longitudes);
    wl=0;
    sem_init(&binIN, 0 , 0);
    sem_init(&binOUT, 0 ,1);
    pthread_create(&hiloOUT, NULL,(void*) out, NULL);
    pthread_create(&hiloIN, NULL,(void*) in, NULL);
    pthread_join(hiloOUT, NULL);
    pthread_join(hiloIN, NULL);
    sem_close(&binIN);
    sem_close(&binOUT);
    return longitudes;
}

void out(){
    while(1){
        sem_wait(&binOUT);
        switch(getchar()){
            case ' ':
            case '\n':
            case '\t':
                sem_post(&binOUT);
                break;
            case EOF:
                sem_post(&binIN);
                return;
            default:
                wl++;
                sem_post(&binIN);
        }
    }
}

void in(){
    while(1){
        sem_wait(&binIN);
        switch(getchar()){
            case ' ':
            case '\n':
            case '\t':
                if (wl>MAX_LEN)
                    ++longitudes[MAX_LEN];
                else
                    ++longitudes[wl];
                sem_post(&binOUT);
                break;
            case EOF:
                sem_post(&binOUT);
                return;
            default:
                ++wl;
                sem_post(&binIN);
        }
    }
}