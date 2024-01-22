#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"utilisateur.h"
int g ;
int g1;
char filename1[50] = "houssem.txt";
void
on_treeviewU_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_Ubutton_AfficherByRole_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *role,*pInfo,*Uaffiche,*w1,*treeview;
       int b = 1;
    char role1[50];
    Uaffiche = lookup_widget(button,"Uaffiche");
     Uaffiche = create_Uaffiche();
    role = lookup_widget(button,"Ucombobox_filtre");
     strcpy(role1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));
      if(strcmp(role1,"")==0 ){
      
       pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Le champs est vide ");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 
               break;
}
     }else{

         
      w1=lookup_widget(button,"Uaffiche");
      Uaffiche=create_Uaffiche();
       gtk_widget_show(Uaffiche);
       gtk_widget_hide(w1);
       treeview=lookup_widget(Uaffiche,"treeviewU");
       viderUtilisateur(treeview);
       afficherUtilisateurByRole(treeview, filename1,role1);
}

}


void
on_UsearchButton_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
     GtkWidget *cin,*pInfo,*Uaffiche,*w1,*treeview;
       int b = 1;
    char cin1[50];
    Uaffiche = lookup_widget(button,"Uaffiche");
     Uaffiche = create_Uaffiche();
    cin = lookup_widget(button,"UsearchEntry");
     strcpy(cin1,gtk_entry_get_text(GTK_ENTRY(cin)));
      if(strcmp(cin1,"")==0 ){
      
       pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK," Le champs est vide ");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 
               break;}
     }else{

         
      w1=lookup_widget(button,"Uaffiche");
      Uaffiche=create_Uaffiche();
       gtk_widget_show(Uaffiche);
       gtk_widget_hide(w1);
       treeview=lookup_widget(Uaffiche,"treeviewU");
       viderUtilisateur(treeview);
       afficherUtilisateurByCin(treeview, filename1,cin1);
}
}



void
on_UgenreFemmeAjout_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
     if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{g=2;} 
}


void
on_UgenreHommeAjout_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{g=1;} 
}

void
on_UgenreHommeModifier_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{g1=1;} 
}


void
on_UgenreFemmeModifier_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{g1=2;} 
}

void
on_UajoutWidget_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *Uajoute,*Uaffiche;
     Uaffiche = lookup_widget(button,"Uaffiche");
   gtk_widget_destroy(Uaffiche);
     Uajoute = lookup_widget(button,"Uajoute");
     Uajoute = create_Uajoute();
     gtk_widget_show(Uajoute);
}


void
on_UmodifierWidget_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *Umodife,*Uaffiche;
     Uaffiche = lookup_widget(button,"Uaffiche");
   gtk_widget_destroy(Uaffiche);
     Umodife = lookup_widget(button,"Umodife");
     Umodife = create_Umodife();
     gtk_widget_show(Umodife);
}


void
on_UsupprimerWidget_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *Usupprime,*Uaffiche;
     Uaffiche = lookup_widget(button,"Uaffiche");
   gtk_widget_destroy(Uaffiche);
     Usupprime = lookup_widget(button,"Usupprime");
     Usupprime = create_Usupprime();
     gtk_widget_show(Usupprime);
}


void
on_Uactualiser_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *Uaffiche,*w1,*treeview;
      w1=lookup_widget(button,"Uaffiche");
      Uaffiche=create_Uaffiche();
       gtk_widget_show(Uaffiche);
       gtk_widget_hide(w1);
       treeview=lookup_widget(Uaffiche,"treeviewU");
       viderUtilisateur(treeview);
       afficherUtilisateur(treeview,filename1);
}


void
on_UstatistiqueWidget_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *Ustatistique,*Uaffiche;
     Uaffiche = lookup_widget(button,"Uaffiche");
   gtk_widget_destroy(Uaffiche);
     Ustatistique = lookup_widget(button,"Ustatistique");
     Ustatistique = create_Ustatistique();
     gtk_widget_show(Ustatistique);
}


void
on_UannulerAjoutButton_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *Uajoute,*Uaffiche;
     Uajoute = lookup_widget(button,"Uajoute");
   gtk_widget_destroy(Uajoute);
     Uaffiche = lookup_widget(button,"Uaffiche");
     Uaffiche = create_Uaffiche();
     gtk_widget_show(Uaffiche);
}


