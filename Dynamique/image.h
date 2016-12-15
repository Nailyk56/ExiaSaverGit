#ifndef IMAGE_H
#define IMAGE_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

#include "Chainon.h"


typedef struct Pixel
{
    int rouge; //Composante rouge d'un pixel (256 nuances)
    int vert; //Composante verte d'un pixel (256 nuances)
    int bleu; //Composante bleue d'un pixel (256 nuances)
}Pixel;

typedef struct Position //Position de l'image dans la console
{
    int X; //numero de colonne
    int Y; //numero de ligne
}Position;

typedef struct Image //Structure d'une image : caracteristiques et donnees
{
    int largeur; //Nombre de caracteres par lignes par l'image
    int hauteur; //Nombre de lignes utilisee par l'image
    int nombre_magique; //Nature de l'image (noir et blanc, nuances de gris, couleurs)
    int nombre_de_couleur; //Valeur maximale de l'echelle du nuancier
    Chainon* chainon_de_pixels; //Liste chainee contenant la totalite des pixels
    Position position; //Position de l'image
}Image;

typedef struct VectorImage
{
    Chainon* line;
    Chainon* dot;
    Position size;
    Position pos;
}VectorImage;


VectorImage* ChargementDeLimageVectoriel(char *chemin_a_charger);
Image* ConversionDImage(VectorImage* a_convertir,Position offset);

Image* ChargementDeLimage(char* chemin_a_charger) ;
void DessinerLImage(Image *console,Image *a_dessiner);
void EffacerLImage(Image* image_a_effacer) ;
void AfficherLaFenetre(Image *fenetre) ;
void ConsoleCouleur(Pixel p);
Image* CreerImageVierge(int x,int y);
void InitialiserPixel(Pixel* pix);
void SupprimerImage(Image *image_a_supprimer);
void SupprimerImageVectoriel(VectorImage* a_supprimer);

#endif // IMAGE_H
