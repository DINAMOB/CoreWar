## ▶️ Utilisation

```bash
./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name] ...
```

## 📖 Description des options

- `-dump nbr_cycle` : Affiche la mémoire après `nbr_cycle` cycles d’exécution (sauf si la partie est déjà terminée).
  La mémoire est affichée en hexadécimal, avec **32 octets par ligne** (ex. : `A0BCDEFE1DD3...`).

- `-n prog_number` : Définit le **numéro du prochain programme** (champion).
  Par défaut, le numéro libre suivant est attribué selon l’ordre des paramètres.

- `-a load_address` : Définit **l’adresse de chargement** du programme suivant.
  Si aucune adresse n’est spécifiée, les adresses sont **optimisées automatiquement** pour espacer les processus autant que possible.
  Les adresses sont calculées en modulo de `MEM_SIZE`.


# Corewar

Corewar est un projet de première année à **Epitech**, réalisé dans le cadre de l'apprentissage de la programmation bas niveau en langage C.
Le projet a été développé en **4 semaines**, en **binôme** (groupe de 2 personnes).

## 🖥️ Environnement

- Développé sous **Ubuntu**
- Utilisation du compilateur **gcc**
- Projet basé sur une architecture Unix

## ⚙️ Compilation

Le projet utilise un **Makefile** avec les règles suivantes :

- `make` : Compile le projet
- `make clean` : Supprime les fichiers objets
- `make fclean` : Supprime tous les fichiers générés (objets + exécutable)

## 📦 Dépendances

Certaines dépendances peuvent être nécessaires pour compiler ou tester le projet correctement (par exemple : `criterion` pour les tests, ou d'autres bibliothèques selon les besoins).
👉 Une documentation sur l'installation de ces dépendances pourra être ajoutée ultérieurement.

## 🚧 Limitations

Le projet peut être difficile à tester ou à exécuter correctement sans une configuration identique à celle utilisée lors du développement, notamment à cause de l’absence de conteneurisation ou de script d’installation automatisé.

## 👨‍💻 Auteurs

- Antonie MOREL (contact: antonie.morel@epitech.eu)
- brandon-jean-samuel BEGUE (contact: brandon-jean-samuel.begue@epitech.eu)
