#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>


int main()
{

srand (time (NULL)); // initialiser le random

int ModeHasard; // d�claration de la variable pour le mode que l'on va prendre
char MonChemin[100]; // d�claration du pointeur qui va nous servir � charger le chemin
memset(MonChemin,'\0',100); // on initialise les valeurs qui se trouve dans MonChemin
strcat(MonChemin,"/repertoire/Image"); // on �crit dans MonChemin r�pertoire/Image

int numImage = (rand() %5); //On prend le numero de l'image au hasard
char stringImage [5]; // On initialise notre tableau stringImage qui va nous servir � �crire en mode caract�re le numero de l'image

ModeHasard = (rand() %3); // Prendre un nombre au hasard de 0 � 2 car %3 veut dire qu'on a 3 possibilit�es 0,1 et 2

ModeHasard=2;


if (ModeHasard ==0) // Condition pour d�marrer le mode Statique
{

sprintf(stringImage, "%d", numImage); // On va �crire dans string image la valeur de numImage qui est un nombre random
strcat(MonChemin,stringImage); // On rassemble MonChemin et stringImage donc on va coller le stringImage � MonChemin
strcat(MonChemin,".pbm"); // On rajoute � MonChemin .pbm qui est le format de notre image
printf("\n\n%s\n\n",MonChemin); // On affiche MonChemin


}

if (ModeHasard ==1) // Condition pour d�marrer le mode Dynamique
{


}

if (ModeHasard ==2) // Condition pour d�marrer le mode Interactif
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
printf("Ce code ne peut pas s'ex�cuter");
break;


}

}



return 0;
}
