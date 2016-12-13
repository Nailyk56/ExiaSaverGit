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
char tailleImage [10]; // déclaration de la chaine tailleImage
char tmp[10]; // déclaration du tmp qui va nous servir à stocker des données temporaire

memset(MonChemin,'\0',100); // on initialise les valeurs qui se trouve dans MonChemin
memset(tailleImage,'\0',10); // on initialise tailleImage
memset(tmp,'\0',10); // on initialise le tmp à 0 c'est à dire rien

strcat(MonChemin,"/repertoire/Image"); // on écrit dans MonChemin répertoire/Image


int numImage = (rand() %5); //On prend le numero de l'image au hasard
char stringImage [5]; // On initialise notre tableau stringImage qui va nous servir à écrire en mode caractère le numero de l'image

int largeur = (rand() %(79-5+1))+5; // on prend une valeur aléatoire pour la largeur de notre image de minimum 5 à 79
int longueur = (rand() %(23-3+1))+3; // on prend une valeur aléatoire pour la longueur de notre image de minimum 3 à 23

ModeHasard = (rand() %3); // Prendre un nombre au hasard de 0 à 2 car %3 veut dire qu'on a 3 possibilitées 0,1 et 2

ModeHasard=0;




/* Ici, on va ajouter les différentes configuration de notre image a afficher, le répertoire et le nom de base y sont deja grâce à la déclaration de
MonChemin, il ne reste plus qu'à ajouter le numero au hasard de notre image à afficher, son format, sa longueur et sa largeur.
*/




if (ModeHasard ==0) // Condition pour démarrer le mode Statique
{

sprintf(stringImage, "%d", numImage); // on ajoute à stringImage numImage qui est un nombre au hasard




strcat(MonChemin,stringImage); // On ajoute le numero de l'image à la suite de MonChemin qui est le répertoire
strcat(MonChemin,".pbm"); // On ajoute le format de notre image qui est .pbm à la suite de notre image


sprintf(tailleImage," "); // on ajoute a tailleImage un espace


memset(tmp,'\0',10); // on reinitialise le tmp
sprintf(tmp,"%d",largeur); // on met la valeur de largeur dans le tmp
strcat(tailleImage,tmp); // on ajoute la valeur de tmp qui est la valeur de la largeur dans tailleImage

strcat(tailleImage,"x"); // on ajoute x entre la largeur et la longueur

memset(tmp,'\0',10);  // on reinitialise le tmp
sprintf(tmp,"%d",longueur); // on met la valeur de longueur dans le tmp
strcat(tailleImage,tmp); // on ajoute la valeur de tmp qui est la valeur de la longueur dans tailleImage


strcat(MonChemin,tailleImage); // On ajoute toute la taille de l'image dans mon chemin
printf("\n\n%s\n\n",MonChemin); // On affiche le répertoire de notre image plus le nom du fichier image plus la taille de l'image





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
printf("Ce code ne peut pas s'exécuter");
break;


}

}



return 0;
}
