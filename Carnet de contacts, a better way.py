
class Personne:
    def __init__(self, nom: str, telephone: str, email: str) -> None:
        self.nom = nom
        self.telephone = telephone
        self.email = email

    def __str__(self):
        return f"Nom: {self.nom}, Téléphone: {self.telephone}, Email: {self.email}"
    
class CarnetDeContacts:
    def __init__(self) -> None:
        self.contacts= {}

    def ajouter_contact(self, personne: Personne) -> None:
        self.contacts[personne.nom] = personne

    def afficher_contacts(self) -> None:
        if not self.contacts:
            print("Aucun contact enregistré.")
            return

        for contact in self.contacts:
            print(self.contacts[contact])

    def rechercher_contact(self, nom: str) -> Personne | None:
        return self.contacts.get(nom)

    def supprimer_contact(self, nom: str) -> bool:
        if nom in self.contacts:
            del self.contacts[nom]
            return True
        return False

#initialisation du carnet de contacts
carnet = CarnetDeContacts()
while True:
    print("\n\n\t---------- Carnet de Contacts --------\nQue voulez-vous faire ?\n1. Ajouter un contact\n2. Afficher les contacts\n3. Rechercher un contact\n4. Supprimer un contact\n5. Quitter")
    choix = input("Entrez votre choix (1-5): ")
    match choix:
        case "1":
            nom = input("Entrez le nom du contact: ")
            telephone = input("Entrez le numéro de téléphone du contact: ")
            email = input("Entrez l'email du contact: ")
            personne = Personne(nom, telephone, email)
            carnet.ajouter_contact(personne)
            print(f"Contact {nom} ajouté avec succès.")
        case "2":
            print("Liste des contacts:")
            carnet.afficher_contacts()
        case "3":
            nom = input("Entrez le nom du contact à rechercher: ")
            contact = carnet.rechercher_contact(nom)
            if contact:
                print("Contact trouvé:")
                print(contact)
            else:
                print(f"Aucun contact trouvé avec le nom {nom}.")
        case "4":
            nom = input("Entrez le nom du contact à supprimer: ")
            if carnet.supprimer_contact(nom):
                print(f"Contact {nom} supprimé avec succès.")
            else:
                print(f"Aucun contact trouvé avec le nom {nom}.")
        case "5":
            print("Au revoir!")
            break