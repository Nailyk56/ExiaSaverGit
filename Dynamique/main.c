#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

#include "image.h"

void CodePere(int* pipe,char* argv);
void CodeFils(int *pipe);


int main(int argc, char *argv[])
{
    system("/bin/ssty raw");
    pid_t pere_ou_fils;
    int tube[2];

    pere_ou_fils = fork();

    if(pere_ou_fils == -1)
    {
        printf("erreur fork");
        exit(EXIT_FAILURE);
    }
    else if(pere_ou_fils == 0)
    {
        CodeFils(tube);
    }
    else
    {
        CodePere(tube,argv);
    }

    system("/bin/ssty cooked");
        return 0;
}

void CodePere(int* pipe,char* argv)
{
    Position size;
    size.X = strtol(strtok(argv,"x "),NULL,10);
    size.Y = strtol(strtok(NULL,"x "),NULL,10);
    Image console = CreerImageVierge(80,24);

    VectorImage caractere_zero = ChargementDeLimageVectoriel("/repertoire/chiffre_0.vec");
    VectorImage caractere_un = ChargementDeLimageVectoriel("/repertoire/chiffre_1.vec");
    VectorImage caractere_deux = ChargementDeLimageVectoriel("/repertoire/chiffre_2.vec");
    VectorImage caractere_trois = ChargementDeLimageVectoriel("/repertoire/chiffre_3.vec");
    VectorImage caractere_quatre = ChargementDeLimageVectoriel("/repertoire/chiffre_4.vec");
    VectorImage caractere_cinq = ChargementDeLimageVectoriel("/repertoire/chiffre_5.vec");
    VectorImage caractere_six = ChargementDeLimageVectoriel("/repertoire/chiffre_6.vec");
    VectorImage caractere_sept = ChargementDeLimageVectoriel("/repertoire/chiffre_7.vec");
    VectorImage caractere_huit = ChargementDeLimageVectoriel("/repertoire/chiffre_8.vec");
    VectorImage caractere_neuf = ChargementDeLimageVectoriel("/repertoire/chiffre_9.vec");
    VectorImage caractere_dp = ChargementDeLimageVectoriel("/repertoire/deux_points.vec");

    time_t rawtime;
    struct tm *structtime;



    int continuer = 1;
    int* comm = malloc(sizeof(int));
    *comm = 0;

    while(continuer)
    {
        close(pipe[1]);
        read(pipe[0],comm,sizeof(int));
        if(*comm != 0)
            continuer=0;


        time(&rawtime);
        structtime = localtime(&rawtime);

        EffacerLImage(console);


        switch((int)(structtime->tm_hour / 10))
        {
        case 0:
            Image *img = ConversionDImage(caractere_zero, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2);
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 1:
            Image *img = ConversionDImage(caractere_un, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2);
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 2:
            Image *img = ConversionDImage(caractere_deux, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2);
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        default:
            break;
        }
        switch(structtime->tm_hour % 10)
        {
        case 0:
            Image *img = ConversionDImage(caractere_zero, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 1;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 1:
            Image *img = ConversionDImage(caractere_un, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 1;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 2:
            Image *img = ConversionDImage(caractere_deux, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 1;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 3:
            Image *img = ConversionDImage(caractere_trois, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 1;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 4:
            Image *img = ConversionDImage(caractere_quatre, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 1;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 5:
            Image *img = ConversionDImage(caractere_cinq, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 1;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 6:
            Image *img = ConversionDImage(caractere_six, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 1;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 7:
            Image *img = ConversionDImage(caractere_sept, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 1;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 8:
            Image *img = ConversionDImage(caractere_huit, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 1;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 9:
            Image *img = ConversionDImage(caractere_neuf, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 1;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        default:
            break;
        }

        Image *img = ConversionDImage(caractere_dp, size);
        img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 2;
        img->position.Y = console.hauteur /2 - (size.Y /2);
        DessinerLImage(console,img);


        switch((int)(structtime->tm_min / 10))
        {
        case 0:
            Image *img = ConversionDImage(caractere_zero, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 3;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 1:
            Image *img = ConversionDImage(caractere_un, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 3;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 2:
            Image *img = ConversionDImage(caractere_deux, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 3;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 3:
            Image *img = ConversionDImage(caractere_trois, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 3;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 4:
            Image *img = ConversionDImage(caractere_quatre, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 3;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 5:
            Image *img = ConversionDImage(caractere_cinq, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 3;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 6:
            Image *img = ConversionDImage(caractere_six, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 3;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        default:
            break;
        }
        switch(structtime->tm_min % 10)
        {
        case 0:
            Image *img = ConversionDImage(caractere_zero, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 4;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 1:
            Image *img = ConversionDImage(caractere_un, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 4;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 2:
            Image *img = ConversionDImage(caractere_deux, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 4;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 3:
            Image *img = ConversionDImage(caractere_trois, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 4;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 4:
            Image *img = ConversionDImage(caractere_quatre, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 4;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 5:
            Image *img = ConversionDImage(caractere_cinq, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 4;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 6:
            Image *img = ConversionDImage(caractere_six, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 4;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 7:
            Image *img = ConversionDImage(caractere_sept, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 4;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 8:
            Image *img = ConversionDImage(caractere_huit, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 4;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 9:
            Image *img = ConversionDImage(caractere_neuf, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 4;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        default:
            break;
        }

        Image *img = ConversionDImage(caractere_dp, size);
        img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 5;
        img->position.Y = console.hauteur /2 - (size.Y /2);
        DessinerLImage(console,img);

        switch((int)(structtime->tm_sec / 10))
        {
        case 0:
            Image *img = ConversionDImage(caractere_zero, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 6;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 1:
            Image *img = ConversionDImage(caractere_un, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 6;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 2:
            Image *img = ConversionDImage(caractere_deux, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 6;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 3:
            Image *img = ConversionDImage(caractere_trois, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 6;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 4:
            Image *img = ConversionDImage(caractere_quatre, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 6;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 5:
            Image *img = ConversionDImage(caractere_cinq, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 6;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 6:
            Image *img = ConversionDImage(caractere_six, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 6;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        default:
            break;
        }
        switch(structtime->tm_sec % 10)
        {
        case 0:
            Image *img = ConversionDImage(caractere_zero, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 7;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 1:
            Image *img = ConversionDImage(caractere_un, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 7;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 2:
            Image *img = ConversionDImage(caractere_deux, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 7;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 3:
            Image *img = ConversionDImage(caractere_trois, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 7;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 4:
            Image *img = ConversionDImage(caractere_quatre, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 7;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 5:
            Image *img = ConversionDImage(caractere_cinq, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 7;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 6:
            Image *img = ConversionDImage(caractere_six, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 7;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 7:
            Image *img = ConversionDImage(caractere_sept, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 7;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 8:
            Image *img = ConversionDImage(caractere_huit, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 7;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        case 9:
            Image *img = ConversionDImage(caractere_neuf, size);
            img->position.X = console.largeur /2 - ((size.X * 8) /2) + size.X * 7;
            img->position.Y = console.hauteur /2 - (size.Y /2);
            DessinerLImage(console,img);
            break;
        default:
            break;
        }


        printf("\033[2J");
        AfficherLaFenetre(console);


    }


}




void CodeFils(int* pipe)
{
       char c = getchar();
       int msg = malloc(sizeof(int));
       *msg = 123;
       close(pipe[0]);
       write(pipe[1],msg,sizeof(int));

       free(msg);

}





