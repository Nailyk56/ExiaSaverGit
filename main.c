#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>


int main()
{

srand (time (NULL)); // initialiser le random

int ModeHasard; // déclaration de la variable pour le mode que l'on va prendre
char MonChemin[100]; // déclaration du pointeur qui va nous servir à charger le chemin
memset(MonChemin,'\0',100); // on initialise les valeurs qui se trouve dans MonChemin
strcat(MonChemin,"/repertoire/Image"); // on écrit dans MonChemin répertoire/Image

int numImage = (rand() %5); //On prend le numero de l'image au hasard
char stringImage [5]; // On initialise notre tableau stringImage qui va nous servir à écrire en mode caractère le numero de l'image

ModeHasard = (rand() %3); // Prendre un nombre au hasard de 0 à 2 car %3 veut dire qu'on a 3 possibilitées 0,1 et 2

ModeHasard=2;


if (ModeHasard ==0) // Condition pour démarrer le mode Statique
{

sprintf(stringImage, "%d", numImage); // On va écrire dans string image la valeur de numImage qui est un nombre random
strcat(MonChemin,stringImage); // On rassemble MonChemin et stringImage donc on va coller le stringImage à MonChemin
strcat(MonChemin,".pbm"); // On rajoute à MonChemin .pbm qui est le format de notre image
printf("\n\n%s\n\n",MonChemin); // On affiche MonChemin


}

if (ModeHasard ==1) // Condition pour démarrer le mode Dynamique
{


}

if (ModeHasard ==2) // Condition pour démarrer le mode Interactif
{

int direction = (rand() %4);


switch(direction)
{
case 1:

break;

case 2:

break;

case 3:

break ;

case 4:

break;

default:
printf("Ce code ne peut pas s'exécuter");
break;


}

}



return 0;
}
