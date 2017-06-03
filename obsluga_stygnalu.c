#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
/*wlasna obsluga sygnalu*/
void sig_hand (int syg)
{
        printf ("dotarl sygnal: %d.\n", syg);
}
 
int main (int argc, char *argv[]){
 
char *wykonaj = argv[1]; /*trzyma sekwecje klawiszy...*/
int syg =  atol(argv[2]); /*nr sygnalu*/
 
if(argc !=3 && argc !=2){               /*obluga bledow*/
        printf("aby uruchomic, wpisz: ./nazwa programu <operacja dla sygnalu> [nr_sygnalu]\n");
printf("parametry:\n \tk - operacja domyslna\n \to - ignorowanie\n \tc - obsluga wlasna\n");
        fprintf(stderr,"niepoprawna liczba argumentow!\n"); /*stand. wyjscie bledow*/
                        exit(1);
        }
/*kill them all! (domyslna)*/
 if (strcmp (wykonaj, "k") == 0)
{
        if(signal(syg,SIG_DFL)==SIG_ERR){
        perror("operacja zakonczona niepowodzeniem\n");
        exit(1);}
        else printf("they all are dead\n");
        exit(EXIT_SUCCESS);
}
 
/*ingnoruj*/
else if (strcmp (wykonaj, "o") == 0)
{
        if(signal(syg,SIG_IGN)==SIG_ERR){
perror("operacja zakonczona niepowodzeniem\n");
exit(1); }
}
 
/*zlap sygnal i obsluz...*/
if(strcmp(wykonaj,"c")==0){
        if(signal(syg,sig_hand)!=SIG_ERR){
        sig_hand(syg);
        exit(0);
                        }
                }
 
else pause();/*czeka na kill podany z drugiego terminalu*/
return 0;
}
