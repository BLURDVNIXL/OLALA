class Personne:
    def __init__(self, nom, telephone, email):
        self.nom = nom
        self.telephone = telephone
        self.email = email

contact=[]

def ajouter_contact(nom, telephone, email):
    personne = Personne(nom, telephone, email)
    contact.append(personne)

def afficher_contacts():
    for personne in contact:
        print(f"Nom: {personne.nom}, Téléphone: {personne.telephone}, Email: {personne.email}")

def rechercher_contact(nom):
    for personne in contact:
        if personne.nom == nom:
            print(f"Nom: {personne.nom}, Téléphone: {personne.telephone}, Email: {personne.email}")
            return
    print("Contact non trouvé.")


#test
a=True
while a:
    print("\n\tCarnet de contacts\n1. Ajouter un contact\n2. Afficher les contacts\n3. Rechercher un contact\n4. Quitter")
    choix = input("Choisissez une option: ")

    if choix == "1":
        nom = input("Entrez le nom: ")
        telephone = input("Entrez le numéro de téléphone: ")
        email = input("Entrez l'email: ")
        ajouter_contact(nom, telephone, email)
    elif choix == "2":
        afficher_contacts()
    elif choix == "3":
        nom = input("Entrez le nom à rechercher: ")
        rechercher_contact(nom)
    elif choix == "4":
        a=False
    else:
        print("Option invalide.")
