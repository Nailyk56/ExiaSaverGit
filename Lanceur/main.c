#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>

#include "Chainon.h"
#include "stat.h"

int main(int argc, char *argv[])
{

    time_t rawtime;
    struct tm *structtime;
    Log a_sauvegarder;
    time(&rawtime);
    structtime = localtime(&rawtime);
    a_sauvegarder.heure_de_lancement = *structtime;


    argc = 2;
    argv[1] = "-stat";

    if(argc > 1)
    {
        if(argc == 2)
        {
            if(strcmp("-stat",argv[1]) == 0)
            {
               Chainon* logs = ChargementDesLog("C:\\Users\\1748698\\Documents\\Lanceur\\test.log");
               AfficherLesStats(logs,24);
               system("PAUSE");


               time(&rawtime);
               structtime = localtime(&rawtime);
               a_sauvegarder.heure_de_fermeture = *structtime;
               a_sauvegarder.type = Statique;
               a_sauvegarder.precision = malloc(sizeof(char)*50);
               a_sauvegarder.precision = "testda0zta";

               SauvegarderLesLog(a_sauvegarder,"C:\\Users\\1748698\\Documents\\Lanceur\\test.log");



            }
            else
            {
                printf("erreur: mauvaise commande");
                return -1;
            }
        }
        else
        {
            printf("erreur: trop d'arguments");
            return -1;
        }
    }
    else
    {

        // PARTIE VEILLE



    }






    return 0;
}