void
on_UajoutButton_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *cin,*nom,*prenom,*jj,*mm,*yy,*region,*num,*role,*login,*mdp,*Uajoute,*label,*pInfo,*Uaffiche,*w1,*treeview;
   int b = 1;
   utilisateur u;
   Uajoute = lookup_widget(button,"Uajoute");
           Uajoute = create_Uajoute();
  cin = lookup_widget(button,"UcinEntryAjout");
  nom =lookup_widget(button,"UnomEntryAjout");
  prenom = lookup_widget(button,"UprenomEntryAjout");
  jj = lookup_widget(button,"UjjSpinAjout");
  mm = lookup_widget(button,"UmmSpinAjout");
  yy = lookup_widget(button,"UyySpinAjout");
  region = lookup_widget(button,"UregionComboAjout");
  num = lookup_widget(button,"UnumEntryAjout");
  role = lookup_widget(button,"UroleComboAjout");
  login = lookup_widget(button,"UloginEntryAjout");
  mdp = lookup_widget(button,"UmdpEntryAjout");
  label = lookup_widget(button,"UcontroleSaisiAjout");    

  strcpy(u.Cin,gtk_entry_get_text(GTK_ENTRY(cin)));
  strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
  strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
  u.dateNaissance.jj = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jj));
        u.dateNaissance.mm = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mm));
        u.dateNaissance.yy = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(yy));
  strcpy(u.Region,gtk_combo_box_get_active_text(GTK_COMBO_BOX(region)));
  strcpy(u.num,gtk_entry_get_text(GTK_ENTRY(num)));
   strcpy(u.Role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));
   strcpy(u.login,gtk_entry_get_text(GTK_ENTRY(login)));
   strcpy(u.mpd,gtk_entry_get_text(GTK_ENTRY(mdp)));

    if(g == 1){
     strcpy(u.genre,"Homme");
  }else{
       strcpy(u.genre,"Femme");

    }

     if(strcmp(u.Cin,"")==0 ){
      
           b=0;
             }
       if(strcmp(u.nom,"")==0 ){
      
           b=0;
             }
        if(strcmp(u.prenom,"")==0 ){
      
           b=0;
             }
      if(strcmp(u.Region,"")==0 ){
      
           b=0;
             }
        if(strcmp(u.num,"")==0 ){
      
           b=0;
             }
        if(strcmp(u.Role,"")==0 ){
      
           b=0;
             }
        if(strcmp(u.login,"")==0 ){
      
           b=0;
             }
          if(strcmp(u.mpd,"")==0 ){
      
           b=0;
             }
          
                 if(b == 1){
       int t =  ajouterUtilisateur(filename1,u);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Ajout avec succées ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 
                  gtk_entry_set_text(GTK_ENTRY(cin),"");
                  gtk_entry_set_text(GTK_ENTRY(nom),"");
                  gtk_entry_set_text(GTK_ENTRY(prenom),"");
                  gtk_entry_set_text(GTK_ENTRY(num),"");
                  gtk_entry_set_text(GTK_ENTRY(login),"");
                  gtk_entry_set_text(GTK_ENTRY(mdp),"");
                  
          		 gtk_widget_destroy(Uajoute);
              Uaffiche = lookup_widget(button,"Uaffiche");
             Uaffiche = create_Uaffiche();
             gtk_widget_show(Uaffiche);
                 w1=lookup_widget(button,"Uaffiche");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(Uaffiche,"treeviewU");
       viderUtilisateur(treeview);
       afficherUtilisateur(treeview, filename1);
               break;


          }
       }else{

          gtk_label_set_text(GTK_LABEL(label),"Echec d'ajouter  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"Vérifier votre données   ❌️");
     }

   
}


void
on_UafficherMdpAjout_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    GtkWidget *pass,*buttoncheck;
       pass = lookup_widget(togglebutton, "UmdpEntryAjout");
     buttoncheck = lookup_widget(togglebutton,"UafficherMdpAjout");
   
    if( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(buttoncheck))){
       gtk_entry_set_visibility(pass,TRUE);
   }else{
       gtk_entry_set_visibility(pass,FALSE);
   }
}





