#include <stdio.h>
#include <string.h>

#define MAX_NOM 50
#define MAX_TELEPHONE 15
#define MAX_EMAIL 50

typedef struct {
    
    char nom[MAX_NOM];
    char telephone[MAX_TELEPHONE];
    char email[MAX_EMAIL];

} Personne;

Personne creer_personne(const char* nom, const char* telephone, const char* email) {
    Personne p;
    strncpy(p.nom, nom, MAX_NOM);
    strncpy(p.telephone, telephone, MAX_TELEPHONE);
    strncpy(p.email, email, MAX_EMAIL);
    return p;
}

typedef struct {
    Personne contacts[100];
    int taille;
} CarnetDeContacts;

/* //TODO : Ajouter les fonctions pour ajouter, afficher, rechercher et supprimer des contacts dans le carnet de contacts. 
*/

void ajouter_contact(CarnetDeContacts* carnet, Personne p) {
    if (carnet->taille < 100) {
        carnet->contacts[carnet->taille] = p;
        carnet->taille++;
    } else {
        printf("Le carnet de contacts est plein.\n");
    }
}

void afficher_contacts(const CarnetDeContacts* carnet) {
    for (int i = 0; i < carnet->taille; i++) {
        printf("Nom: %s, Téléphone: %s, Email: %s\n", 
               carnet->contacts[i].nom, 
               carnet->contacts[i].telephone, 
               carnet->contacts[i].email);
    }
}

void rechercher_contact(const CarnetDeContacts* carnet, const char* nom) {
    for (int i = 0; i < carnet->taille; i++) {
        if (strcmp(carnet->contacts[i].nom, nom) == 0) {
            printf("Contact trouvé: Nom: %s, Téléphone: %s, Email: %s\n", 
                   carnet->contacts[i].nom, 
                   carnet->contacts[i].telephone, 
                   carnet->contacts[i].email);
            return;
        }
    }
    printf("Contact non trouvé.\n");
}

void supprimer_contact(CarnetDeContacts* carnet, const char* nom) {
    for (int i = 0; i < carnet->taille; i++) {
        if (strcmp(carnet->contacts[i].nom, nom) == 0) {
            for (int j = i; j < carnet->taille - 1; j++) {
                carnet->contacts[j] = carnet->contacts[j + 1];
            }
            carnet->taille--;
            printf("Contact supprimé.\n");
            return;
        }
    }
    printf("Contact non trouvé.\n");
}

void initialiser_carnet(CarnetDeContacts* carnet) {
    carnet->taille = 0;
    while (1) {
        printf("1. Ajouter un contact\n");
        printf("2. Afficher les contacts\n");
        printf("3. Rechercher un contact\n");
        printf("4. Supprimer un contact\n");
        printf("5. Quitter\n");
        int choix;
        scanf("%d", &choix);
        getchar(); // Consommer le caractère de nouvelle ligne restant dans le tampon

        if (choix == 1) {
            char nom[MAX_NOM];
            char telephone[MAX_TELEPHONE];
            char email[MAX_EMAIL];

            printf("Entrez le nom: ");
            fgets(nom, MAX_NOM, stdin);
            nom[strcspn(nom, "\n")] = 0; // Supprimer le caractère de nouvelle ligne

            printf("Entrez le téléphone: ");
            fgets(telephone, MAX_TELEPHONE, stdin);
            telephone[strcspn(telephone, "\n")] = 0;

            printf("Entrez l'email: ");
            fgets(email, MAX_EMAIL, stdin);
            email[strcspn(email, "\n")] = 0;

            Personne p = creer_personne(nom, telephone, email);
            ajouter_contact(carnet, p);
        } else if (choix == 2) {
            afficher_contacts(carnet);
        } else if (choix == 3) {
            char nom[MAX_NOM];
            printf("Entrez le nom à rechercher: ");
            fgets(nom, MAX_NOM, stdin);
            nom[strcspn(nom, "\n")] = 0;
            rechercher_contact(carnet, nom);
        } else if (choix == 4) {
            char nom[MAX_NOM];
            printf("Entrez le nom à supprimer: ");
            fgets(nom, MAX_NOM, stdin);
            nom[strcspn(nom, "\n")] = 0;
            supprimer_contact(carnet, nom);
        } else if (choix == 5) {
            break;
        } else {
            printf("Choix invalide.\n");
        }
    }
}