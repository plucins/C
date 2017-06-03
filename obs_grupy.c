/****************grup_syg.c********************/
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<signal.h>
 
int main(int argc, char *argv[]){
int kill(pid_t pid, int sig);/*def kill'a*/
char *wykonaj = argv[1]; /*trzyma sekwecje klawiszy...*/
int syg =  atol(argv[2]); /*nr sygnalu*/
 
int i=0;
/*mini sprawdzacz czy warunki uruchomienia zostaly zachowane!*/
        if (argc != 3) {
                fprintf(stderr,"za malo argumentow!\n");
                exit (1); }
do{
switch(fork()){
case -1:
        perror("blad execl\n"); /*obsluga bledow*/
        exit(1);
        break;
case 0:
        execl("obs_syg","obs_syg.c",wykonaj,syg, NULL); /*odpala program syg z podanymi parametrami...*/
        break;
default:
        wait(NULL);
        break;
}
i++; }while(i<3);
                sleep(1);
       
        printf("sygnal %d wyslany do grupy proc o ID: %d\n",syg,getpgrp()); /*wyswietla "co sie dzieje"*/
        kill(-getpgrp(),syg); /*wysyla sygnal za pomoca kill()*/
        while (wait(NULL) != -1){printf("brak potomkow!\n");}
return 0;
 
}