void
on_UsupprimerButton_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *cin,*Usupprime,*label,*pInfo,*Uaffiche,*w1,*treeview;
      int b = 1;
    char cin1[50];
   Usupprime = lookup_widget(button,"Usupprime");
           Usupprime = create_Usupprime();
  cin = lookup_widget(button,"UidEntrySupprimer");
 
  label = lookup_widget(button,"UcontroleSaisiSupprimer");    

  strcpy(cin1,gtk_entry_get_text(GTK_ENTRY(cin)));
 
  

     if(strcmp(cin1,"")==0 ){
      
           b=0;
             }
      
          
                 if(b == 1){
       int t =  supprimerUtilisateur(filename1,cin1);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Suppression avec succées ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 
                  gtk_entry_set_text(GTK_ENTRY(cin),"");
                  
                  
          		 gtk_widget_destroy(Usupprime);
              Uaffiche = lookup_widget(button,"Uaffiche");
             Uaffiche = create_Uaffiche();
             gtk_widget_show(Uaffiche);
                 w1=lookup_widget(button,"Uaffiche");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(Uaffiche,"treeviewU");
       viderUtilisateur(treeview);
       afficherUtilisateur(treeview,filename1);
               break;


          }
       }else{

          gtk_label_set_text(GTK_LABEL(label),"Echec du suppression ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"Vérifier votre données   ❌️");
     }
}


void
on_UannulerSupprimerButton_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *Usupprime,*Uaffiche;
     Usupprime = lookup_widget(button,"Usupprime");
   gtk_widget_destroy(Usupprime);
     Uaffiche = lookup_widget(button,"Uaffiche");
     Uaffiche = create_Uaffiche();
     gtk_widget_show(Uaffiche);
}


void
on_FDstatistiqueButton_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
     GtkWidget *labelHomme,*labelFemme,*Ustatistique;
       char homme[50],femme[50];
       Ustatistique = lookup_widget(button,"Ustatistique");
     Ustatistique = create_Ustatistique();
       labelHomme  = lookup_widget(button,"UpourcentageHommeLabelStatistique");
        labelFemme = lookup_widget(button,"UpourcentageFemmeLabelStatistique");
       float nbH ,nbF;
     afficherPourcentageParSexe(filename1,&nbH,&nbF);
    sprintf(homme,"%.2f",nbH);
    sprintf(femme,"%.2f",nbF);

     gtk_label_set_text(GTK_LABEL(labelHomme),homme);
     gtk_label_set_text(GTK_LABEL(labelFemme),femme);
}


void
on_UannulerStatistiqueButton_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *Ustatistique,*Uaffiche;
     Ustatistique = lookup_widget(button,"Ustatistique");
   gtk_widget_destroy(Ustatistique);
     Uaffiche = lookup_widget(button,"Uaffiche");
     Uaffiche = create_Uaffiche();
     gtk_widget_show(Uaffiche);
}


void
on_UModifierButton_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *cin,*nom,*prenom,*jj,*mm,*yy,*region,*num,*role,*login,*mdp,*Umodife,*label,*pInfo,*Uaffiche,*w1,*treeview;
   int b = 1;
   utilisateur u;
   Umodife = lookup_widget(button,"Umodife");
           Umodife = create_Umodife();
  cin = lookup_widget(button,"UcinEntryModifier");
  nom =lookup_widget(button,"UnomEntryModifier");
  prenom = lookup_widget(button,"UprenomEntryModifier");
  jj = lookup_widget(button,"UjjSpinModifier");
  mm = lookup_widget(button,"UmmSpinModifier");
  yy = lookup_widget(button,"UyySpinModifier");
  region = lookup_widget(button,"UregionComboModifier");
  num = lookup_widget(button,"UnumEntryModifier");
  role = lookup_widget(button,"UroleComboModifier");
  login = lookup_widget(button,"UloginEntryModifier");
  mdp = lookup_widget(button,"UmdpEntryModifier");
  label = lookup_widget(button,"UcontroleSaisiModifier");    

  strcpy(u.Cin,gtk_entry_get_text(GTK_ENTRY(cin)));
  strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
  strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
  u.dateNaissance.jj = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jj));
        u.dateNaissance.mm = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mm));
        u.dateNaissance.yy = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(yy));
  strcpy(u.Region,gtk_combo_box_get_active_text(GTK_COMBO_BOX(region)));
  strcpy(u.num,gtk_entry_get_text(GTK_ENTRY(num)));
   strcpy(u.Role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));
   strcpy(u.login,gtk_entry_get_text(GTK_ENTRY(login)));
   strcpy(u.mpd,gtk_entry_get_text(GTK_ENTRY(mdp)));

    if(g == 1){
     strcpy(u.genre,"Homme");
  }else{
       strcpy(u.genre,"Femme");

    }

     if(strcmp(u.Cin,"")==0 ){
      
           b=0;
             }
       if(strcmp(u.nom,"")==0 ){
      
           b=0;
             }
        if(strcmp(u.prenom,"")==0 ){
      
           b=0;
             }
      if(strcmp(u.Region,"")==0 ){
      
           b=0;
             }
        if(strcmp(u.num,"")==0 ){
      
           b=0;
             }
        if(strcmp(u.Role,"")==0 ){
      
           b=0;
             }
        if(strcmp(u.login,"")==0 ){
      
           b=0;
             }
          if(strcmp(u.mpd,"")==0 ){
      
           b=0;
             }
          
                 if(b == 1){
       int t =  modifierUtilisateur(filename1,u.Cin,u);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Modification avec succées ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 
                  gtk_entry_set_text(GTK_ENTRY(cin),"");
                  gtk_entry_set_text(GTK_ENTRY(nom),"");
                  gtk_entry_set_text(GTK_ENTRY(prenom),"");
                  gtk_entry_set_text(GTK_ENTRY(num),"");
                  gtk_entry_set_text(GTK_ENTRY(login),"");
                  gtk_entry_set_text(GTK_ENTRY(mdp),"");
                  
          		 gtk_widget_destroy(Umodife);
              Uaffiche = lookup_widget(button,"Uaffiche");
             Uaffiche = create_Uaffiche();
             gtk_widget_show(Uaffiche);
                 w1=lookup_widget(button,"Uaffiche");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(Uaffiche,"treeviewU");
       viderUtilisateur(treeview);
       afficherUtilisateur(treeview, filename1);
               break;


          }
       }else{

          gtk_label_set_text(GTK_LABEL(label),"Echec de modification  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"Vérifier votre données   ❌️");
     }

}


