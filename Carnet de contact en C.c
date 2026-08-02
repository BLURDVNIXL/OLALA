#include <stdio.h>
#include <string.h>

#define MAX_NOM 50
#define MAX_TELEPHONE 15
#define MAX_EMAIL 50
#define MAX_CONTACTS 100


typedef struct {

    char nom[MAX_NOM];
    char telephone[MAX_TELEPHONE];
    char email[MAX_EMAIL];

} Personne;


Personne creer_personne(const char* nom, const char* telephone, const char* email)
{
    Personne p;

    strncpy(p.nom, nom, MAX_NOM - 1);
    p.nom[MAX_NOM - 1] = '\0';

    strncpy(p.telephone, telephone, MAX_TELEPHONE - 1);
    p.telephone[MAX_TELEPHONE - 1] = '\0';

    strncpy(p.email, email, MAX_EMAIL - 1);
    p.email[MAX_EMAIL - 1] = '\0';

    return p;
}


typedef struct {

    Personne contacts[MAX_CONTACTS];
    int taille;

} CarnetDeContacts;



void ajouter_contact(CarnetDeContacts* carnet, Personne p)
{
    if (carnet->taille < MAX_CONTACTS)
    {
        carnet->contacts[carnet->taille] = p;
        carnet->taille++;
        printf("Contact ajouté avec succès.\n");
    }
    else
    {
        printf("Le carnet de contacts est plein.\n");
    }
}



void afficher_contacts(const CarnetDeContacts* carnet)
{
    if (carnet->taille == 0)
    {
        printf("Aucun contact enregistré.\n");
        return;
    }

    for (int i = 0; i < carnet->taille; i++)
    {
        printf("\nContact %d\n", i + 1);
        printf("Nom : %s\n", carnet->contacts[i].nom);
        printf("Téléphone : %s\n", carnet->contacts[i].telephone);
        printf("Email : %s\n", carnet->contacts[i].email);
    }
}



void rechercher_contact(const CarnetDeContacts* carnet, const char* nom)
{
    for (int i = 0; i < carnet->taille; i++)
    {
        if (strcmp(carnet->contacts[i].nom, nom) == 0)
        {
            printf("\nContact trouvé :\n");
            printf("Nom : %s\n", carnet->contacts[i].nom);
            printf("Téléphone : %s\n", carnet->contacts[i].telephone);
            printf("Email : %s\n", carnet->contacts[i].email);
            return;
        }
    }

    printf("Contact non trouvé.\n");
}



void supprimer_contact(CarnetDeContacts* carnet, const char* nom)
{
    for (int i = 0; i < carnet->taille; i++)
    {
        if (strcmp(carnet->contacts[i].nom, nom) == 0)
        {
            for (int j = i; j < carnet->taille - 1; j++)
            {
                carnet->contacts[j] = carnet->contacts[j + 1];
            }

            carnet->taille--;

            printf("Contact supprimé.\n");
            return;
        }
    }

    printf("Contact non trouvé.\n");
}



void menu_carnet(CarnetDeContacts* carnet)
{
    while (1)
    {
        printf("\n");
        printf("---------- Carnet de Contacts ----------\n");
        printf("1. Ajouter un contact\n");
        printf("2. Afficher les contacts\n");
        printf("3. Rechercher un contact\n");
        printf("4. Supprimer un contact\n");
        printf("5. Quitter\n");

        printf("Choix : ");

        int choix;
        scanf("%d", &choix);
        getchar(); // enlève le '\n' restant


        switch (choix)
        {

        case 1:
        {
            char nom[MAX_NOM];
            char telephone[MAX_TELEPHONE];
            char email[MAX_EMAIL];


            printf("Nom : ");
            fgets(nom, MAX_NOM, stdin);
            nom[strcspn(nom, "\n")] = '\0';


            printf("Téléphone : ");
            fgets(telephone, MAX_TELEPHONE, stdin);
            telephone[strcspn(telephone, "\n")] = '\0';


            printf("Email : ");
            fgets(email, MAX_EMAIL, stdin);
            email[strcspn(email, "\n")] = '\0';


            Personne p = creer_personne(nom, telephone, email);

            ajouter_contact(carnet, p);

            break;
        }


        case 2:
            afficher_contacts(carnet);
            break;


        case 3:
        {
            char nom[MAX_NOM];

            printf("Nom à rechercher : ");
            fgets(nom, MAX_NOM, stdin);
            nom[strcspn(nom, "\n")] = '\0';

            rechercher_contact(carnet, nom);

            break;
        }


        case 4:
        {
            char nom[MAX_NOM];

            printf("Nom à supprimer : ");
            fgets(nom, MAX_NOM, stdin);
            nom[strcspn(nom, "\n")] = '\0';

            supprimer_contact(carnet, nom);

            break;
        }


        case 5:
            printf("Au revoir !\n");
            return;


        default:
            printf("Choix invalide.\n");
        }
    }
}



int main(void)
{
    CarnetDeContacts carnet;

    carnet.taille = 0;

    menu_carnet(&carnet);

    return 0;
}