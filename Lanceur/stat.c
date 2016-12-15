#include "stat.h"


// FONCTION de chargement des logs depuis chemin_de_log
Chainon* ChargementDesLog(char* chemin_des_log)
{
    //variable log qui stock les donnees d'une ligne du fichier log;
    Log* tmp = malloc(sizeof(Log));

    //Creation de la liste chainee et ajout de la valeur 0 (par defaut)
    tmp->type = Debug;
    Chainon* tab = ChainonCreate(tmp);

    //Ouverture
    FILE* fichier_de_log = fopen(chemin_des_log,"r");
    if(fichier_de_log == NULL)
    {
        printf("erreur: impossible d'ouvir %s\n",chemin_des_log);
        exit(EXIT_FAILURE);
    }

    char strtmp[500];
    while(fgets(strtmp, 500, fichier_de_log) != NULL)
    {
        if(strtmp[0] != '#' && strtmp[0] != '\n')
        {
            tmp = malloc(sizeof(Log));
            char* parti = strtok (strtmp," ;/:");
            tmp->heure_de_lancement.tm_mday = strtol(parti,NULL,10);
            parti = strtok (NULL," ;/:");
            tmp->heure_de_lancement.tm_mon = strtol(parti,NULL,10)-1;
            parti = strtok (NULL," ;/:");
            tmp->heure_de_lancement.tm_year = strtol(parti,NULL,10)-1900;
            parti = strtok (NULL," ;/:");
            tmp->heure_de_lancement.tm_hour = strtol(parti,NULL,10);
            parti = strtok (NULL," ;/:");
            tmp->heure_de_lancement.tm_min = strtol(parti,NULL,10);
            parti = strtok (NULL," ;/:");
            tmp->heure_de_lancement.tm_sec = strtol(parti,NULL,10);
            tmp->heure_de_lancement.tm_isdst = 0;

            parti = strtok (NULL," ;/:");
            tmp->heure_de_fermeture.tm_mday = strtol(parti,NULL,10);
            parti = strtok (NULL," ;/:");
            tmp->heure_de_fermeture.tm_mon = strtol(parti,NULL,10)-1;
            parti = strtok (NULL," ;/:");
            tmp->heure_de_fermeture.tm_year = strtol(parti,NULL,10)-1900;
            parti = strtok (NULL," ;/:");
            tmp->heure_de_fermeture.tm_hour = strtol(parti,NULL,10);
            parti = strtok (NULL," ;/:");
            tmp->heure_de_fermeture.tm_min = strtol(parti,NULL,10);
            parti = strtok (NULL," ;/:");
            tmp->heure_de_fermeture.tm_sec = strtol(parti,NULL,10);
            tmp->heure_de_fermeture.tm_isdst = 0;

            parti = strtok (NULL," ;/:");
            switch (strtol(parti,NULL,10))
            {
            case 1:
                tmp->type = Statique;
                break;
            case 2:
                tmp->type = Dynamique;
                break;
            case 3:
                tmp->type = Interactif;
                break;
            default:
                printf("erreur: fichier de log corrompu");
                exit(EXIT_FAILURE);
                break;
            }

            char *prectmp = malloc(sizeof(char)*50);
            parti = strtok(NULL," ;/:");
            if(parti != NULL)
                memcpy(prectmp,parti,strlen(parti)+1);
            tmp->precision = prectmp;

            ChainonAdd(tab,tmp);
        }


    }
    fclose(fichier_de_log);
    return tab;

}



int NombreDeFoisLeMode(Chainon* chaine_de_logs,TypeDeVeille type)
{
    int i = 1;
    int c = 0;
    for(i=1 ; i<ChainonGetSize(chaine_de_logs); i++)
    {
        if(((Log*)ChainonAccess(chaine_de_logs,i))->type == type)
            c++;
    }
    return c;
}

