#include "image.h"

Image* ChargementDeLimage(char* chemin_a_sauvegarder)
{
    FILE* fichier_image = fopen(chemin_a_sauvegarder,"r"); //Ouverture du fichier de l'image envoyee
    char ligne[1000]; //Nombre maximale de caracteres par ligne = 1000
    memset(ligne,'\0',1000); //Remplissage du tableau ligne avec la valeur 0

    int nombre_magique = 0; //initialisation du nombre magique

    int buffer[5];

    int* tmp = malloc(sizeof(int));
    *tmp = 0;
    Chainon* data = ChainonCreate(tmp); //Creation de la liste chainee data contenant les donnees de l'image



    while (fgets(ligne, 1000, fichier_image) != NULL) //Lecture de toutes les lignes du fichier
    {
        if(ligne[0] != '#') //Ne pas lire les commentaires
        {
         if(ligne[0] == 'P') //On repere la ligne ou est signale le nombre magique
         {
             tmp = malloc(sizeof(int)); //On recupere le nombre magique
             *tmp = ligne[1]-48; //On traduit le char en int
             ChainonAdd(data,tmp); //On l'ajoute a la liste chainee
         }
         else if(ChainonGetSize(data) >= 2) //Si la liste chainee possede au moins le nombre magique
         {
            char* temp;
            temp = strtok(ligne," ");
            while(temp != NULL) //Tant qu'on ne rencontre pas d'espace
            {
                tmp = malloc(sizeof(int));
                memset(buffer,'\0',5); //Remplissage du tableau avec la valeur 0
                *tmp = strtol(buffer,NULL,10);
                ChainonAdd(data,tmp); //On l'ajoute a la liste chainee
                temp = strtok(NULL," ");
            }


         }
        }
    }

    fclose(fichier_image) //Fermeture du fichier de l'image

    Image* img = malloc(sizeof(Image));

    Position pos; //Initialisation de la position de l'image a 0 0
    pos.X = 0;
    pos.y = 0;

    img->largeur = (*((int*)ChainonAccess(data,2))); //Le troisieme chainon est associe a la largeur
    img->hauteur = (*((int*)ChainonAccess(data,3))); //Le quatrieme chainon est associe a la hauteur
    img->nombre_magique (*((int*)ChainonAccess(data,1))); //Le cinquieme chainon est associe au nombre magique

    Pixel* pixeltemp = malloc(sizeof(Pixel));
    InitialiserPixel(pixeltemp); //Initialisation de la couleur des pixels a noir
    Chainon* pixels = ChainonCreate(pixeltemp); //Creation de la liste chainee contenant l'ensemble des pixels


    if(*((int*)ChainonAccess(data,1)) == 1) //Si le nombre magique est 1 (image noir et blanc)
    {
        img->nombre_de_couleur = 0;

        int i = 0;
        for(i = 4; i < ChainonGetSize(data); i++) //Parcourt de l'ensemble des valeurs restantes
        {
            pixeltemp = malloc(sizeof(Pixel));
            InitialiserPixel(pixeltemp); //Initialisation du pixel a noir

            if(*((int*)ChainonAccess(data,i)) == 0) //0 = noir
                ChainonAdd(pixels,pixeltemp); //Ajout a la liste chainee
            else //1 = blanc
            {
                pixeltemp->bleu = 255;
                pixeltemp->rouge = 255;
                pixeltemp->vert = 255;
                ChainonAdd(pixels,pixeltemp); //Ajout a la liste chainee
            }
        }
        img->chainon_de_pixels = pixels; //Ajout a la structure de l'image
    }
    else if(*((int*)ChainonAccess(data,1)) == 2) //Si le nombre magique est 2 (nuances de gris)
    {
        img->nombre_de_couleur = (*((int*)ChainonAccess(data,4))); //La valeur maximale de la couleur est la cinquieme valeur de la liste chainee

        int i = 0;
        for(i = 5; i < ChainonGetSize(data); i++) //Parcourt de l'ensemble des valeurs restantes
        {
            pixeltemp = malloc(sizeof(Pixel));
            InitialiserPixel(pixeltemp); //Initialisation du pixel a noir

            pixeltemp->bleu = (*((int*)ChainonAccess(data,i))) * 255 /  img->nombre_de_couleur; //Rapport de grandeur pour avoir 256 nuances
            pixeltemp->rouge = (*((int*)ChainonAccess(data,i))) * 255 /  img->nombre_de_couleur; //Rapport de grandeur pour avoir 256 nuances
            pixeltemp->vert = (*((int*)ChainonAccess(data,i))) * 255 /  img->nombre_de_couleur; //Rapport de grandeur pour avoir 256 nuances
            ChainonAdd(pixels,pixeltemp);
        }
        img->chainon_de_pixels = pixels; //Ajout a la structure de l'image
    }
    else //Si le nombre magique est 3 (couleurs)
    {
        img->nombre_de_couleur = (*((int*)ChainonAccess(data,4))); //La valeur maximale de la couleur est la cinquieme valeur de la liste chainee

        int i = 0;
        for(i = 5; i < ChainonGetSize(data); i++) //On lit toutes les donnees jusqu'a la derniere
        {
            pixeltemp = malloc(sizeof(Pixel));
            InitialiserPixel(pixeltemp);
            pixeltemp->bleu = (*((int*)ChainonAccess(data,i))) * 255 /  img->nombre_de_couleur; //Rapport de grandeur pour avoir 256 nuances
            i++; //On passe a la couleur de pixel suivante
            pixeltemp->rouge = (*((int*)ChainonAccess(data,i))) * 255 /  img->nombre_de_couleur; //Rapport de grandeur pour avoir 256 nuances
            i++; //On passe a la couleur de pixel suivante
            pixeltemp->vert = (*((int*)ChainonAccess(data,i))) * 255 /  img->nombre_de_couleur; //Rapport de grandeur pour avoir 256 nuances
            ChainonAdd(pixels,pixeltemp);
        }
        img->chainon_de_pixels = pixels; //Ajout a la structure de l'image
    }
    img->position = pos; //Ajout de la position a la structure de l'image

    ChainonFree(pixels);

    return img; //On renvoie l'image sous forme de structure
}


