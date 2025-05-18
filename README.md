
# 🚗 Rush Hour – Jeu de réflexion en C++/SFML

Ce projet est une version moderne du célèbre jeu de logique **Rush Hour**, développée en **C++ avec SFML**. Il propose une interface graphique immersive, une gestion dynamique des niveaux au format JSON, et un rendu coloré avec **sprites personnalisés**.

---

## 📦 Fonctionnalités

- 🧠 **Mode manuel** : déplacez les véhicules pour libérer la voiture rouge (`X`) et la faire sortir.
- 🤖 **Résolution automatique (IA)** : l'algorithme résout le niveau s’il existe une solution.
- 🎨 **Affichage graphique** : chaque véhicule est dessiné selon sa **couleur RVB**.
- 🧩 **Plateaux personnalisables** : éditez ou créez vos niveaux en JSON.
- 🕹️ **Contrôles claviers + souris** clairs et intuitifs.

---

## 🔗 Dépôt GitHub

> 📥 Clonez le projet :  
```bash
git clone https://github.com/nirminee/RushHourGame.git
cd RushHourGame
```

---

## 🖥️ Dépendances

- [SFML 2.5+](https://www.sfml-dev.org/)
- [nlohmann/json](https://github.com/nlohmann/json) (inclus dans `include/json.hpp`)
- CMake (recommandé)

---

## 🚀 Installation & Compilation

1. **Préparation**  
   Placez vos assets :
   - `assets/car.png` → sprite des véhicules
   - `assets/OpenSans-Regular.ttf` → police

2. **Compilation**  
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. **Exécution**
   ```bash
   ./RushHour
   ```

---

## 🎮 Commandes

- **Menu principal**
  - `1` → Jouer manuellement
  - `2` → Lancer la résolution automatique (IA)

- **Contrôles en jeu**
  - Sélection : taper la lettre d’un véhicule (`A` à `X`)
  - Déplacement : touches fléchées

---

## 📝 Format JSON d’un plateau

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
    }
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

## 🎨 Représentation des couleurs utilisées

| Lettre | Couleur RVB            | Exemple visuel              | Signification                         |
|--------|------------------------|------------------------------|----------------------------------------|
| X      | `rvb(255, 0, 0)`       | ![#FF0000](https://via.placeholder.com/15/FF0000/000000?text=+) Rouge        | Voiture à libérer                      |
| A      | `rvb(0, 255, 0)`       | ![#00FF00](https://via.placeholder.com/15/00FF00/000000?text=+) Vert         | Voiture classique                      |
| B      | `rvb(0, 0, 255)`       | ![#0000FF](https://via.placeholder.com/15/0000FF/000000?text=+) Bleu         | Voiture classique                      |
| C      | `rvb(255, 128, 0)`     | ![#FF8000](https://via.placeholder.com/15/FF8000/000000?text=+) Orange       | Camion / véhicule                      |
| D      | `rvb(255, 105, 180)`   | ![#FF69B4](https://via.placeholder.com/15/FF69B4/000000?text=+) Rose vif     | Camion ou autre                        |
| E      | `rvb(157, 113, 83)`    | ![#9D7153](https://via.placeholder.com/15/9D7153/000000?text=+) Marron clair  | Voiture                                |
| F      | `rvb(238, 130, 238)`   | ![#EE82EE](https://via.placeholder.com/15/EE82EE/000000?text=+) Violet clair  | Voiture                                |
| G      | `rvb(43, 255, 255)`    | ![#2BFFFF](https://via.placeholder.com/15/2BFFFF/000000?text=+) Cyan clair    | Voiture                                |
| H      | `rvb(255, 0, 255)`     | ![#FF00FF](https://via.placeholder.com/15/FF00FF/000000?text=+) Magenta       | Voiture                                |

> ℹ️ Les couleurs sont définies dans les fichiers JSON et utilisées pour afficher les sprites.

---

## 🛠️ Organisation du projet

```
RushHourGame/
├── assets/       # Images & polices
├── include/      # Fichiers .hpp (dont json.hpp)
├── plateaux/     # Fichiers de niveaux JSON
├── src/          # Fichiers sources C++
├── build/        # Dossier de compilation (vide au début)
├── CMakeLists.txt
└── README.md
```

---

## 💡 Conseils

- Pour ajouter un niveau, copiez un fichier JSON et changez les véhicules.
- Pour tester un niveau avec l’IA, utilisez l’option `2` du menu.
- Vous pouvez facilement adapter les couleurs et tailles des véhicules dans les fichiers JSON.

---

## 📧 Contact

Une question ou un bug ?  
👉 Ouvrez une [issue sur GitHub](https://github.com/nirminee/RushHourGame/issues) ou contactez le développeur.

---

**🧩 Amuse-toi bien avec Rush Hour !**  
**🚗 Bonne chance pour libérer la voiture rouge !**
