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