
#include "utilisateur.h"
#include<stdio.h>
#include <string.h>
#include"utilisateur.h"
enum{ECIN,
     ENOM,
     EPRENOM,
     EDATEJJ,
     EDATEMM,
     EDATEYY,
     EGENRE,
     EREGION,
     ENUM,
     EROLE,
     ELOGIN,
     EPASS,
     COLUMNS
      };

void afficherUtilisateurByCin(GtkWidget *liste, char *filename,char * Cin){


GtkCellRenderer *renderer; // afficheur de cellule (Cellule contient un texte, image, case à cocher)
      GtkTreeViewColumn *column; // visualisation des colonnes
       GtkTreeIter iter;          /**/
       GtkListStore *store;       // création du modèle de type liste

  char jj[50],mm[50],yy[50];
    store = NULL;
   utilisateur u;
    FILE *f;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        
	renderer=gtk_cell_renderer_text_new();                                                               // cellule contenant du texte
        column = gtk_tree_view_column_new_with_attributes("CIN ", renderer, "text", ECIN, NULL); // création d'une colonne avec du texte
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);                                             // associer la colonne à l'afficheur (GtkTreeView)

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("NOM", renderer, "text", ENOM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("PRENOM", renderer, "text", EPRENOM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text", EDATEJJ, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text", EDATEMM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Année", renderer, "text", EDATEYY, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("GENRE", renderer, "text", EGENRE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("REGION", renderer, "text", EREGION, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

         renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("NUMERO", renderer, "text", ENUM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ROLE", renderer, "text", EROLE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("LOGIN", renderer, "text", ELOGIN, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("PASSWORD", renderer, "text", EPASS, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        // La liste contient 7 colonnes de type chaine de caractères
    }
   store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);


     


              f = fopen(filename, "r");

    if (f == NULL)
    {
        return;
    }
    else
    {
       
        while (fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s\n",u.Cin,u.nom,u.prenom,&u.dateNaissance.jj,&u.dateNaissance.mm,&u.dateNaissance.yy,u.genre,u.Region,u.num,u.Role,u.login,u.mpd)!=EOF)
        {  
            if(strcmp(u.Cin,Cin)==0){

         sprintf(jj,"%d",u.dateNaissance.jj);
         sprintf(mm,"%d",u.dateNaissance.mm);
         sprintf(yy,"%d",u.dateNaissance.yy);
        
        





            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter,ECIN,u.Cin,ENOM,u.nom,EPRENOM,u.prenom,EDATEJJ,jj,EDATEMM,mm,EDATEYY,yy,EGENRE,u.genre,EREGION,u.Region,ENUM,u.num,EROLE,u.Role,ELOGIN,u.login,EPASS,u.mpd,-1);}
        }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }









}
void afficherUtilisateurByRole(GtkWidget *liste, char *filename,char * role){

 GtkCellRenderer *renderer; // afficheur de cellule (Cellule contient un texte, image, case à cocher)
      GtkTreeViewColumn *column; // visualisation des colonnes
       GtkTreeIter iter;          /**/
       GtkListStore *store;       // création du modèle de type liste

  char jj[50],mm[50],yy[50];
    store = NULL;
   utilisateur u;
    FILE *f;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        
	renderer=gtk_cell_renderer_text_new();                                                               // cellule contenant du texte
        column = gtk_tree_view_column_new_with_attributes("CIN ", renderer, "text", ECIN, NULL); // création d'une colonne avec du texte
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);                                             // associer la colonne à l'afficheur (GtkTreeView)

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("NOM", renderer, "text", ENOM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("PRENOM", renderer, "text", EPRENOM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text", EDATEJJ, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text", EDATEMM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Année", renderer, "text", EDATEYY, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("GENRE", renderer, "text", EGENRE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("REGION", renderer, "text", EREGION, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

         renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("NUMERO", renderer, "text", ENUM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ROLE", renderer, "text", EROLE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("LOGIN", renderer, "text", ELOGIN, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("PASSWORD", renderer, "text", EPASS, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        // La liste contient 7 colonnes de type chaine de caractères
    }
   store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);


     


              f = fopen(filename, "r");

    if (f == NULL)
    {
        return;
    }
    else
    {
       
        while (fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s\n",u.Cin,u.nom,u.prenom,&u.dateNaissance.jj,&u.dateNaissance.mm,&u.dateNaissance.yy,u.genre,u.Region,u.num,u.Role,u.login,u.mpd)!=EOF)
        {  
            if(strcmp(u.Role,role)==0){

         sprintf(jj,"%d",u.dateNaissance.jj);
         sprintf(mm,"%d",u.dateNaissance.mm);
         sprintf(yy,"%d",u.dateNaissance.yy);
        
        





            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter,ECIN,u.Cin,ENOM,u.nom,EPRENOM,u.prenom,EDATEJJ,jj,EDATEMM,mm,EDATEYY,yy,EGENRE,u.genre,EREGION,u.Region,ENUM,u.num,EROLE,u.Role,ELOGIN,u.login,EPASS,u.mpd,-1);}
        }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }







}
void afficherUtilisateur(GtkWidget *liste, char *filename){


 GtkCellRenderer *renderer; // afficheur de cellule (Cellule contient un texte, image, case à cocher)
      GtkTreeViewColumn *column; // visualisation des colonnes
       GtkTreeIter iter;          /**/
       GtkListStore *store;       // création du modèle de type liste

  char jj[50],mm[50],yy[50];
    store = NULL;
   utilisateur u;
    FILE *f;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        
	renderer=gtk_cell_renderer_text_new();                                                               // cellule contenant du texte
        column = gtk_tree_view_column_new_with_attributes("CIN ", renderer, "text", ECIN, NULL); // création d'une colonne avec du texte
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);                                             // associer la colonne à l'afficheur (GtkTreeView)

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("NOM", renderer, "text", ENOM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("PRENOM", renderer, "text", EPRENOM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text", EDATEJJ, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text", EDATEMM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Année", renderer, "text", EDATEYY, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("GENRE", renderer, "text", EGENRE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("REGION", renderer, "text", EREGION, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

         renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("NUMERO", renderer, "text", ENUM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ROLE", renderer, "text", EROLE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("LOGIN", renderer, "text", ELOGIN, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("PASSWORD", renderer, "text", EPASS, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        // La liste contient 7 colonnes de type chaine de caractères
    }
   store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);


     


              f = fopen(filename, "r");

    if (f == NULL)
    {
        return;
    }
    else
    {
       
        while (fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s\n",u.Cin,u.nom,u.prenom,&u.dateNaissance.jj,&u.dateNaissance.mm,&u.dateNaissance.yy,u.genre,u.Region,u.num,u.Role,u.login,u.mpd)!=EOF)
        {

         sprintf(jj,"%d",u.dateNaissance.jj);
         sprintf(mm,"%d",u.dateNaissance.mm);
         sprintf(yy,"%d",u.dateNaissance.yy);
        
        





            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter,ECIN,u.Cin,ENOM,u.nom,EPRENOM,u.prenom,EDATEJJ,jj,EDATEMM,mm,EDATEYY,yy,EGENRE,u.genre,EREGION,u.Region,ENUM,u.num,EROLE,u.Role,ELOGIN,u.login,EPASS,u.mpd,-1);
        }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }














}


