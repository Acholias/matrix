> English version available here : [README.en.md](README.en.md)

# Matrix — Introduction à l'algèbre linéaire

Implémentation en C17 des concepts fondamentaux de l'algèbre linéaire, dans le cadre du projet **matrix** de l'École 42. Le projet couvre les vecteurs, les matrices, et les opérations mathématiques associées, du plus simple au plus avancé.

---

## Sommaire

- [Structure du projet](#structure-du-projet)
- [Compilation](#compilation)
- [CLI — Interface en ligne de commande](#cli)
- [Structures de base](#structures-de-base)
  - [vector.h / vector.c](#vectorh--vectorc)
  - [matrix.h / matrix.c](#matrixh--matrixc)
- [Exercices](#exercices)
  - [Ex00 — Add, Subtract and Scale](#ex00--add-subtract-and-scale)
  - [Ex01 — Linear Combination](#ex01--linear-combination)
  - [Ex02 — Linear Interpolation](#ex02--linear-interpolation)
  - [Ex03 — Dot Product](#ex03--dot-product)
  - [Ex04 — Norm](#ex04--norm)
  - [Ex05 — Cosine](#ex05--cosine)
  - [Ex06 — Cross Product](#ex06--cross-product)
  - [Ex07 — Linear Map, Matrix Multiplication](#ex07--linear-map-matrix-multiplication)
  - [Ex08 — Trace](#ex08--trace)
  - [Ex09 — Transpose](#ex09--transpose)
  - [Ex10 — Row Echelon Form](#ex10--row-echelon-form)
  - [Ex11 — Determinant](#ex11--determinant)
  - [Ex12 — Inverse](#ex12--inverse)
  - [Ex13 — Rank](#ex13--rank)
- [Utilitaires](#utilitaires)
  - [utils.h / utils.c](#utilsh--utilsc)
  - [display.h / display.c](#displayh--displayc)

---

## Structure du projet

```
matrix/
├── Makefile
├── README.md
├── README.en.md
├── includes/
│   ├── vector.h
│   ├── matrix.h
│   ├── exercises.h
│   ├── display.h
│   ├── cli.h
│   └── utils.h
└── srcs/
    ├── main.c
    ├── vector.c
    ├── matrix.c
    ├── display.c
    ├── cli.c
    ├── utils.c
    └── exercises/
        ├── ex00.c
        ├── ex01.c
        ├── ex02.c
        ├── ex03.c
        ├── ex04.c
        ├── ex05.c
        ├── ex06.c
        ├── ex07.c
        ├── ex08.c
        ├── ex09.c
        ├── ex10.c
        ├── ex11.c
        ├── ex12.c
        └── ex13.c
```

---

## Compilation

```bash
make        # compile le projet
make re     # recompile entièrement
make clean  # supprime les .o
make fclean # supprime les .o et le binaire
make test   # lance tous les tests de la grille de correction
```

---

## CLI

L'interface en ligne de commande permet de lancer n'importe quel exercice avec les matrices de son choix.

```
./matrix <exercice> [matrice1] [matrice2] ... [-s scalaire1,scalaire2,...]
```

### Format des entrées

| Type | Format | Exemple |
|------|--------|---------|
| Vecteur | valeurs séparées par des virgules | `"1,2,3"` |
| Matrice | lignes séparées par `;`, colonnes par `,` | `"1,2;3,4"` |
| Scalaire(s) | flag `-s` suivi de valeurs séparées par `,` | `-s 2` ou `-s 10,-2,0.5` |

### Exemples

```bash
./matrix ex00 "1,2;3,4" "5,6;7,8"          # addition et soustraction
./matrix ex00 "1,2;3,4" "5,6;7,8" -s 2     # avec scaling
./matrix ex03 "1,2,3" "4,5,6"              # dot product
./matrix ex01 "1,0,0" "0,1,0" -s 10,-2    # combinaison linéaire
./matrix ex11 "1,2;3,4"                    # déterminant
```

Sans argument, le programme affiche l'aide.

---

## Structures de base

### `vector.h` / `vector.c`

Un vecteur est une liste ordonnée de nombres. Chaque nombre s'appelle une **composante**.

```
⎡ 2.0 ⎤  ← composante 0
⎢ 3.0 ⎥  ← composante 1
⎣ 5.0 ⎦  ← composante 2
```

```c
typedef struct s_vector
{
    float   *data;   // tableau des composantes
    size_t  size;    // nombre de composantes
}   t_vector;
```

| Fonction | Description |
|----------|-------------|
| `new_vec(size)` | Crée un vecteur vide de taille `size` |
| `from_vec(data, size)` | Crée un vecteur depuis un tableau de floats |
| `free_vec(v)` | Libère la mémoire du vecteur |
| `print_vec(v)` | Affiche le vecteur |
| `mat_to_vec(m)` | Convertit une matrice colonne en vecteur |

---

### `matrix.h` / `matrix.c`

Une matrice est un tableau 2D de nombres organisé en lignes et colonnes. On peut la voir comme une collection de vecteurs empilés.

```
⎡ 1.0  2.0  3.0 ⎤  ← ligne 0
⎢ 4.0  5.0  6.0 ⎥  ← ligne 1
⎣ 7.0  8.0  9.0 ⎦  ← ligne 2
```

Accès à un élément : `data[ligne][colonne]` — ex: `data[1][2] = 6.0`

```c
typedef struct s_matrix
{
    float   **data;  // tableau de lignes
    size_t  rows;    // nombre de lignes
    size_t  cols;    // nombre de colonnes
}   t_matrix;
```

| Fonction | Description |
|----------|-------------|
| `new_mat(rows, cols)` | Crée une matrice vide |
| `from_mat(data, rows, cols)` | Crée une matrice depuis un tableau 2D |
| `free_mat(m)` | Libère la mémoire de la matrice |
| `print_mat(m)` | Affiche la matrice |
| `mat_is_square(m)` | Retourne `true` si la matrice est carrée |
| `shape(m)` | Retourne `(rows, cols)` |

---

## Exercices

### Ex00 — Add, Subtract and Scale

**Complexité : O(n) en temps et en espace**

Trois opérations de base sur vecteurs et matrices. On parcourt chaque élément exactement une fois et on applique l'opération.

**Addition** — additionne deux vecteurs/matrices composante par composante :
```
⎡ 2 ⎤     ⎡ 5 ⎤     ⎡  7 ⎤
⎣ 3 ⎦  +  ⎣ 7 ⎦  =  ⎣ 10 ⎦
```

**Soustraction** — soustrait composante par composante :
```
⎡ 2 ⎤     ⎡ 5 ⎤     ⎡ -3 ⎤
⎣ 3 ⎦  -  ⎣ 7 ⎦  =  ⎣ -4 ⎦
```

**Scaling** — multiplie chaque composante par un scalaire :
```
⎡ 2 ⎤          ⎡ 4 ⎤
⎣ 3 ⎦  * 2 =   ⎣ 6 ⎦
```

---

### Ex01 — Linear Combination

**Complexité : O(n) en temps et en espace**

On prend plusieurs vecteurs, on multiplie chacun par un coefficient et on additionne le tout. Utilise `fmaf(a, b, c) = a * b + c` pour accumuler.

```
result = (coef1 * v1) + (coef2 * v2) + ... + (coefN * vN)
```

**Exemple :**
```
v1 = [1, 0, 0]   coef1 = 10
v2 = [0, 1, 0]   coef2 = -2
v3 = [0, 0, 1]   coef3 =  0.5

result = 10*[1,0,0] + (-2)*[0,1,0] + 0.5*[0,0,1]

⎡  10 ⎤
⎢  -2 ⎥
⎣ 0.5 ⎦
```

---

### Ex02 — Linear Interpolation

**Complexité : O(n) en temps et en espace**

Permet de glisser progressivement entre deux valeurs `u` et `v` grâce à un paramètre `t` compris entre 0 et 1. `t` est un pourcentage du chemin entre `u` et `v`.

```
formule : lerp(u, v, t) = u + t * (v - u)
avec fmaf : fmaf(t, v - u, u)
```

| t | résultat |
|---|---------|
| 0.0 | retourne u |
| 0.5 | retourne le point au milieu |
| 1.0 | retourne v |

**Exemple :**
```
u = [2, 1]    v = [4, 2]    t = 0.3

lerp = [2 + 0.3*(4-2), 1 + 0.3*(2-1)]
     = [2.6, 1.3]
```

Fonctionne sur scalaires, vecteurs et matrices.

---

### Ex03 — Dot Product

**Complexité : O(n) en temps et en espace**

Le produit scalaire prend deux vecteurs et retourne un seul nombre. On multiplie les composantes deux à deux et on additionne le tout avec `fmaf`.

```
u · v = (u[0]*v[0]) + (u[1]*v[1]) + ... + (u[n]*v[n])
```

**Interprétation géométrique :**
```
u · v > 0  →  vecteurs dans le même sens
u · v = 0  →  vecteurs perpendiculaires
u · v < 0  →  vecteurs en sens opposés
```

**Exemple :**
```
⎡ 1 ⎤      ⎡ 4 ⎤
⎢ 2 ⎥  ·  ⎢ 5 ⎥  =  (1*4) + (2*5) + (3*6) = 32
⎣ 3 ⎦      ⎣ 6 ⎦
```

---

### Ex04 — Norm

**Complexité : O(n) en temps et en espace**

Une norme mesure la "longueur" d'un vecteur. Il en existe plusieurs définitions. Le projet implémente les trois principales.

**Norme 1 — Manhattan** : somme des valeurs absolues
```
||v||1 = |v[0]| + |v[1]| + ... + |v[n]|

[1, -2, 3]  →  |1| + |-2| + |3| = 6
```

**Norme 2 — Euclidienne** : distance en ligne droite (Pythagore)
```
||v||2 = sqrt(v[0]² + v[1]² + ... + v[n]²)

[1, -2, 3]  →  sqrt(1 + 4 + 9) = sqrt(14) ≈ 3.742
```

**Norme infinie — Supremum** : la plus grande valeur absolue
```
||v||∞ = max(|v[0]|, |v[1]|, ..., |v[n]|)

[1, -2, 3]  →  max(1, 2, 3) = 3
```

---

### Ex05 — Cosine

**Complexité : O(n) en temps et en espace**

Calcule le cosinus de l'angle entre deux vecteurs. Réutilise le dot product et la norme euclidienne. La fonction `cos` de la librairie standard est interdite.

```
cos(u, v) = (u · v) / (||u|| * ||v||)
```

**Interprétation :**
```
cos = 1   →  vecteurs parallèles, même sens (angle = 0°)
cos = 0   →  vecteurs perpendiculaires (angle = 90°)
cos = -1  →  vecteurs parallèles, sens opposé (angle = 180°)
```

**Exemple :**
```
⎡ 1 ⎤       ⎡ 0 ⎤
⎣ 0 ⎦  cos  ⎣ 1 ⎦  =  0   (perpendiculaires)
```

---

### Ex06 — Cross Product

Le produit vectoriel prend deux vecteurs 3D et retourne un troisième vecteur **perpendiculaire** aux deux premiers. Uniquement défini en 3D.

```
u × v = [ u[1]*v[2] - u[2]*v[1] ]
        [ u[2]*v[0] - u[0]*v[2] ]
        [ u[0]*v[1] - u[1]*v[0] ]
```

**Interprétation :** si `u` et `v` définissent un plan, `u × v` pointe perpendiculairement à ce plan.

**Exemple :**
```
⎡ 1 ⎤      ⎡ 0 ⎤     ⎡ 0 ⎤
⎢ 0 ⎥  ×  ⎢ 1 ⎥  =  ⎢ 0 ⎥
⎣ 0 ⎦      ⎣ 0 ⎦     ⎣ 1 ⎦
```

**Propriété :** `u × v = -(v × u)` — le produit vectoriel est anticommutatif.

---

### Ex07 — Linear Map, Matrix Multiplication

**Complexité : O(nm) pour matrix×vecteur, O(nmp) pour matrix×matrix**

Une matrice représente une transformation linéaire. La multiplier par un vecteur applique cette transformation.

**Matrix × Vecteur** — dot product de chaque ligne avec le vecteur :
```
⎡ 1 1 ⎤      ⎡ 4 ⎤     ⎡ 1*4 + 1*2 ⎤     ⎡ 6 ⎤
⎣ 1 1 ⎦  ×  ⎣ 2 ⎦  =  ⎣ 1*4 + 1*2 ⎦  =  ⎣ 6 ⎦
```

**Matrix × Matrix** — chaque élément `result[i][j]` est le dot product de la ligne `i` de A avec la colonne `j` de B :
```
A (m×n) × B (n×p) = result (m×p)

colonnes de A == lignes de B  (obligatoire)
```

---

### Ex08 — Trace

**Complexité : O(n) en temps**

La trace d'une matrice carrée est la **somme des éléments sur la diagonale principale** — les éléments où `ligne == colonne`.

```
⎡ 1 2 ⎤
⎣ 3 4 ⎦   →   trace = 1 + 4 = 5

⎡ 2  0  0 ⎤
⎢ 0  3  0 ⎥   →   trace = 2 + 3 + 1 = 6
⎣ 0  0  1 ⎦
```

---

### Ex09 — Transpose

**Complexité : O(nm) en temps et en espace**

La transposée échange les lignes et les colonnes. L'élément en position `[i][j]` se retrouve en position `[j][i]`. Une matrice `m×n` devient une matrice `n×m`.

```
⎡ 1 2 3 ⎤ T      ⎡ 1 4 ⎤
⎣ 4 5 6 ⎦    →   ⎢ 2 5 ⎥
                   ⎣ 3 6 ⎦
```

---

### Ex10 — Row Echelon Form

**Complexité : O(n³) en temps, O(n²) en espace**

La forme échelonnée réduite transforme une matrice pour obtenir un "escalier" de 1 sur la diagonale et 0 partout ailleurs. Algorithme : **élimination de Gauss-Jordan**.

```
Départ :          Résultat :
⎡ 1 2 ⎤          ⎡ 1 0 ⎤
⎣ 3 4 ⎦    →     ⎣ 0 1 ⎦

⎡ 4 2 ⎤          ⎡ 1 0.5 ⎤
⎣ 2 1 ⎦    →     ⎣ 0 0   ⎦
```

**Étapes de l'algorithme :**
1. Trouver le pivot (valeur absolue max dans la colonne)
2. Échanger avec la ligne courante (swap)
3. Normaliser la ligne pivot (diviser par le pivot → pivot = 1)
4. Éliminer la colonne dans toutes les autres lignes

Sert de base pour l'ex11 (déterminant), ex12 (inverse) et ex13 (rang).

---

### Ex11 — Determinant

**Complexité : O(n³) en temps**

Le déterminant est un scalaire qui caractérise une matrice carrée. Il représente le **facteur de changement de volume** après la transformation linéaire.

```
det = 0   →  la matrice écrase l'espace → pas inversible
det ≠ 0   →  la matrice est inversible
det = 1   →  la transformation conserve les volumes
det < 0   →  la transformation inverse l'orientation
```

On utilise l'élimination de Gauss et on accumule les pivots. Chaque swap de lignes inverse le signe.

```
⎡ 1 2 ⎤
⎣ 3 4 ⎦   →   det = (1*4) - (2*3) = -2

⎡ 2 0 ⎤
⎣ 0 2 ⎦   →   det = 2 * 2 = 4
```

---

### Ex12 — Inverse

**Complexité : O(n³) en temps, O(n²) en espace**

L'inverse de A est la matrice A⁻¹ telle que `A * A⁻¹ = I`. Équivalent de `1/x` pour les matrices. N'existe que si `det(A) ≠ 0`.

**Méthode — matrice augmentée :**
On colle la matrice identité à droite de A, puis on applique Gauss-Jordan. Quand la partie gauche devient l'identité, la partie droite est l'inverse.

```
[ A | I ]  →  Gauss-Jordan  →  [ I | A⁻¹ ]

⎡ 1 2 | 1 0 ⎤       ⎡ 1 0 | -2    1  ⎤
⎣ 3 4 | 0 1 ⎦  →    ⎣ 0 1 | 1.5  -0.5 ⎦
```

---

### Ex13 — Rank

**Complexité : O(n³) en temps**

Le rang d'une matrice est le **nombre de lignes non nulles** dans sa forme échelonnée. C'est aussi la dimension de l'espace image de la transformation.

```
⎡ 1 0 ⎤              ⎡ 1 1 ⎤
⎣ 0 1 ⎦  →  rang 2   ⎣ 1 1 ⎦  →  rang 1

⎡ 0 0 ⎤
⎣ 0 0 ⎦  →  rang 0
```

On applique l'élimination de Gauss et on compte les lignes non nulles dans le résultat.

---

## Utilitaires

### `utils.h` / `utils.c`

Fonctions mathématiques réimplémentées sans `math.h` (sauf `fmaf` qui est autorisé par le sujet) :

| Fonction | Description |
|----------|-------------|
| `ft_abs(x)` | Valeur absolue d'un float |
| `ft_sqrt(x)` | Racine carrée (méthode de Newton-Raphson) |
| `ft_pow(x, n)` | Puissance entière |
| `exercise_header(label, name)` | Affiche le header d'un exercice |

Constantes de couleur pour le terminal : `RESET`, `BOLD`, `RED`, `GREEN`, `YELLOW`, `GREY`.

---

### `display.h` / `display.c`

Fonctions d'affichage mathématique avec les crochets `⎡ ⎢ ⎣` pour un rendu propre.

| Fonction | Description |
|----------|-------------|
| `display_vec(v)` | Affiche un vecteur |
| `display_mat(m)` | Affiche une matrice |
| `display_vec_result(op, u, v, result)` | Affiche `u op v = result` pour des vecteurs |
| `display_mat_result(op, u, v, result)` | Affiche `u op v = result` pour des matrices |
| `display_mat_scl(u, scalar, result)` | Affiche `u * scalar = result` |
| `display_scalar_result(op, u, v, result)` | Affiche `u op v = float` |
| `display_vec_label(label, v)` | Affiche un vecteur avec un label aligné |