void
on_UannulerModifierButton_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *Umodife,*Uaffiche;
     Umodife = lookup_widget(button,"Umodife");
   gtk_widget_destroy(Umodife);
     Uaffiche = lookup_widget(button,"Uaffiche");
     Uaffiche = create_Uaffiche();
     gtk_widget_show(Uaffiche);
}


void
on_UafficherMdpModifier_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
     GtkWidget *pass,*buttoncheck;
       pass = lookup_widget(togglebutton, "UmdpEntryModifier");
     buttoncheck = lookup_widget(togglebutton,"UafficherMdpModifier");
   
    if( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(buttoncheck))){
       gtk_entry_set_visibility(pass,TRUE);
   }else{
       gtk_entry_set_visibility(pass,FALSE);
   }
}





void
on_UbuttonRechercherIDModifier_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *cin,*nom,*prenom,*jj,*mm,*yy,*region,*num,*role,*login,*mdp,*Umodife,*label,*pInfo,*Uaffiche,*w1,*treeview;
   int b = 1;
   utilisateur u;
   char cin1[50];
   Umodife = lookup_widget(button,"Umodife");
           Umodife = create_Umodife();
  cin = lookup_widget(button,"UcinEntryModifier");
  nom =lookup_widget(button,"UnomEntryModifier");
  prenom = lookup_widget(button,"UprenomEntryModifier");

  region = lookup_widget(button,"UregionComboModifier");
  num = lookup_widget(button,"UnumEntryModifier");
  role = lookup_widget(button,"UroleComboModifier");
  login = lookup_widget(button,"UloginEntryModifier");
  mdp = lookup_widget(button,"UmdpEntryModifier");
  label = lookup_widget(button,"UcontroleSaisiModifier");    

  strcpy(cin1,gtk_entry_get_text(GTK_ENTRY(cin)));
 



     if(strcmp(cin1,"")==0 ){
      
           b=0;
             }

         if(b == 1){

     u =  chercherUtilisateurByCin(filename1, cin1);
       if(strcmp(u.Cin,"-1")==0){

pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Pas trouvé ");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 gtk_entry_set_text(GTK_ENTRY(cin),"");
               break;}

          }else{
                 
                 
              gtk_entry_set_text(GTK_ENTRY(cin),u.Cin);
                  gtk_entry_set_text(GTK_ENTRY(nom),u.nom);
                  gtk_entry_set_text(GTK_ENTRY(prenom),u.prenom);
                  gtk_entry_set_text(GTK_ENTRY(num),u.num);
                  gtk_entry_set_text(GTK_ENTRY(login),u.login);
                  gtk_entry_set_text(GTK_ENTRY(mdp),u.mpd);
                 
                 // gtk_combo_box_set_active_iter(region, p.region);
          }



     }else if (b == 0){

         gtk_label_set_text(GTK_LABEL(label),"Verifier votre carte d'identité (Cin)   ❌️");

       }
      
}

