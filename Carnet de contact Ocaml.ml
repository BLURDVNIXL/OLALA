(* //TODO : Ajouter les fonctions pour ajouter, afficher, rechercher et supprimer des contacts dans le carnet de contacts. *)


type personne = {
  nom : string;
  telephone : string;
  email : string;
}


type carnet = personne list



let afficher_personne p =
  Printf.printf
    "Nom : %s\nTéléphone : %s\nEmail : %s\n"
    p.nom
    p.telephone
    p.email



let ajouter_contact personne carnet =
  personne :: carnet



let daniel = {
  nom = "Daniel";
  telephone = "010203";
  email = "daniel@mail.com";
}



let carnet = []

let carnet = ajouter_contact daniel carnet

let () =
  afficher_personne daniel