> Version anglaise disponible ici : [README.EN.md](README.EN.md)

# Matrix — Structures de base

Ce projet est une introduction à l'algèbre linéaire implémentée en Rust.
Tous les exercices reposent sur deux fichiers qui définissent les types fondamentaux utilisés dans tout le projet : `vector.rs` et `matrix.rs`.

---

## vector.rs

### Qu'est-ce qu'un vecteur ?

Un vecteur est une liste ordonnée de nombres. Chaque nombre s'appelle une **composante**.

```
[2.0]   <- composante 0
[3.0]   <- composante 1
[5.0]   <- composante 2
```

En espace 2D ou 3D, un vecteur peut représenter un point, une direction ou une magnitude.
Dans ce projet, un vecteur est simplement une enveloppe autour d'un tableau dynamique de valeurs d'un type générique `K`.

### Structure

```rust
pub struct Vector<K> {
    pub data: Vec<K>,
}
```

`K` est un type générique. Cela signifie que le vecteur fonctionne avec n'importe quel type numérique : `f32`, `f64`, ou un type nombre complexe personnalisé plus tard dans les exercices bonus.
`data` est un `Vec<K>`, qui est le tableau dynamique de Rust.

### Méthodes

```rust
impl<K: Clone> Vector<K> {
    pub fn from(data: &[K]) -> Self
    pub fn size(&self) -> usize
}
```

| Méthode | Description |
|---------|-------------|
| `from(data)` | Crée un Vector depuis une slice de valeurs |
| `size()` | Retourne le nombre de composantes |

**Exemple :**

```rust
let v = Vector::from(&[1.0_f32, 2.0, 3.0]);
println!("{}", v.size()); // 3
```

### Affichage

```rust
impl<K: fmt::Display> fmt::Display for Vector<K>
```

Implémenter le trait `Display` permet d'utiliser `println!("{}", v)` sur un Vector.
Chaque composante est affichée sur sa propre ligne entre crochets.

```rust
let v = Vector::from(&[1.0_f32, 2.0, 3.0]);
println!("{}", v);
// [1]
// [2]
// [3]
```

> La syntaxe `impl Trait for Type` signifie : "ce type respecte maintenant ce contrat".
> `Display` exige d'implémenter une seule méthode `fmt()`, et en échange, `println!("{}", ...)` fonctionne automatiquement.

---

## matrix.rs

### Qu'est-ce qu'une matrice ?

Une matrice est un tableau 2D de nombres, organisé en lignes et colonnes.

```
[ 1.0,  2.0,  3.0 ]  <- ligne 0
[ 4.0,  5.0,  6.0 ]  <- ligne 1
[ 7.0,  8.0,  9.0 ]  <- ligne 2
```

C'est une matrice 3x3 : 3 lignes, 3 colonnes.
On peut la voir comme une collection de vecteurs empilés les uns sur les autres.

Pour accéder à un élément : `data[ligne][colonne]`

```
data[1][2] = 6.0
```

### Structure

```rust
pub struct Matrix<K> {
    pub data: Vec<Vec<K>>,
}
```

`data` est un `Vec<Vec<K>>` : un tableau dynamique de lignes, où chaque ligne est elle-même un tableau dynamique de valeurs.
Comme pour `Vector`, le type `K` est générique.

### Méthodes

```rust
impl<K: Clone> Matrix<K> {
    pub fn from(data: &[Vec<K>]) -> Self
    pub fn shape(&self) -> (usize, usize)
    pub fn is_square(&self) -> bool
}
```

| Méthode | Description |
|---------|-------------|
| `from(data)` | Crée une Matrix depuis une slice de lignes |
| `shape()` | Retourne `(nb_lignes, nb_colonnes)` |
| `is_square()` | Retourne `true` si la matrice a autant de lignes que de colonnes |

**Exemple :**

```rust
let m = Matrix::from(&[
    vec![1.0_f32, 2.0, 3.0],
    vec![4.0,     5.0, 6.0],
]);

println!("{:?}", m.shape());     // (2, 3)
println!("{}",   m.is_square()); // false
```

### Affichage

```rust
impl<K: fmt::Display> fmt::Display for Matrix<K>
```

Chaque ligne est affichée sur sa propre ligne, avec les éléments séparés par des virgules.

```rust
let m = Matrix::from(&[
    vec![1.0_f32, 2.0],
    vec![3.0,     4.0],
]);
println!("{}", m);
// [1, 2]
// [3, 4]
```

---

## Pourquoi deux fichiers séparés ?

`vector.rs` définit ce qu'est une liste simple de nombres.
`matrix.rs` s'appuie sur ce concept pour définir un tableau de nombres.

Chaque exercice du projet ajoute de nouvelles opérations mathématiques par-dessus ces deux structures.
Aucun des deux fichiers ne contient de maths — ils sont purement structurels.

```
vector.rs  →  définit Vector<K>
matrix.rs  →  définit Matrix<K>
exercises/ →  ajoute les opérations mathématiques sur Vector et Matrix
main.rs    →  exécute chaque exercice
```

---

## Le type générique K

Les deux structures utilisent un type générique `K` plutôt qu'un type concret comme `f32`.
Cela signifie que le même code fonctionne pour différents types numériques sans être réécrit.

```rust
// Fonctionne avec f32
let v = Vector::from(&[1.0_f32, 2.0]);

// Fonctionne avec f64
let v = Vector::from(&[1.0_f64, 2.0]);
```

Les exercices n'exigent que du `f32` (flottant 32 bits), mais l'exercice bonus (ex15) réutilise
les mêmes structures avec des nombres complexes, ce qui explique pourquoi les génériques sont
utilisés dès le départ.
