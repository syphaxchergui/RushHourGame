#include "Grille.hpp"
#include <fstream>
#include <sstream>
#include "json.hpp"

using json = nlohmann::json;

Grille::Grille() : grille(6, std::vector<char>(6, '.')) {}

bool Grille::chargerPlateauDepuisJson(const std::string& chemin) {
    std::ifstream fichier(chemin);
    if (!fichier) return false;

    json donnees;
    fichier >> donnees;

    vehicules.clear();
    colorMap.clear();

    // Voiture départ (X)
    auto& vd = donnees["voiture_dep"];
    vehicules.emplace_back(
        vd["id"].get<std::string>()[0],
        vd["x"].get<int>() - 1,
        vd["y"].get<int>() - 1,
        vd["taille"].get<int>(),
        (vd["orientation"].get<std::string>() == "verticale") ? 'v' : 'h'
    );
    std::string couleur = vd["couleur"].get<std::string>();
    int r, g, b;
    sscanf(couleur.c_str(), "rvb(%d, %d, %d)", &r, &g, &b);
    colorMap[vd["id"].get<std::string>()[0]] = sf::Color(r, g, b);

    // Autres voitures
    for (const auto& v : donnees["voitures"]) {
        vehicules.emplace_back(
            v["id"].get<std::string>()[0],
            v["x"].get<int>() - 1,
            v["y"].get<int>() - 1,
            v["taille"].get<int>(),
            (v["orientation"].get<std::string>() == "verticale") ? 'v' : 'h'
        );
        std::string c = v["couleur"].get<std::string>();
        sscanf(c.c_str(), "rvb(%d, %d, %d)", &r, &g, &b);
        colorMap[v["id"].get<std::string>()[0]] = sf::Color(r, g, b);
    }

    // Sortie
    sortieX = donnees["sortie"]["x"].get<int>() - 1;
    sortieY = donnees["sortie"]["y"].get<int>() - 1;
    sortieOrientation = 'r';

    mettreAJourGrille();
    return true;
}

void Grille::mettreAJourGrille() {
    grille.assign(6, std::vector<char>(6, '.'));
    for (const auto& v : vehicules) {
        for (int i = 0; i < v.getLongueur(); ++i) {
            int xi = v.isHorizontal() ? v.getX() + i : v.getX();
            int yi = v.isHorizontal() ? v.getY() : v.getY() + i;
            if (xi < 6 && yi < 6) {
                grille[yi][xi] = v.getId();
            }
        }
    }
}

bool Grille::deplacerVehicule(char id, const std::string& direction) {
    for (auto& v : vehicules) {
        if (v.getId() != id) continue;

        int dx = 0, dy = 0;
        if (direction == "gauche" && v.isHorizontal()) dx = -1;
        else if (direction == "droite" && v.isHorizontal()) dx = 1;
        else if (direction == "haut" && !v.isHorizontal()) dy = -1;
        else if (direction == "bas" && !v.isHorizontal()) dy = 1;
        else return false;

        for (int i = 0; i < v.getLongueur(); ++i) {
            int nx = v.getX() + (v.isHorizontal() ? i : 0) + dx;
            int ny = v.getY() + (v.isHorizontal() ? 0 : i) + dy;

            if (nx < 0 || nx >= 6 || ny < 0 || ny >= 6) return false;
            if (grille[ny][nx] != '.' && grille[ny][nx] != v.getId()) return false;
        }

        v.setX(v.getX() + dx);
        v.setY(v.getY() + dy);
        mettreAJourGrille();
        return true;
    }
    return false;
}

bool Grille::gagne() const {
    for (const auto& v : vehicules) {
        if (v.getId() == 'X') {
            // Vérifie l'orientation de la sortie (à droite)
            if (sortieOrientation != 'r') return false;

            // La voiture X doit être horizontale pour sortir
            if (!v.isHorizontal()) return false;

            // Position finale de la voiture X
            int finX = v.getX() + v.getLongueur() - 1;
            int finY = v.getY();

            // La sortie est toujours sur le bord droit (x=5 en 0-based)
            return (finX == 5) && (finY == sortieY);
        }
    }
    return false;
}



const std::vector<Vehicule>& Grille::getVehicules() const {
    return vehicules;
}

const std::map<char, sf::Color>& Grille::getColorMap() const {
    return colorMap;
}

std::string Grille::getHash() const {
    std::stringstream ss;
    for (const auto& v : vehicules) {
        ss << v.getId() << v.getX() << v.getY();
    }
    return ss.str();
}
