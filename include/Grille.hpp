#ifndef GRILLE_HPP
#define GRILLE_HPP

#include "Vehicule.hpp"
#include <vector>
#include <string>
#include <map>
#include <SFML/Graphics.hpp>

class Grille {
private:
    std::vector<std::vector<char>> grille;
    std::vector<Vehicule> vehicules;
    std::map<char, sf::Color> colorMap;
    int sortieX, sortieY;
    char sortieOrientation;

    void mettreAJourGrille();

public:
    Grille();
    bool chargerPlateauDepuisJson(const std::string& chemin);
    bool deplacerVehicule(char id, const std::string& direction);
    bool gagne() const;
    const std::vector<Vehicule>& getVehicules() const;
    const std::map<char, sf::Color>& getColorMap() const;
    std::string getHash() const;
};

#endif
