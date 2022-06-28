# MiniShell_2

[![forthebadge](http://forthebadge.com/images/badges/built-with-love.svg)](https://github.com/Gaetandrt)  [![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://fr.wikipedia.org/wiki/C_(langage))  [![linkedin-](https://user-images.githubusercontent.com/91087072/175767199-5ecadc72-20a2-42dc-a24f-3a601bba5ddb.svg)](https://www.linkedin.com/in/gaetan-darrort/)

Reproduction d'un shell fonctionnel Partie finale.

## Qu'est qu'un shell ?

Un shell Unix est un interpréteur de commandes destiné aux systèmes d'exploitation Unix et de type Unix qui permet d'accéder aux fonctionnalités internes du système d'exploitation. Il se présente sous la forme d'une interface en ligne de commande accessible depuis la console ou un terminal. L'utilisateur lance des commandes sous forme d'une entrée texte exécutée ensuite par le shell.

## Minishell by Epitech Part II

Le but de ce projet est d'améliorer le Minishell 2, en lui rajoutant certaines fonctionnalités :
    - Gérer les parenthèses "()", "*", "?", "[]"
    - Gérer les && et les ||
    - Conserver les commandes précèdement exécutées dans un historique
    - Créé un système d'auto-complétion pour les commandes
    - Créer les fonctions where, repeat, if, which, foreach, alias

### Compétences travaillées

- Renforcement des listes chainnées
- Architecture
- Algorithme d'auto-complétion

### Installation

Pour compiler ce projet, il vous suffit de vous rendre a la racine et de lancer la commande :

    `make`

Cette commande va vous générez un binaire qu'il suffira ensuite de lancer grace a la commande :
    `./mysh`

## Utilisation

Prenant pour exemple TCSH, le 42sh s'utilise de la même manière.

Pour executer une commande, il suffit de la taper dans la console du 42sh, comme ceci :

[![minishell1](https://user-images.githubusercontent.com/91087072/175777049-fb0833cb-6c2a-4756-94a7-b057bcdcac18.png)](https://user-images.githubusercontent.com/91087072/175777049-fb0833cb-6c2a-4756-94a7-b057bcdcac18.png)


Pour quitter, vous pouvez utiliser la commande exit, ou CTRL+D.

## Fabriqué avec

* [Visual Studio Code](https://code.visualstudio.com/) - Environnement de développement
* [C](https://fr.wikipedia.org/wiki/C_(langage)) - Langage de programmation
