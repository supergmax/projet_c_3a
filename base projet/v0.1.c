#include <stdio.h>
#include <string.h>

struct Livre {
    char titre[100];
    char auteur[100];
    char isbn[20];
    char genre[50];
    int emprunte;
};

struct Emprunt {
    int idLivre;
    char emprunteur[100];
    char dateEmprunt[20];
};

void afficherMenuPrincipal() {
    printf("\nMenu Principal :\n");
    printf("1. Ajouter un livre\n");
    printf("2. Rechercher un livre\n");
    printf("3. Emprunter un livre\n");
    printf("4. Retourner un livre\n");
    printf("5. Afficher la liste des livres disponibles\n");
    printf("6. Afficher la liste des livres empruntés\n");
    printf("7. Quitter\n");
    printf("Entrez le numero de l option : ");
}

void sauvegarderLivres(struct Livre bibliotheque[], int nbLivres) {
    FILE *fichierLivres = fopen("livres.txt", "w");
    if (fichierLivres == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier de sauvegarde des livres.\n");
        return;
    }

    for (int i = 0; i < nbLivres; i++) {
        fprintf(fichierLivres, "%s|%s|%s|%s|%d\n", bibliotheque[i].titre, bibliotheque[i].auteur, bibliotheque[i].isbn, bibliotheque[i].genre, bibliotheque[i].emprunte);
    }

    fclose(fichierLivres);
}

void chargerLivres(struct Livre bibliotheque[], int *nbLivres) {
    FILE *fichierLivres = fopen("livres.txt", "r");
    if (fichierLivres == NULL) {
        return; // Le fichier n'existe pas encore, rien à charger.
    }

    while (fscanf(fichierLivres, "%[^|]|%[^|]|%[^|]|%[^|]|%d\n", bibliotheque[*nbLivres].titre, bibliotheque[*nbLivres].auteur, bibliotheque[*nbLivres].isbn, bibliotheque[*nbLivres].genre, &bibliotheque[*nbLivres].emprunte) == 5) {
        (*nbLivres)++;
    }

    fclose(fichierLivres);
}

void ajouterLivre(struct Livre bibliotheque[], int *nbLivres) {
    if (*nbLivres < 100) {
        printf("Nouveau livre :\n");
        printf("Titre : ");
        scanf("%s", bibliotheque[*nbLivres].titre);
        printf("Auteur : ");
        scanf("%s", bibliotheque[*nbLivres].auteur);
        printf("ISBN : ");
        scanf("%s", bibliotheque[*nbLivres].isbn);
        printf("Genre : ");
        scanf("%s", bibliotheque[*nbLivres].genre);
        bibliotheque[*nbLivres].emprunte = 0;
        (*nbLivres)++;
        printf("Livre ajouté avec succès.\n");

        // Sauvegardez les données de la bibliothèque après l'ajout
        sauvegarderLivres(bibliotheque, *nbLivres);
    } else {
        printf("La bibliothèque est pleine, impossible d'ajouter plus de livres.\n");
    }
}

void afficherListeLivres(struct Livre bibliotheque[], int nbLivres) {
    printf("Liste des livres disponibles :\n\n");
    for (int i = 0; i < nbLivres; i++) {
        if (bibliotheque[i].emprunte == 0) {
            printf("ID : %d\nTitre : %s\nAuteur : %s\nISBN : %s\nGenre : %s\n\n", i, bibliotheque[i].titre, bibliotheque[i].auteur, bibliotheque[i].isbn, bibliotheque[i].genre);
        }
    }
}

void emprunterLivre(struct Livre bibliotheque[], int nbLivres, int idLivre, char emprunteur[]) {
    if (idLivre >= 0 && idLivre < nbLivres) {
        if (bibliotheque[idLivre].emprunte == 0) {
            bibliotheque[idLivre].emprunte = 1;
            // Enregistrez les détails de l'emprunt ici (date d'emprunt, nom de l'emprunteur).
            printf("Le livre a été emprunté avec succès.\n");
        } else {
            printf("Ce livre est déjà emprunté.\n");
        }
    } else {
        printf("L'ID de livre n'est pas valide.\n");
    }
}

void afficherLivresEmpruntes(struct Livre bibliotheque[], struct Emprunt emprunts[], int nbLivres, int nbEmprunts) {
    printf("Liste des livres empruntés :\n");
    for (int i = 0; i < nbEmprunts; i++) {
        int idLivre = emprunts[i].idLivre;
        if (idLivre >= 0 && idLivre < nbLivres && bibliotheque[idLivre].emprunte == 1) {
            printf("ID : %d\nTitre : %s\nAuteur : %s\nEmprunteur : %s\nDate d'emprunt : %s\n\n", idLivre, bibliotheque[idLivre].titre, bibliotheque[idLivre].auteur, emprunts[i].emprunteur, emprunts[i].dateEmprunt);
        }
    }
}

void rechercherLivre(struct Livre bibliotheque[], int nbLivres) {
    char critere[100];
    int resultat_trouve = 0;

    printf("Rechercher un livre par titre ou auteur : ");
    scanf("%s", critere);

    printf("Résultats de la recherche :\n");
    for (int i = 0; i < nbLivres; i++) {
        // Comparez le critère avec le titre et l'auteur (vous pouvez ajouter plus de critères ici)
        if (strstr(bibliotheque[i].titre, critere) || strstr(bibliotheque[i].auteur, critere)) {
            printf("Titre : %s\nAuteur : %s\nISBN : %s\nGenre : %s\n\n", bibliotheque[i].titre, bibliotheque[i].auteur, bibliotheque[i].isbn, bibliotheque[i].genre);
            resultat_trouve = 1;
        }
    }

    if (!resultat_trouve) {
        printf("Aucun livre trouvé pour le critère \"%s\".\n", critere);
    }
}

int main() {
    struct Livre bibliotheque[100];
    int nbLivres = 0;
    struct Emprunt emprunts[100];
    int nbEmprunts = 0;
    
    // Chargement dles données depuis le fichier au démarrage
    chargerLivres(bibliotheque, &nbLivres);

    int choix = 0;
    do {
        afficherMenuPrincipal();
        scanf("%d", &choix);
        printf("\n");

        switch (choix) {
            case 1:
                ajouterLivre(bibliotheque, &nbLivres);
                break;
            case 2:
                rechercherLivre(bibliotheque, nbLivres); // Ajoutez la fonction de recherche de livres ici
                break;
            case 3:
                //ajoute la fonction emprun de livre
                break;
            case 4:
                // Ajoutez la fonction de retour de livres ici
                break;
            case 5:
                afficherListeLivres(bibliotheque, nbLivres);
                break;
            case 6:
                // Ajoutez la fonction pour afficher la liste des livres empruntés ici
                break;
            case 7:
                printf("Au revoir !\n");
                break;
            default:
                printf("Option invalide. Veuillez entrer un numéro valide.\n");
            // Lorsque l'utilisateur quitte le programme, les données seront sauvegardées automatiquement.
        }
    } while (choix != 7);

    return 0;
}
