/*****exe.c****/
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<signal.h>
 
 
 
int main(int argc, char *argv[]){
 
char *wykonaj = argv[1]; /*trzyma sekwecje klawiszy...*/
int syg =  atol(argv[2]); /*nr sygnalu*/
int pid=fork(); /*proces potomny*/
int kill(pid_t pid, int sig);/*def kill'a*/
/*mini sprawdzacz czy warunki uruchomienia zostaly zachowane!*/
        if (argc != 3) {
                fprintf(stderr,"za malo argumentow!\n");
                exit (1); }
 
switch(pid){
case -1:
        perror("blad execl\n"); /*obsluga bledow*/
        exit(1);
        break;
case 0:
        execl("obs_syg","obs_syg.c",wykonaj, NULL); /*odpala program syg z podanymi parametrami...*/
        exit(2);
        break;
default:
        sleep(1);
        printf("program syg otwarty z podanymi parametrami...\n");
        printf("sygnal %d wyslany do procesu %d\n",syg,pid); /*wyswietla "co sie dzieje"*/
        kill(pid,syg); /*wysyla sygnal za pomoca kill()*/
        break;
                        }
       
return 0;
 
}