void DessinerLImage(Image *console,Image *a_dessiner)
{
   int c = a_dessiner->position.x + 1;
   int d = 1;
   int i=0;
   int j=0;

   for(i=0; i < a_dessiner->position.y;i++)
       c += console->largeur;


    for(i=0; i < a_dessiner->hauteur; k++) //on repete pour toute la hauteur de l'image
    {
        for(j=0;j <a_dessiner->largeur ; j++) //on repete pour toute la largeur de l'image
        {

            ((Pixel*)ChainonAccess(console->chaine_de_pixels,c))->bleue =  ((Pixel*)ChainonAccess(a_dessiner->chaine_de_pixels,d))->bleue;
            ((Pixel*)ChainonAccess(console->chaine_de_pixels,c))->rouge =  ((Pixel*)ChainonAccess(a_dessiner->chaine_de_pixels,d))->rouge;
            ((Pixel*)ChainonAccess(console->chaine_de_pixels,c))->vert =  ((Pixel*)ChainonAccess(a_dessiner->chaine_de_pixels,d))->vert;

            c++;
            d++;
        }
        c+= console->largeur - a_dessiner->largeur;
    }
    return;
}

Image* CreerImageVierge(int x,int y)
{
    Image img = malloc(sizeof(Image));
    Pixel* pixel_tmp = malloc(sizeof(Pixel));
    pixel_tmp->rouge = 0;
    pixel_tmp->vert = 0;
    pixel_tmp->bleue = 0;
    Chainon* pixels = ChainonCreate(pixel_tmp);

    img.hauteur = x;
    img.largeur = y;

    img.nombre_de_couleur = 255;
    img.nombre_magique = -1;
    img.position.x = 0;
    img.position.y = 0;

    int i = 0;
    int j = x * y;

    for(i=0;i<j;i++)
    {
    Pixel* pixel_tmp = malloc(sizeof(Pixel));
    pixel_tmp->rouge = 0;
    pixel_tmp->vert = 0;
    pixel_tmp->bleue = 0;
    ChainonAdd(pixels,pixel_tmp);
    }

    img.chaine_de_pixels = pixels;
    return img;

}


