> French version available here : [README.md](README.md)

# Matrix — Base structures

This project is an introduction to linear algebra implemented in Rust.
All exercises rely on two core files that define the fundamental types used throughout the project: `vector.rs` and `matrix.rs`.

---

## vector.rs

### What is a Vector?

A vector is an ordered list of numbers. Each number is called a **component**.

```
[2.0]   <- component 0
[3.0]   <- component 1
[5.0]   <- component 2
```

In 2D or 3D space, a vector can represent a point, a direction, or a magnitude.
In this project, a vector is simply a wrapper around a dynamic array of values of a generic type `K`.

### Structure

```rust
pub struct Vector<K> {
    pub data: Vec<K>,
}
```

`K` is a generic type. It means the vector works with any numeric type: `f32`, `f64`, or a custom complex number type later in the bonus exercises.
`data` is a `Vec<K>`, which is Rust's dynamic array.

### Methods

```rust
impl<K: Clone> Vector<K> {
    pub fn from(data: &[K]) -> Self
    pub fn size(&self) -> usize
}
```

| Method | Description |
|--------|-------------|
| `from(data)` | Creates a Vector from a slice of values |
| `size()` | Returns the number of components |

**Example:**

```rust
let v = Vector::from(&[1.0_f32, 2.0, 3.0]);
println!("{}", v.size()); // 3
```

### Display

```rust
impl<K: fmt::Display> fmt::Display for Vector<K>
```

Implementing the `Display` trait allows using `println!("{}", v)` on a Vector.
Each component is printed on its own line between brackets.

```rust
let v = Vector::from(&[1.0_f32, 2.0, 3.0]);
println!("{}", v);
// [1]
// [2]
// [3]
```

> The `impl Trait for Type` syntax means: "this type now respects this contract".
> `Display` requires implementing a single method `fmt()`, and in exchange, `println!("{}", ...)` works automatically.

---

## matrix.rs

### What is a Matrix?

A matrix is a 2D table of numbers, organized in rows and columns.

```
[ 1.0,  2.0,  3.0 ]  <- row 0
[ 4.0,  5.0,  6.0 ]  <- row 1
[ 7.0,  8.0,  9.0 ]  <- row 2
```

This is a 3x3 matrix: 3 rows, 3 columns.
It can be seen as a collection of vectors stacked on top of each other.

To access an element: `data[row][col]`

```
data[1][2] = 6.0
```

### Structure

```rust
pub struct Matrix<K> {
    pub data: Vec<Vec<K>>,
}
```

`data` is a `Vec<Vec<K>>`: a dynamic array of rows, where each row is itself a dynamic array of values.
Just like `Vector`, the type `K` is generic.

### Methods

```rust
impl<K: Clone> Matrix<K> {
    pub fn from(data: &[Vec<K>]) -> Self
    pub fn shape(&self) -> (usize, usize)
    pub fn is_square(&self) -> bool
}
```

| Method | Description |
|--------|-------------|
| `from(data)` | Creates a Matrix from a slice of rows |
| `shape()` | Returns `(nb_rows, nb_cols)` |
| `is_square()` | Returns `true` if the matrix has the same number of rows and columns |

**Example:**

```rust
let m = Matrix::from(&[
    vec![1.0_f32, 2.0, 3.0],
    vec![4.0,     5.0, 6.0],
]);

println!("{:?}", m.shape());    // (2, 3)
println!("{}",   m.is_square()); // false
```

### Display

```rust
impl<K: fmt::Display> fmt::Display for Matrix<K>
```

Each row is printed on its own line, with elements separated by commas.

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

## Why two separate files?

`vector.rs` defines what a single list of numbers is.
`matrix.rs` builds on top of that concept to define a table of numbers.

Every exercise in this project adds new mathematical operations on top of these two structures.
Neither file contains any math — they are purely structural.

```
vector.rs  →  defines Vector<K>
matrix.rs  →  defines Matrix<K>
exercises/ →  adds mathematical operations on Vector and Matrix
main.rs    →  runs each exercise
```

---

## Generic type K

Both structures use a generic type `K` instead of a concrete type like `f32`.
This means the same code works for different numeric types without being rewritten.

```rust
// Works with f32
let v = Vector::from(&[1.0_f32, 2.0]);

// Works with f64
let v = Vector::from(&[1.0_f64, 2.0]);
```

The exercises only require `f32` (32-bit float), but the bonus exercise (ex15) reuses
the same structures with complex numbers, which is why generics are used from the start.
