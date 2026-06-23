# so_long

Projet 42 : créer un petit jeu 2D avec **MiniLibX** où le joueur doit récupérer tous les collectibles avant d'atteindre la sortie.

## Objectif du projet

Le programme charge une carte au format `.ber`, vérifie sa validité, affiche le niveau dans une fenêtre, puis permet de déplacer le joueur.

Le but est de :
- ramasser tous les `C` (collectibles),
- atteindre la sortie `E`,
- éviter les murs `1`.

Le nombre de mouvements est affiché dans le terminal à chaque déplacement.

## Règles de la map

Une map valide :
- est **rectangulaire**,
- est **fermée par des murs** (`1`),
- contient uniquement les caractères `0`, `1`, `C`, `E`, `P`,
- contient exactement :
  - `1` joueur (`P`)
  - `1` sortie (`E`)
  - au moins `1` collectible (`C`)
- possède un chemin valide permettant de collecter tous les `C` puis d'atteindre `E`.

### Légende

- `0` : case vide
- `1` : mur
- `C` : collectible
- `E` : sortie
- `P` : position de départ du joueur

## Contrôles

- `W` : haut
- `A` : gauche
- `S` : bas
- `D` : droite
- `ESC` : quitter proprement le jeu

## Compilation

```bash
make
```

Le Makefile contient les cibles :
- `all`
- `clean`
- `fclean`
- `re`

## Exécution

```bash
./so_long map/map1.ber
```

Le programme attend exactement **un argument** : le chemin vers une map `.ber`.

## Structure du dépôt

- `src/` : logique du jeu, parsing, vérifications, déplacements
- `include/` : headers
- `libft/` : bibliothèque personnelle (libft + ft_printf + get_next_line)
- `map/` : exemples de maps `.ber`
- `picture/` : textures `.xpm`

## Fonctions autorisées (sujet)

- `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`
- fonctions de la bibliothèque math (`-lm`)
- fonctions MiniLibX
- `gettimeofday()`
- `ft_printf` (ou équivalent codé)

## Gestion d'erreurs

En cas de map invalide ou d'erreur d'initialisation, le programme quitte proprement avec un message explicite.