void viderUtilisateur(GtkWidget *liste){


 GtkCellRenderer *renderer; // afficheur de cellule (Cellule contient un texte, image, case à cocher)
      GtkTreeViewColumn *column; // visualisation des colonnes
       GtkTreeIter iter;          /**/
       GtkListStore *store;       // création du modèle de type liste

  char jj[50],mm[50],yy[50];
    store = NULL;
   utilisateur u;
    FILE *f;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        
	renderer=gtk_cell_renderer_text_new();                                                               // cellule contenant du texte
        column = gtk_tree_view_column_new_with_attributes("CIN ", renderer, "text", ECIN, NULL); // création d'une colonne avec du texte
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);                                             // associer la colonne à l'afficheur (GtkTreeView)

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("NOM", renderer, "text", ENOM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("PRENOM", renderer, "text", EPRENOM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text", EDATEJJ, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text", EDATEMM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Année", renderer, "text", EDATEYY, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("GENRE", renderer, "text", EGENRE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("REGION", renderer, "text", EREGION, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

         renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("NUMERO", renderer, "text", ENUM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ROLE", renderer, "text", EROLE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("LOGIN", renderer, "text", ELOGIN, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("PASSWORD", renderer, "text", EPASS, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        // La liste contient 7 colonnes de type chaine de caractères
    }
   store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);











}
int ajouterUtilisateur(char * filename, utilisateur u ){
         FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %d %d %d %s %s %s %s %s %s\n",u.Cin,u.nom,u.prenom,u.dateNaissance.jj,u.dateNaissance.mm,u.dateNaissance.yy,u.genre,u.Region,u.num,u.Role,u.login,u.mpd);
        fclose(f);
        return 1;
    }
    else return 0;


}


