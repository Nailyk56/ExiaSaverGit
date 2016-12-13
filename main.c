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
char tailleImage [10]; // d�claration de la chaine tailleImage
char tmp[10]; // d�claration du tmp qui va nous servir � stocker des donn�es temporaire

memset(MonChemin,'\0',100); // on initialise les valeurs qui se trouve dans MonChemin
memset(tailleImage,'\0',10); // on initialise tailleImage
memset(tmp,'\0',10); // on initialise le tmp � 0 c'est � dire rien

strcat(MonChemin,"/repertoire/Image"); // on �crit dans MonChemin r�pertoire/Image


int numImage = (rand() %5); //On prend le numero de l'image au hasard
char stringImage [5]; // On initialise notre tableau stringImage qui va nous servir � �crire en mode caract�re le numero de l'image

int largeur = (rand() %(79-5+1))+5; // on prend une valeur al�atoire pour la largeur de notre image de minimum 5 � 79
int longueur = (rand() %(23-3+1))+3; // on prend une valeur al�atoire pour la longueur de notre image de minimum 3 � 23

ModeHasard = (rand() %3); // Prendre un nombre au hasard de 0 � 2 car %3 veut dire qu'on a 3 possibilit�es 0,1 et 2

ModeHasard=0;




/* Ici, on va ajouter les diff�rentes configuration de notre image a afficher, le r�pertoire et le nom de base y sont deja gr�ce � la d�claration de
MonChemin, il ne reste plus qu'� ajouter le numero au hasard de notre image � afficher, son format, sa longueur et sa largeur.
*/




if (ModeHasard ==0) // Condition pour d�marrer le mode Statique
{

sprintf(stringImage, "%d", numImage); // on ajoute � stringImage numImage qui est un nombre au hasard




strcat(MonChemin,stringImage); // On ajoute le numero de l'image � la suite de MonChemin qui est le r�pertoire
strcat(MonChemin,".pbm"); // On ajoute le format de notre image qui est .pbm � la suite de notre image


sprintf(tailleImage," "); // on ajoute a tailleImage un espace


memset(tmp,'\0',10); // on reinitialise le tmp
sprintf(tmp,"%d",largeur); // on met la valeur de largeur dans le tmp
strcat(tailleImage,tmp); // on ajoute la valeur de tmp qui est la valeur de la largeur dans tailleImage

strcat(tailleImage,"x"); // on ajoute x entre la largeur et la longueur

memset(tmp,'\0',10);  // on reinitialise le tmp
sprintf(tmp,"%d",longueur); // on met la valeur de longueur dans le tmp
strcat(tailleImage,tmp); // on ajoute la valeur de tmp qui est la valeur de la longueur dans tailleImage


strcat(MonChemin,tailleImage); // On ajoute toute la taille de l'image dans mon chemin
printf("\n\n%s\n\n",MonChemin); // On affiche le r�pertoire de notre image plus le nom du fichier image plus la taille de l'image





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
printf("Haut");

break;

case 2:
printf("Bas");

break;

case 3:
printf("Droite");

break ;

case 4:
printf("Gauche");

break;

default:
printf("Ce code ne peut pas s'ex�cuter");
break;


}

}



return 0;
}
