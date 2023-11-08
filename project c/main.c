#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


struct Livre {
    char titre[100];    // Titre du livre
    char auteur[100];   // Auteur du livre
    char isbn[20];      // Numéro ISBN
    char genre[50];     // Genre du livre
    int emprunte;       // Indicateur d'emprunt (0 pour disponible, 1 pour emprunté)
    // Vous pouvez ajouter d'autres champs si nécessaire, comme la date de publication, le nombre de pages, etc.
};

struct Emprunt {
    int idLivre;       // Identifiant du livre emprunté
    char emprunteur[100];  // Nom de l'emprunteur
    char dateEmprunt[20]; // Date d'emprunt (peut être une chaîne de caractères au format "YYYY-MM-DD")
};

struct Livre bibliotheque[100];  // Tableau de livres (vous pouvez ajuster la taille selon vos besoins)
struct Emprunt emprunts[100];    // Tableau d'emprunts (ajustez la taille selon vos besoins)

void ajouterLivre(struct Livre bibliotheque[], int *nbLivres) {
    if (*nbLivres < 100) { // Vérifiez si la bibliothèque a de l'espace
        printf("Nouveau livre :\n");
        printf("Titre : ");
        scanf("%s", bibliotheque[*nbLivres].titre);
        printf("Auteur : ");
        scanf("%s", bibliotheque[*nbLivres].auteur);
        printf("ISBN : ");
        scanf("%s", bibliotheque[*nbLivres].isbn);
        printf("Genre : ");
        scanf("%s", bibliotheque[*nbLivres].genre);
        bibliotheque[*nbLivres].emprunte = 0; // Le livre est initialisé comme disponible
        (*nbLivres)++; // Incrémente le nombre de livres
        printf("Livre ajouté avec succès.\n");
    } else {
        printf("La bibliothèque est pleine, impossible d'ajouter plus de livres.\n");
    }
}


void rechercherParTitre(struct Livre bibliotheque[], int nbLivres, char titreRecherche[]) {
    printf("Livres correspondants au titre \"%s\" :\n", titreRecherche);
    for (int i = 0; i < nbLivres; i++) {
        if (strcmp(bibliotheque[i].titre, titreRecherche) == 0) {
            // Affichez les détails du livre trouvé
            printf("Titre : %s\nAuteur : %s\nISBN : %s\nGenre : %s\n\n", bibliotheque[i].titre, bibliotheque[i].auteur, bibliotheque[i].isbn, bibliotheque[i].genre);
        }
    }
}

void rechercherParTitre(struct Livre bibliotheque[], int nbLivres, char titreRecherche[]) {
    printf("Livres correspondants au titre \"%s\" :\n", titreRecherche);
    for (int i = 0; i < nbLivres; i++) {
        if (strcmp(bibliotheque[i].titre, titreRecherche) == 0) {
            // Affichez les détails du livre trouvé
            printf("Titre : %s\nAuteur : %s\nISBN : %s\nGenre : %s\n\n", bibliotheque[i].titre, bibliotheque[i].auteur, bibliotheque[i].isbn, bibliotheque[i].genre);
        }
    }
}


void rechercherParTitre(struct Livre bibliotheque[], int nbLivres, char titreRecherche[]) {
    printf("Livres correspondants au titre \"%s\" :\n", titreRecherche);
    for (int i = 0; i < nbLivres; i++) {
        if (strcmp(bibliotheque[i].titre, titreRecherche) == 0) {
            // Affichez les détails du livre trouvé
            printf("Titre : %s\nAuteur : %s\nISBN : %s\nGenre : %s\n\n", bibliotheque[i].titre, bibliotheque[i].auteur, bibliotheque[i].isbn, bibliotheque[i].genre);
        }
    }
}

void rechercherParTitre(struct Livre bibliotheque[], int nbLivres, char titreRecherche[]) {
    printf("Livres correspondants au titre \"%s\" :\n", titreRecherche);
    for (int i = 0; i < nbLivres; i++) {
        if (strcmp(bibliotheque[i].titre, titreRecherche) == 0) {
            // Affichez les détails du livre trouvé
            printf("Titre : %s\nAuteur : %s\nISBN : %s\nGenre : %s\n\n", bibliotheque[i].titre, bibliotheque[i].auteur, bibliotheque[i].isbn, bibliotheque[i].genre);
        }
    }
}

void rechercherParTitre(struct Livre bibliotheque[], int nbLivres, char titreRecherche[]) {
    printf("Livres correspondants au titre \"%s\" :\n", titreRecherche);
    for (int i = 0; i < nbLivres; i++) {
        if (strcmp(bibliotheque[i].titre, titreRecherche) == 0) {
            // Affichez les détails du livre trouvé
            printf("Titre : %s\nAuteur : %s\nISBN : %s\nGenre : %s\n\n", bibliotheque[i].titre, bibliotheque[i].auteur, bibliotheque[i].isbn, bibliotheque[i].genre);
        }
    }
}


int main(int argc, char const *argv[])
{
    printf("test");
    return 0;
}