char* TempsPasserEnMode(Chainon* chaine_de_logs,TypeDeVeille type)
{
    int i = 1;
    double time = 0;
    struct tm tmp;
    for(i=1 ; i<ChainonGetSize(chaine_de_logs); i++)
    {
        if(((Log*)ChainonAccess(chaine_de_logs,i))->type == type)
        {
           struct tm titest = ((Log*)ChainonAccess(chaine_de_logs,i))->heure_de_fermeture;
           time_t test = mktime(&titest);
           time_t test2 = mktime(&(((Log*)ChainonAccess(chaine_de_logs,i))->heure_de_lancement));
           time+=difftime(test,test2);
        }
    }
    tmp.tm_mon = (int)(time/262800);
    time = fmod(time,262800);
    tmp.tm_mday = (int)(time/86400);
    time = fmod(time,86400);
    tmp.tm_hour = (int)(time/3600);
    time = fmod(time,3600);
    tmp.tm_min = (int)(time/60);
    time = fmod(time,60);
    tmp.tm_sec = time;

    char temp[10];
    char *ret = malloc(sizeof(char)*100);
    memset(temp,'\0',10);
    memset(ret,'\0',100);
    sprintf(temp," %dmois",tmp.tm_mon);
    strcat(ret,temp);
    memset(temp,'\0',10);
    sprintf(temp," %djour",tmp.tm_mday);
    strcat(ret,temp);
    memset(temp,'\0',10);
    sprintf(temp," %dheure",tmp.tm_hour);
    strcat(ret,temp);
    memset(temp,'\0',10);
    sprintf(temp," %dmin",tmp.tm_min);
    strcat(ret,temp);
    memset(temp,'\0',10);
    sprintf(temp," %dsec",tmp.tm_sec);
    strcat(ret,temp);
    return ret;
}
void AfficherLesStats(Chainon* chaine_de_logs,int hauteur_console)
{

    int i;
    for(i=0; i<30;i++)
    printf("\n");

    for(i=0; i<32;i++)
    printf(" ");
    printf("Menu Statistique\n\n"); //2 Ligne
    printf(" Nombre de fois le mode Statique : %d \n",NombreDeFoisLeMode(chaine_de_logs,Statique));
    printf(" Nombre de fois le mode Dynamique : %d \n",NombreDeFoisLeMode(chaine_de_logs,Dynamique));
    printf(" Nombre de fois le mode Interactif : %d \n\n",NombreDeFoisLeMode(chaine_de_logs,Interactif));


    char* temps_passer = TempsPasserEnMode(chaine_de_logs,Statique);
    printf(" Temps passe en mode Statique : %s \n",temps_passer);
    free(temps_passer);
    temps_passer = TempsPasserEnMode(chaine_de_logs,Dynamique);
    printf(" Temps passe en mode Dynamique : %s \n",temps_passer);
    free(temps_passer);
    temps_passer = TempsPasserEnMode(chaine_de_logs,Interactif);
    printf(" Temps passe en mode Interactif : %s \n\n",temps_passer);
    free(temps_passer);

    printf(" Dernier mode lance:\n");
    if(ChainonGetSize(chaine_de_logs) > 1)
    {
        printf("  Mode : ");
        if(((Log*)ChainonAccess(chaine_de_logs,ChainonGetSize(chaine_de_logs)-1))->type == Statique)
            printf("Statique\n");
        else if(((Log*)ChainonAccess(chaine_de_logs,ChainonGetSize(chaine_de_logs)-1))->type == Dynamique)
            printf("Dynamique\n");
        else
            printf("Interactif\n");

        char temp[50];
        struct tm temptm;
        temptm = ((Log*)ChainonAccess(chaine_de_logs,ChainonGetSize(chaine_de_logs)-1))->heure_de_lancement;
        strftime(temp,50,"%Y/%m/%d : %H:%M:%S",&temptm);
        printf("  Heure de lancement : %s\n",temp);
        temptm = ((Log*)ChainonAccess(chaine_de_logs,ChainonGetSize(chaine_de_logs)-1))->heure_de_fermeture;
        strftime(temp,50,"%Y/%m/%d : %H:%M:%S",&temptm);
        printf("  Heure de fermeture : %s\n",temp);
        Log* test = (Log*)ChainonAccess(chaine_de_logs,ChainonGetSize(chaine_de_logs)-1);
        char* test2 = test->precision;
        printf("  Parametre : %s\n",test2);

        for(i=0; i<hauteur_console - 16;i++)
            printf(" \n");
    }
    else
    {
        printf(" Aucun\n");
        for(i=0; i<hauteur_console - 16;i++)
            printf(" \n");
    }

    printf("Appuyer sur une touche pour quitter\n");

}




