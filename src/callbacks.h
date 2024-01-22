#include <gtk/gtk.h>


void
on_treeviewU_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_Ubutton_AfficherByRole_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_UsearchButton_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_Udeconnexcion_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_UajoutWidget_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_UmodifierWidget_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_UsupprimerWidget_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_Uactualiser_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_UstatistiqueWidget_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_UannulerAjoutButton_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_UajoutButton_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_UafficherMdpAjout_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_UgenreFemmeAjout_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_UgenreHommeAjout_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_UsupprimerButton_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_UannulerSupprimerButton_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_FDstatistiqueButton_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_UannulerStatistiqueButton_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_UModifierButton_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_UannulerModifierButton_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_UafficherMdpModifier_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_UgenreHommeModifier_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_UgenreFemmeModifier_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_UbuttonRechercherIDModifier_clicked (GtkButton       *button,
                                        gpointer         user_data);
