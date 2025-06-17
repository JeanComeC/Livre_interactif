# Livre Interactif

## Concept
**Livre Interactif** est un projet de fin d'année CIR1 qui implémente une version numérique d'un livre de type "choose your own adventure" des années 80. Le joueur incarne un aventurier dans le village maudit de Grinheim, en quête du *Collier aux Sept Pierres* pour briser une malédiction. Le jeu propose une aventure textuelle où les choix du joueur influencent l'histoire, avec des mécaniques de gestion de points de vie (PV) et d'inventaire limité à trois objets. Les décisions mènent à différents chapitres, avec des combats, des objets à collecter, et des conditions basées sur les possessions ou l'état du joueur.

Le contenu du jeu est défini dans le fichier `src/book.txt`, qui contient les chapitres, descriptions, choix, et conditions. Le programme, écrit en C, parse ce fichier pour construire une structure de données dynamique (`BigTableau`) et permet une interaction textuelle via la console.

## Structure des Fichiers
Le projet est organisé comme suit :

- **src/** : Répertoire contenant les fichiers source et les données du jeu.
  - **book.txt** : Fichier texte définissant l'histoire, avec des balises `<chapter>`, `<p>`, `<choice>`, `<option>`, et `<if>` pour structurer les chapitres, descriptions, choix, objets, et conditions.
  - **main.c** : Point d'entrée du programme, responsable de l'initialisation, du parsing de `book.txt` via `remplissage_BigTableau`, et de la boucle principale du jeu.
  - **import.c** : Contient les fonctions de parsing pour extraire les chapitres, choix, et objets de `book.txt` (par exemple, `recuperationChoice`).
  - **algo.c** : Gère les structures de données dynamiques (`BigTableau`, `Chapter`, `ChoicesArray`) et les algorithmes de manipulation (par exemple, `add_choiceArray`).
  - **render.c** : Gère l'affichage des chapitres et choix (via `afficherchoices`) et l'interaction avec le joueur (via `choisir_choix`).
  - **algo.h**, **import.h** : En-têtes définissant les structures (`Chapter`, `Choice`, `ChoicesArray`, `BigTableau`) et les prototypes des fonctions.

- **Makefile** : Simplifie la compilation du projet.
- **README.markdown** : Ce fichier, décrivant le projet, sa structure, et les instructions d'exécution.

## Prérequis
- Un compilateur C (ex. : `gcc`).
- Un système compatible POSIX (Linux, macOS, ou Windows avec WSL/MinGW).
- La bibliothèque standard C et ncurses.

## Instructions pour Lancer le Jeu
1. **Cloner le dépôt** :
   ```bash
   git clone https://github.com/JeanComeC/Livre_interactif.git
   cd Livre_interactif
   ```

2. **Compiler le programme** :
   Avec le `Makefile` :
   ```bash
   make
   ```

3. **Lancer le jeu** :
   Exécutez le binaire généré, en s'assurant que `src/book.txt` est présent :
   ```bash
   ./livre_interactif.exe
   ```

4. **Jouer** :
   - Le jeu affiche le texte d'un chapitre et les choix disponibles.
   - Entrez le numéro du choix pour avancer dans l'histoire.
   - Les points de vie et l'inventaire sont gérés automatiquement en fonction des événements (combats, objets collectés, conditions).

## Notes
- Assurez-vous que `src/book.txt` est correctement formaté, avec des balises `<choice>`, `<option>`, et `<if>` conformes au parsing attendu.
- Si vous n'avez pas installé la bibliothèque ncurses, installez-la, avant de compiler le programme, avec la commande :
```bash
sudo apt-get install libncurses5-dev libncursesw5-dev
```
- Le jeu se termine lorsque le joueur atteint le chapitre final ( *La Delivrance de Grinheim*) ou perd tous ses points de vie.