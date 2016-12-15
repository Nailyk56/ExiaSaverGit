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
    char* path = argv;
    Image console = CreerImageVierge(80,24);
    Image a_dessiner = ChargementDeLimage(path);
    
    Position pos;   
    
    pos.X = console.largeur/2 - a_dessiner.largeur/2;
    pos.Y = console.hauteur/2 - a_dessiner.hauteur/2;
    
    DessinerLImage(&console,&a_dessiner);
    AfficherLaFenetre(&console);
    
    int continuer = 1;
    int* comm = malloc(sizeof(int));
    *comm = 0;
    
    while(continuer)
    {
        close(pipe[1]);
        read(pipe[0],comm,sizeof(int));
        if(*comm != 0)
            continuer=0;
        
    }

    SupprimerImage(&console);
    SupprimerImage(&a_dessiner);
            
            
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