void ConsoleCouleur(Pixel p)
{
    char temp[25];
    char buffer[5];

    memset(temp,'\0',25);
    memset(temp,'\0',5);

    strcat(temp,"\033[38;2;");
    sprintf(buffer,"%d",p.rouge);
    strcat(temp,buffer);
    strcat(temp,";");
    memset(buffer,'\0',5);
    sprintf(buffer,"%d",p.vert);
    strcat(temp,buffer);
    strcat(temp,";");
    memset(buffer,'\0',5);
    sprintf(buffer,"%d",p.bleu);
    strcat(temp,buffer);
    strcat(temp,";m");

    printf(temp);

}

void EffacerLImage(Image* image_a_effacer)
{
    int i = 0;
    int j = 0;
    int c = 1;

    for(i=0;i<image_a_effacer->hauteur;i++)
    {
        for(j=0;j<image_a_effacer->largeur;j++)
        {
            ((Pixel*)ChainonAccess(image_a_effacer,c))->bleu = 0;
            ((Pixel*)ChainonAccess(image_a_effacer,c))->rouge = 0;
            ((Pixel*)ChainonAccess(image_a_effacer,c))->vert = 0;
            c++;
        }
    }
}

void AfficherLaFenetre(Image *fenetre)
{
    int nb_colonne = image_a_afficher->largeur;
    int nb_ligne = image_a_afficher->hauteur;

    int i;
    int j;
    int c=1;

    for (i = 0; i < nb_ligne; i++) //repetition sur toute la hauteur de l'image
    {
        for (j = 0; j < nb_colonne; j++) //repetition sur toute la ligne
        {

            ConsoleCouleur(*((Pixel*)ChainonAccess(fenetre->chainon_de_pixels,c)));
            printf("\xE2\x96\88"); //Affichage du caratere plein
            c++;
        }

        printf("\n"); //Ligne suivante de l'image
    }

}

void SupprimerImage(Image* image_a_supprimer)
{
    ChainonFree(image_a_supprimer->chainon_de_pixels);
}

VectorImage* ChargementDeLimageVectoriel(char *chemin_a_charger)
{
    FILE* fichier_image = fopen(chemin_a_sauvegarder,"r"); //Ouverture du fichier de l'image envoyee
    char ligne[1000]; //Nombre maximale de caracteres par ligne = 1000
    memset(ligne,'\0',1000); //Remplissage du tableau ligne avec la valeur 0

    Position* tmp = malloc(sizeof(Position));
    tmp->X = 0;
    tmp->Y = 0;
    Chainon* line = ChainonCreate(tmp); //Creation de la liste chainee data contenant les donnees de l'image

    Chainon* dot = ChainonCreate(tmp);

    VectorImage *img = malloc(sizeof(VectorImage));
    img->pos.X = 0;
    img->pos.Y = 0;
    img->size.X = 0;
    img->size.Y = 0;



    while (fgets(ligne, 1000, fichier_image) != NULL) //Lecture de toutes les lignes du fichier
    {
        if(ligne[0] != '#') //Ne pas lire les commentaires
        {
            if(img->size.Y != 0)
            {
                if(ligne[0] == 'P' && ligne[1] == ':')
                {
                    char* temp;

                    tmp = malloc(sizeof(Position));
                    tmp->X = 0;
                    tmp->Y = 0;

                    temp = strtok(ligne," ");
                    temp = strtok(NULL," ");
                    tmp.X = strtol(temp,NULL,10);
                    temp = strtok(NULL," ");
                    tmp.Y = strtol(temp,NULL,10);

                    ChainonAdd(dot,tmp);

                }
                else if(ligne[0] == 'L' && ligne[1] == ':')
                {
                    char* temp;

                    tmp = malloc(sizeof(Position));
                    tmp->X = 0;
                    tmp->Y = 0;

                    temp = strtok(ligne," ");
                    temp = strtok(NULL," ");
                    tmp.X = strtol(temp,NULL,10);
                    temp = strtok(NULL," ");
                    tmp.Y = strtol(temp,NULL,10);

                    ChainonAdd(line,tmp);


                }
            }
            else
            {
                char* temp;

                temp = strtok(ligne," ");
                img->size.X = strtol(temp,NULL,10);
                temp = strtok(NULL," ");
                img->size.Y = strtol(temp,NULL,10);
            }
        }
    }

    img->dot = dot;
    img->line = line;

    return img;

}


