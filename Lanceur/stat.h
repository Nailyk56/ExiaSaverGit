#ifndef STAT_H
#define STAT_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>

#include "chainon.h"

typedef enum TypeDeVeille{Statique,Dynamique,Interactif,Debug}TypeDeVeille;

typedef struct Log
{
    struct tm heure_de_lancement;
    struct tm heure_de_fermeture;
    TypeDeVeille type;
    char* precision;

} Log;


Chainon* ChargementDesLog(char* chemin_des_log) ;

int NombreDeFoisLeMode(Chainon* chaine_de_logs, TypeDeVeille type);
char *TempsPasserEnMode(Chainon* chaine_de_logs,TypeDeVeille type);
void AfficherLesStats(Chainon* chaine_de_logs,int hauteur_console);
void SauvegarderLesLog(Log log_a_sauvegarder, char* chemin_a_sauvegarder) ;



#endif // STAT_H
