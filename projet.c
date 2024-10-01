#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONTACTS 5

typedef struct {
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
    if(numbercontacts < MAX_CONTACTS){
    for(int i = 0; i < nombert; i++) {

        printf("Nom: ");
        scanf(" %[^\n]s",contacts[numbercontacts].Nom);
        printf("Numero_telephone: ");
        scanf(" %[^\n]s",&contacts[numbercontacts].Numero_telephone);
        printf("Adresse_e_mail: ");
        scanf(" %[^\n]s",contacts[numbercontacts].Adresse_e_mail);

        printf("Nom :'%s' , numero de telephone : '%s' , adresse e-mail : '%s' . \n",contacts[numbercontacts].Nom,contacts[numbercontacts].Numero_telephone,contacts[numbercontacts].Adresse_e_mail);
        printf(" ajoute avec succes!\n\n\n");
        numbercontacts++;
    }
    }
     else {
        printf("limite de contacts atteinte. Impossible d'ajouter plus de contacts.\n\n\n");
    }
}

void affichertcontact(Contacts contacts[]){
    for (int i = 0 ; i < numbercontacts ; i++){

        printf("nom : %s <<< numero de telephone : %s <<< adresse e-mail : %s.\n\n\n",contacts[i].Nom,contacts[i].Numero_telephone,contacts[i].Adresse_e_mail);
    }
}


void ModifierContact(Contacts contacts[]){
    char nommodifier[50];
    int a ;
    char temptelephone[50];
    char tempmail[100];
    printf("Entrer le nom de contact  a rechercher: ");
    scanf("%s", nommodifier);
    for (int i = 0; i < numbercontacts; i++) {
        if (strcmp(contacts[i].Nom, nommodifier) == 0) {

                printf("nom : %s <<< numero de telephone : %s <<< adresse e-mail : %s.\n",contacts[i].Nom,contacts[i].Numero_telephone,contacts[i].Adresse_e_mail);

    printf("1.modifier le numero de telephone . \n");
    printf("2.modifier l'adresse e-mail . \n");
    printf("choisir un nomber :");
    scanf("%d",&a);
    switch(a){
        case 1: printf("modifier le numero de telephone :");
                scanf(" %s",temptelephone);
                strcpy( contacts[i].Numero_telephone,temptelephone);
                printf("le numero de telephone est modifier avec succes!\n\n\n");
                break;
        case 2: printf("modifier l'adresse e-mail  :");
                scanf(" %s",&tempmail);
                strcpy(contacts[i].Adresse_e_mail,tempmail);
                printf("le numero de telephone est modifier avec succes!\n\n\n");
                break;
        default:printf("ce choie n'existe pas \n\n");
                break;
        }
       }
    }
}

void supprimercontact(Contacts contacts[]){
    char nomsupprimer[50];
    printf("Entrer le nom de contact a rechercher: ");
    scanf("%s", nomsupprimer);

    int found = 0;

    for (int i = 0; i < numbercontacts; i++) {
        if (strcmp(contacts[i].Nom, nomsupprimer) == 0) {

            printf("Nom : %s <<< Numero de telephone : %s <<< Adresse e-mail : %s \n", contacts[i].Nom, contacts[i].Numero_telephone, contacts[i].Adresse_e_mail);

            for (int j = i; j < numbercontacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            found = 1;
            numbercontacts--;
            printf("Contact %s supprime avec succes!\n\n\n", nomsupprimer);
            break;
        }
    }

    if (!found) {
        printf("Ce nom n'existe pas \n\n");
    }
}

void RechercherContact(Contacts contacts[]){
    char nomrechercher[50];
    printf("Entrer le nom de contact a rechercher: ");
    scanf(" %[^\n]", nomrechercher);

    for (int i = 0; i < numbercontacts; i++) {
        if (strcmp(contacts[i].Nom, nomrechercher) == 0) {

            printf("Nom : %s <<< Numero de telephone : %s <<< Adresse e-mail : %s.\n\n",contacts[i].Nom, contacts[i].Numero_telephone, contacts[i].Adresse_e_mail);

            return;
        }
    }
    printf("Ce nom n'existe pas.\n\n");

}


void menu(){
    printf("Choose an option:\n");
    printf("1.Ajouter un contact \n");
    printf("2.modifier un contact \n");
    printf("3.Supprimer un contact \n");
    printf("4.afficher tout contact \n");
    printf("5.Rechercher un Contact \n");
    printf("0. Exit\n\n");
    printf("Enter your choice: ");
}
int main()
{
    char nommodifier[50];
    char nomsupprimer[50];
    char nomrechercher[50];
    Contacts contacts[MAX_CONTACTS];
    int choice;
    do{
    menu();
    scanf("%d", &choice);
    switch(choice){
        case 1 :ajoutercontacts(contacts);
        break;
        case 2 :ModifierContact(contacts);
        break;
        case 3:supprimercontact(contacts);
        break;
        case 4:affichertcontact(contacts);
        break;
        case 5:RechercherContact(contacts);
        break;
        case 0 :printf("Quitter le programme.\n");
        break;
        default :
            printf("Cette option n'existe pas");
    }
    }while(choice != 0);

    return 0;
}