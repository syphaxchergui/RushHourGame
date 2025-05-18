Bien sûr ! Voici un exemple de **README.md** professionnel pour ton projet Rush Hour en C++ avec SFML, gestion des couleurs RVB et affichage par sprites.

---

# 🚗 Rush Hour – Jeu de réflexion en C++/SFML

Ce projet est une version moderne du célèbre jeu de logique **Rush Hour**, développée en C++ avec la bibliothèque graphique **SFML**. Il propose une interface graphique colorée, la gestion de plateaux personnalisés au format JSON, et l’affichage des véhicules sous forme de sprites colorés.

---

## 📦 Fonctionnalités

- **Jeu manuel** : déplacez les véhicules pour libérer la voiture rouge (X) et la faire sortir de la grille.
- **Résolution automatique (IA)** : l’algorithme trouve la solution optimale si elle existe.
- **Affichage graphique** : chaque véhicule est représenté par un sprite coloré selon sa couleur RVB définie dans le plateau JSON.
- **Plateaux personnalisables** : créez vos propres niveaux facilement en éditant des fichiers JSON.
- **Interface claire et intuitive** (clavier + souris).

---

## 🖥️ Dépendances

- [SFML 2.5+](https://www.sfml-dev.org/)
- [nlohmann/json](https://github.com/nlohmann/json) (inclus dans `include/json.hpp`)
- CMake (recommandé) ou Makefile

---

## 🚀 Installation & Compilation

1. **Clonez le dépôt**  
   ```bash
   git clone 
   cd RUSH
   ```

2. **Placez vos assets**  
   - Placez une image de voiture nommée `car.png` dans le dossier `assets/`
   - Placez la police `OpenSans-Regular.ttf` dans `assets/`

3. **Compilation**  
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

4. **Lancement**  
   ```bash
   ./RushHour
   ```

---

## 🎮 Utilisation

- **Menu principal** :  
  `1` = Jouer manuellement  
  `2` = Résolution automatique (IA)

- **Contrôles en mode manuel** :
  - Sélectionner un véhicule : appuyez sur sa lettre (`A`, `B`, ..., `X`)
  - Déplacer : flèches directionnelles
  - Objectif : amener la voiture rouge (X) à la sortie (bord droit de la grille)

- **Plateaux** :  
  Les fichiers JSON des plateaux sont dans le dossier `plateaux/`.  
  Vous pouvez les éditer ou en créer de nouveaux.

---

## 📝 Format d’un plateau JSON

```json
{
  "nom": "plateau facile 1",
  "largeur": 6,
  "hauteur": 6,
  "voitures": [
    {
      "id": "A",
      "couleur": "rvb(0, 255, 0)",
      "x": 2,
      "y": 1,
      "taille": 3,
      "orientation": "verticale"
    },
    // ... autres véhicules
  ],
  "voiture_dep": {
    "id": "X",
    "couleur": "rvb(255, 0, 0)",
    "x": 3,
    "y": 3,
    "taille": 2,
    "orientation": "horizontale"
  },
  "sortie": {
    "x": 6,
    "y": 3
  }
}
```

---

## 🎨 Guide des couleurs

| Lettre | Couleur RVB         | Signification         |
|--------|---------------------|----------------------|
| X      | rvb(255, 0, 0)      | Voiture rouge (à sortir) |
| A      | rvb(0, 255, 0)      | Vert                 |
| B      | rvb(0, 0, 255)      | Bleu                 |
| C      | rvb(255, 128, 0)    | Orange               |
| ...    | ...                 | ...                  |

---

## 💡 Astuces

- Pour ajouter un nouveau plateau, copiez un fichier JSON existant et modifiez les positions, tailles, couleurs, etc.
- Pour changer l’apparence des voitures, remplacez `car.png` par une autre image (format PNG recommandé).
- Pour tester un plateau en IA, choisissez l’option 2 au lancement.

---

## 🛠️ Développement

- **Structure du projet** :
  - `src/` : sources C++
  - `include/` : headers et json.hpp
  - `assets/` : images et polices
  - `plateaux/` : niveaux JSON
  - `.vscode/` : config VS Code (optionnel)
  - `build/` : dossier de compilation

---

## 📧 Contact

Pour toute question, suggestion ou bug, contactez l’auteur du projet ou ouvrez une issue sur le dépôt Git.

---

**Bon jeu et amuse-toi bien avec Rush Hour ! 🚗🧩**

---
Réponse de Perplexity: pplx.ai/share