int modifierUtilisateur( char * filename, char *Cin , utilisateur nouv){

   int tr=0;
    utilisateur u;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s\n",u.Cin,u.nom,u.prenom,&u.dateNaissance.jj,&u.dateNaissance.mm,&u.dateNaissance.yy,u.genre,u.Region,u.num,u.Role,u.login,u.mpd)!=EOF)
        {
            if(strcmp(u.Cin,Cin)==0)
            {
                fprintf(f2,"%s %s %s %d %d %d %s %s %s %s %s %s\n",nouv.Cin,nouv.nom,nouv.prenom,nouv.dateNaissance.jj,nouv.dateNaissance.mm,nouv.dateNaissance.yy,nouv.genre,nouv.Region,nouv.num,nouv.Role,nouv.login,nouv.mpd);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %d %d %d %s %s %s %s %s %s\n",u.Cin,u.nom,u.prenom,u.dateNaissance.jj,u.dateNaissance.mm,u.dateNaissance.yy,u.genre,u.Region,u.num,u.Role,u.login,u.mpd);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;


}


int supprimerUtilisateur(char * filename, char *Cin ){


   int tr=0;
    utilisateur u;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s\n",u.Cin,u.nom,u.prenom,&u.dateNaissance.jj,&u.dateNaissance.mm,&u.dateNaissance.yy,u.genre,u.Region,u.num,u.Role,u.login,u.mpd)!=EOF)
        {
            if(strcmp(u.Cin,Cin)==0)
                tr=1;
            else
                fprintf(f2,"%s %s %s %d %d %d %s %s %s %s %s %s\n",u.Cin,u.nom,u.prenom,u.dateNaissance.jj,u.dateNaissance.mm,u.dateNaissance.yy,u.genre,u.Region,u.num,u.Role,u.login,u.mpd);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

utilisateur chercherUtilisateurByCin(char *filename, char *Cin){


    utilisateur u;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s\n",u.Cin,u.nom,u.prenom,&u.dateNaissance.jj,&u.dateNaissance.mm,&u.dateNaissance.yy,u.genre,u.Region,u.num,u.Role,u.login,u.mpd)!=EOF)
        {
            if(strcmp(u.Cin,Cin)==0)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        strcpy(u.Cin,"-1");
    return u;

}




int listeUtilisateur(char *filename ,utilisateur *resultat ){

    utilisateur u;

     int i = 0;
      FILE * f=fopen(filename, "r");
        if(f!=NULL)
    {
        while( fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s\n",u.Cin,u.nom,u.prenom,&u.dateNaissance.jj,&u.dateNaissance.mm,&u.dateNaissance.yy,u.genre,u.Region,u.num,u.Role,u.login,u.mpd)!=EOF)
        {

             resultat[i] = u;
               i++;

        }
    }
    fclose(f);
    return i;

}
void afficherPourcentageParSexe(char *filename,float *pourcentageHommes,float *pourcentageFemmes )
{

    utilisateur u;
    int nombreHommes=0;
    int nombreFemmes=0;
    int nbUtilisateur = 0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while( fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s\n",u.Cin,u.nom,u.prenom,&u.dateNaissance.jj,&u.dateNaissance.mm,&u.dateNaissance.yy,u.genre,u.Region,u.num,u.Role,u.login,u.mpd)!=EOF)
        {
            nbUtilisateur++;

            if (strcmp(u.genre, "Homme") == 0)
            {
                nombreHommes++;
            }
            else if (strcmp(u.genre, "Femme") == 0)
            {
                nombreFemmes++;
            }



        }

    }
    fclose(f);

    if (nbUtilisateur > 0)
    {
        *pourcentageHommes = (float)nombreHommes / (float)nbUtilisateur * 100;
        *pourcentageFemmes = (float)nombreFemmes / (float)nbUtilisateur * 100;

    }
    else
    {
        printf("Aucun utilisateur � afficher.\n");
    }
}


int listeUtilisateurByrole(char *filename,char *role,utilisateur *resultat){
     utilisateur u;

     int i = 0;
      FILE * f=fopen(filename, "r");
        if(f!=NULL)
    {
        while( fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s\n",u.Cin,u.nom,u.prenom,&u.dateNaissance.jj,&u.dateNaissance.mm,&u.dateNaissance.yy,u.genre,u.Region,u.num,u.Role,u.login,u.mpd)!=EOF)
        {
            if(strcmp(u.Role, role) == 0){
             resultat[i] = u;
               i++;
               }
        }
    }
    fclose(f);
    return i;
}
