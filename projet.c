#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIVRE 10

typedef struct {
    int id;
    char Nom[50];
    char Numero_telephone[50];
    char Adresse_e_mail[100] ;
} Contacts;
 int numbercontacts = 0;


void ajoutercontacts(Contacts contacts[]){
    int nombert;
    printf("Vous avez choisi d'ajouter un nouveau CONTACTS.\n");
    printf("combien des contacts tu veux ajouter :");
    scanf("%d",&nombert);
    if(numbercontacts < MAX_LIVRE){

    contacts[numbercontacts].id = numbercontacts+1;
    for(int i = 0; i < nombert; i++) {

        contacts[numbercontacts].id = numbercontacts+1;
        printf("Contacts:%d \n",contacts[numbercontacts].id);
        printf("Nom: ");
        scanf(" %[^\n]s",contacts[numbercontacts].Nom);
        printf("Numero_telephone: ");
        scanf(" %[^\n]s",&contacts[numbercontacts].Numero_telephone);
        printf("Adresse_e_mail: ");
        scanf(" %[^\n]s",contacts[numbercontacts].Adresse_e_mail);
        printf("contact : %d \n",contacts[numbercontacts].id);
        printf("Nom :'%s' , numero de telephone : '%s' , adresse e-mail : '%s' . \n",contacts[numbercontacts].Nom,contacts[numbercontacts].Numero_telephone,contacts[numbercontacts].Adresse_e_mail);
        printf(" ajoute avec succes!\n\n\n");
        numbercontacts++;
    }
    }
     else {
        printf("limite de contacts atteinte. Impossible d'ajouter plus de contacts.\n\n\n");
    }
}

void ModifierContact(Contacts contacts[],int numbercontacts,char nommodifier[]){
    int a ;
    printf("Entrer le titre de livre  a rechercher: ");
    scanf("%s", nommodifier);
    for (int i = 0; i < numbercontacts; i++) {
        if (strcmp(contacts[i].Nom, nommodifier) == 0) {
                printf("contact : %d \n",contacts[i].id) ;
                printf("nom : %s <<< numero de telephone : %s <<< adresse e-mail : %s.\n",contacts[i].Nom,contacts[i].Numero_telephone,contacts[i].Adresse_e_mail);
        }

    }
    printf("1.modifier le numero de telephone . \n");
    printf("2.modifier l'adresse e-mail . \n");
    printf("choisir un nomber :");
    scanf("%d",&a);
    switch(a){
        case 1: printf("modifier le numero de telephone :");
                scanf("%s", &contacts[numbercontacts-1].Numero_telephone);
                printf("le numero de telephone est modifier avec succes!\n\n\n");
                break;
        case 2: printf("modifier l'adresse e-mail  :");
                scanf("%s", &contacts[numbercontacts-1].Adresse_e_mail);
                printf("le numero de telephone est modifier avec succes!\n\n\n");
                break;
        default:printf("hbybhbyby");
                break;
        }
}
/*
void afficherlivre (Livre livre[]){
    for (int i = 0 ; i < numberlivre ; i++){
        printf("livre : %d \n",livre[i].id) ;
        printf("titre : %s <<< auteur : %s <<< prix : %.2f <<< stock : %d .\n\n\n",livre[i].titre,livre[i].auteur,livre[i].prix,livre[i].stock);
    }
}



void supprimerlivre(Livre livre[],int anumberlivre, char titrecom[]){
    printf("Entrer le titre de livre  a rechercher: ");
    scanf("%s", titrecom);
    int found = 0 ;
    int ids;
    char temtitre[20];
    char tempauteur[20];
    int tempP;
    float temq;

    for (int i = 0; i < numberlivre; i++) {

        if (strcmp(livre[i].titre, titrecom) == 0) {
            printf("livre : %d \n",livre[i].id) ;
            printf("titre : %s <<< auteur : %s <<< prix : %.2f <<< stock : %d .\n",livre[i].titre,livre[i].auteur , livre[i].prix ,livre[i].stock);

             strcpy(temtitre,livre[i].titre);
             strcpy(tempauteur,livre[i].auteur);
             tempP = livre[i].prix;
             temq = livre[i].stock;

             for(int j = 0 ; j < numberlivre ; j++  ){

               strcpy(livre[i].titre,livre[j+1].titre) ;
               strcpy(livre[i].auteur, livre[j+1].auteur ) ;
                livre[i].prix = livre[j+1].prix  ;
                livre[i].stock = livre[j+1].stock  ;
             }
             numberlivre -- ;
             printf("livre %s supprimé avec succès!\n\n\n", temtitre);
             break;
        }
    }
}

void affichagenombertotalstock(Livre livre[]){
    int s =0;
    for( int i = 0 ; i < numberlivre ;i++ ){
        s = s + livre[i].stock ;
    }
    printf("le nomber total des livre en stock %d \n\n\n: ",s);
}
*/
void menu(){
    printf("Choose an option:\n");
    printf("1.Ajouter un Livre \n");
    printf("2.Afficher Tous les Livres Disponibles \n");
    printf("3.Mettre a Jour la Quantite d'un Livre \n");
    printf("4.Supprimer un Livre du Stock \n");
    printf("5.Afficher le Nombre Total de Livres en Stock \n");
    printf("0. Exit\n\n");
    printf("Enter your choice: ");
}
int main()
{
    char nommodifier[50];
    Contacts contacts[MAX_LIVRE];
    int choice;
    do{
    menu();
    scanf("%d", &choice);
    switch(choice){
        case 1 :ajoutercontacts(contacts);
        break;
        case 2 :ModifierContact(contacts,numbercontacts,nommodifier);
        break;
       /* case 3:afficherlivre(contacts);
        break;
        case 4:supprimerlivre(contacts,numberlivre,titrecom);
        break;
        case 5:affichagenombertotalstock(contacts);
        break;
        case 0 :printf("Quitter le programme.\n");
                break;*/
        default :
            printf("Cette option n'existe pas");
    }
    }while(choice != 0);

    return 0;
}