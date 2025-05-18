#ifndef GRILLE_HPP
#define GRILLE_HPP

#include <vector>
#include <string>
#include "Vehicule.hpp"

class Grille {
private:
    static const int largeur = 6;
    static const int hauteur = 6;
    char cases[hauteur][largeur];
    std::vector<Vehicule> vehicules;

public:
    Grille();
    bool chargerPlateauDepuisJson(const std::string& chemin);
    void afficher() const;
    void mettreAJourGrille();
      char getCase(int x, int y) const;
};

#endif
