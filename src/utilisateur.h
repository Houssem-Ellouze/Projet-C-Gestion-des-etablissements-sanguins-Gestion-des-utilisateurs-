#ifndef UTILISATEUR_H_INCLUDED
#define UTILISATEUR_H_INCLUDED
#include <gtk/gtk.h>
typedef struct {
  int jj;
  int mm;
  int yy;
}Date;
typedef struct {
  char Cin[50];
  char nom[50];
  char prenom[50];
  Date dateNaissance;
  char genre[50];
  char Region[50];
  char num[50];
  char Role[50];
  char login[50];
  char mpd[50];

}utilisateur;
void afficherUtilisateur(GtkWidget *liste, char *filename);
void afficherUtilisateurByRole(GtkWidget *liste, char *filename,char * role);
void afficherUtilisateurByCin(GtkWidget *liste, char *filename,char * Cin);
void viderUtilisateur(GtkWidget *liste);
int ajouterUtilisateur(char *, utilisateur );
int modifierUtilisateur( char *, char *, utilisateur );
int supprimerUtilisateur(char *,char * );
utilisateur chercherUtilisateurByCin(char *, char *);
int listeUtilisateur(char * ,utilisateur*);
void afficherPourcentageParSexe(char *,float *,float * );
int listeUtilisateurByrole(char *,char * ,utilisateur*);
#endif // UTILISATEUR_H_INCLUDED