Image* ConversionDImage(VectorImage* a_convertir,Position offset)
{
    Image *img = CreerImageVierge(offset.X,offset.Y);

    int i = 1;

    while(i < ChainonGetSize(a_convertir->line))
    {
        if(((Position*)ChainonAccess(a_convertir->line,i))->X == ((Position*)ChainonAccess(a_convertir->line,i+1))->X)
        {
            Image *temp = CreerImageVierge( ((Position*)ChainonAccess(a_convertir->line,i))->Y - ((Position*)ChainonAccess(a_convertir->line,i+1))->Y,1);
            int j = 1;
            for(j=1;j<ChainonGetSize(temp->chainon_de_pixels);j++)
            {
                ((Pixel*)ChainonAccess(temp->chainon_de_pixels,j))->bleu = 255;
                ((Pixel*)ChainonAccess(temp->chainon_de_pixels,j))->rouge = 255;
                ((Pixel*)ChainonAccess(temp->chainon_de_pixels,j))->vert = 255;
            }
            DessinerLImage(img,temp);

        }
        if(((Position*)ChainonAccess(a_convertir->line,i))->Y == ((Position*)ChainonAccess(a_convertir->line,i+1))->Y)
        {
            Image *temp = CreerImageVierge(1, ((Position*)ChainonAccess(a_convertir->line,i))->X - ((Position*)ChainonAccess(a_convertir->line,i+1))->X);
            for(j=1;j<ChainonGetSize(temp->chainon_de_pixels);j++)
            {
                ((Pixel*)ChainonAccess(temp->chainon_de_pixels,j))->bleu = 255;
                ((Pixel*)ChainonAccess(temp->chainon_de_pixels,j))->rouge = 255;
                ((Pixel*)ChainonAccess(temp->chainon_de_pixels,j))->vert = 255;
            }
            temp->position.Y = min(((Position*)ChainonAccess(a_convertir->line,i))->Y,((Position*)ChainonAccess(a_convertir->line,i+1))->Y);
            DessinerLImage(img,temp);
        }
    }

    i = 1;
    while (i < ChainonGetSize(a_convertir->dot))
    {
        Image *temp = CreerImageVierge(1, 1);
            ((Pixel*)ChainonAccess(temp->chainon_de_pixels,1))->bleu = 255;
            ((Pixel*)ChainonAccess(temp->chainon_de_pixels,1))->rouge = 255;
            ((Pixel*)ChainonAccess(temp->chainon_de_pixels,1))->vert = 255;

        temp->position.X = ((Position*)ChainonAccess(a_convertir->dot,i))->X;
        temp->position.Y = ((Position*)ChainonAccess(a_convertir->dot,i))->Y;
        DessinerLImage(img,temp);
    }



    return temp;
}