void SauvegarderLesLog(Log log_a_sauvegarder, char* chemin_a_sauvegarder)
{

    //10/10/2014 15:15:10  ;  10/10/2014 15:15:10  ;  1  ;  ex1.pbm
    FILE* fichier_de_log = fopen(chemin_a_sauvegarder,"a");
    if(fichier_de_log == NULL)
    {
        printf("erreur: impossible d'ouvrir %s\n",chemin_a_sauvegarder);
        exit(EXIT_FAILURE);
    }
    char tmp[500];
    memset(tmp,'\0',500);
    char conv[50];
    strcat(tmp,"\n");
    memset(conv,'\0',50);
    sprintf(conv,"%d",log_a_sauvegarder.heure_de_lancement.tm_mday);
    strcat(tmp,conv);
    strcat(tmp,"/");
    memset(conv,'\0',50);
    sprintf(conv,"%d",log_a_sauvegarder.heure_de_lancement.tm_mon+1);
    strcat(tmp,conv);
    strcat(tmp,"/");
    memset(conv,'\0',50);
    sprintf(conv,"%d",log_a_sauvegarder.heure_de_lancement.tm_year+1900);
    strcat(tmp,conv);
    strcat(tmp," ");
    memset(conv,'\0',50);
    sprintf(conv,"%d",log_a_sauvegarder.heure_de_lancement.tm_hour);
    strcat(tmp,conv);
    strcat(tmp,":");
    memset(conv,'\0',50);
    sprintf(conv,"%d",log_a_sauvegarder.heure_de_lancement.tm_min);
    strcat(tmp,conv);
    strcat(tmp,":");
    memset(conv,'\0',50);
    sprintf(conv,"%d",log_a_sauvegarder.heure_de_lancement.tm_sec);
    strcat(tmp,conv);
    strcat(tmp,"  ;  ");
    memset(conv,'\0',50);
    sprintf(conv,"%d",log_a_sauvegarder.heure_de_fermeture.tm_mday);
    strcat(tmp,conv);
    strcat(tmp,"/");
    memset(conv,'\0',50);
    sprintf(conv,"%d",log_a_sauvegarder.heure_de_fermeture.tm_mon+1);
    strcat(tmp,conv);
    strcat(tmp,"/");
    memset(conv,'\0',50);
    sprintf(conv,"%d",log_a_sauvegarder.heure_de_fermeture.tm_year+1900);
    strcat(tmp,conv);
    strcat(tmp," ");
    memset(conv,'\0',50);
    sprintf(conv,"%d",log_a_sauvegarder.heure_de_fermeture.tm_hour);
    strcat(tmp,conv);
    strcat(tmp,":");
    memset(conv,'\0',50);
    sprintf(conv,"%d",log_a_sauvegarder.heure_de_fermeture.tm_min);
    strcat(tmp,conv);
    strcat(tmp,":");
    memset(conv,'\0',50);
    sprintf(conv,"%d",log_a_sauvegarder.heure_de_fermeture.tm_sec);
    strcat(tmp,conv);
    strcat(tmp,"  ;  ");

    if(log_a_sauvegarder.type == Statique)
        strcat(tmp,"1  ;  ");
    else if(log_a_sauvegarder.type == Dynamique)
        strcat(tmp,"2  ;  ");
    else
        strcat(tmp,"3  ;  ");
    strcat(tmp,log_a_sauvegarder.precision);


    printf("\n\n%s\n\n",tmp);
    fputs(tmp,fichier_de_log);
    fclose(fichier_de_log);
}
