> Version française disponible ici : [README.md](README.md)

# Matrix — Introduction to Linear Algebra

A C17 implementation of the fundamental concepts of linear algebra, as part of the **matrix** project at École 42. The project covers vectors, matrices, and associated mathematical operations, from basic to advanced.

---

## Table of Contents

- [Project Structure](#project-structure)
- [Compilation](#compilation)
- [CLI — Command Line Interface](#cli)
- [Base Structures](#base-structures)
  - [vector.h / vector.c](#vectorh--vectorc)
  - [matrix.h / matrix.c](#matrixh--matrixc)
- [Exercises](#exercises)
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
- [Utilities](#utilities)
  - [utils.h / utils.c](#utilsh--utilsc)
  - [display.h / display.c](#displayh--displayc)

---

## Project Structure

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
make        # compile the project
make re     # full recompilation
make clean  # removes .o files
make fclean # removes .o files and binary
make test   # runs all correction grid tests
```

---

## CLI

The command line interface lets you run any exercise with the matrices of your choice.

```
./matrix <exercise> [matrix1] [matrix2] ... [-s scalar1,scalar2,...]
```

### Input Format

| Type | Format | Example |
|------|--------|---------|
| Vector | comma-separated values | `"1,2,3"` |
| Matrix | rows separated by `;`, columns by `,` | `"1,2;3,4"` |
| Scalar(s) | `-s` flag followed by comma-separated values | `-s 2` or `-s 10,-2,0.5` |

### Examples

```bash
./matrix ex00 "1,2;3,4" "5,6;7,8"          # addition and subtraction
./matrix ex00 "1,2;3,4" "5,6;7,8" -s 2     # with scaling
./matrix ex03 "1,2,3" "4,5,6"              # dot product
./matrix ex01 "1,0,0" "0,1,0" -s 10,-2    # linear combination
./matrix ex11 "1,2;3,4"                    # determinant
```

With no arguments, the program displays the help.

---

## Base Structures

### `vector.h` / `vector.c`

A vector is an ordered list of numbers. Each number is called a **component**.

```
⎡ 2.0 ⎤  ← component 0
⎢ 3.0 ⎥  ← component 1
⎣ 5.0 ⎦  ← component 2
```

```c
typedef struct s_vector
{
    float   *data;   // component array
    size_t  size;    // number of components
}   t_vector;
```

| Function | Description |
|----------|-------------|
| `new_vec(size)` | Creates an empty vector of size `size` |
| `from_vec(data, size)` | Creates a vector from a float array |
| `free_vec(v)` | Frees the vector's memory |
| `print_vec(v)` | Displays the vector |
| `mat_to_vec(m)` | Converts a column matrix to a vector |

---

### `matrix.h` / `matrix.c`

A matrix is a 2D array of numbers organized in rows and columns. It can be seen as a collection of stacked vectors.

```
⎡ 1.0  2.0  3.0 ⎤  ← row 0
⎢ 4.0  5.0  6.0 ⎥  ← row 1
⎣ 7.0  8.0  9.0 ⎦  ← row 2
```

Element access: `data[row][col]` — ex: `data[1][2] = 6.0`

```c
typedef struct s_matrix
{
    float   **data;  // row array
    size_t  rows;    // number of rows
    size_t  cols;    // number of columns
}   t_matrix;
```

| Function | Description |
|----------|-------------|
| `new_mat(rows, cols)` | Creates an empty matrix |
| `from_mat(data, rows, cols)` | Creates a matrix from a 2D array |
| `free_mat(m)` | Frees the matrix's memory |
| `print_mat(m)` | Displays the matrix |
| `mat_is_square(m)` | Returns `true` if the matrix is square |
| `shape(m)` | Returns `(rows, cols)` |

---

## Exercises

### Ex00 — Add, Subtract and Scale

**Complexity: O(n) in time and space**

Three basic operations on vectors and matrices. Each element is visited exactly once.

**Addition** — adds two vectors/matrices component by component:
```
⎡ 2 ⎤     ⎡ 5 ⎤     ⎡  7 ⎤
⎣ 3 ⎦  +  ⎣ 7 ⎦  =  ⎣ 10 ⎦
```

**Subtraction** — subtracts component by component:
```
⎡ 2 ⎤     ⎡ 5 ⎤     ⎡ -3 ⎤
⎣ 3 ⎦  -  ⎣ 7 ⎦  =  ⎣ -4 ⎦
```

**Scaling** — multiplies each component by a scalar:
```
⎡ 2 ⎤          ⎡ 4 ⎤
⎣ 3 ⎦  * 2 =   ⎣ 6 ⎦
```

---

### Ex01 — Linear Combination

**Complexity: O(n) in time and space**

Takes several vectors, multiplies each by a coefficient, and sums the result. Uses `fmaf(a, b, c) = a * b + c` to accumulate.

```
result = (coef1 * v1) + (coef2 * v2) + ... + (coefN * vN)
```

**Example:**
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

**Complexity: O(n) in time and space**

Slides progressively between two values `u` and `v` using a parameter `t` between 0 and 1. `t` is a percentage of the path from `u` to `v`.

```
formula: lerp(u, v, t) = u + t * (v - u)
with fmaf: fmaf(t, v - u, u)
```

| t | result |
|---|--------|
| 0.0 | returns u |
| 0.5 | returns the midpoint |
| 1.0 | returns v |

**Example:**
```
u = [2, 1]    v = [4, 2]    t = 0.3

lerp = [2 + 0.3*(4-2), 1 + 0.3*(2-1)]
     = [2.6, 1.3]
```

Works on scalars, vectors, and matrices.

---

### Ex03 — Dot Product

**Complexity: O(n) in time and space**

The dot product takes two vectors and returns a single number. Multiplies components pairwise and sums using `fmaf`.

```
u · v = (u[0]*v[0]) + (u[1]*v[1]) + ... + (u[n]*v[n])
```

**Geometric interpretation:**
```
u · v > 0  →  vectors point in the same direction
u · v = 0  →  vectors are perpendicular
u · v < 0  →  vectors point in opposite directions
```

**Example:**
```
⎡ 1 ⎤      ⎡ 4 ⎤
⎢ 2 ⎥  ·  ⎢ 5 ⎥  =  (1*4) + (2*5) + (3*6) = 32
⎣ 3 ⎦      ⎣ 6 ⎦
```

---

### Ex04 — Norm

**Complexity: O(n) in time and space**

A norm measures the "length" of a vector. Three norms are implemented.

**Norm 1 — Manhattan**: sum of absolute values
```
||v||1 = |v[0]| + |v[1]| + ... + |v[n]|

[1, -2, 3]  →  |1| + |-2| + |3| = 6
```

**Norm 2 — Euclidean**: straight-line distance (Pythagoras)
```
||v||2 = sqrt(v[0]² + v[1]² + ... + v[n]²)

[1, -2, 3]  →  sqrt(1 + 4 + 9) = sqrt(14) ≈ 3.742
```

**Infinity norm — Supremum**: largest absolute value
```
||v||∞ = max(|v[0]|, |v[1]|, ..., |v[n]|)

[1, -2, 3]  →  max(1, 2, 3) = 3
```

---

### Ex05 — Cosine

**Complexity: O(n) in time and space**

Computes the cosine of the angle between two vectors. Reuses dot product and Euclidean norm. The standard `cos` function is forbidden.

```
cos(u, v) = (u · v) / (||u|| * ||v||)
```

**Interpretation:**
```
cos = 1   →  parallel vectors, same direction (angle = 0°)
cos = 0   →  perpendicular vectors (angle = 90°)
cos = -1  →  parallel vectors, opposite direction (angle = 180°)
```

**Example:**
```
⎡ 1 ⎤       ⎡ 0 ⎤
⎣ 0 ⎦  cos  ⎣ 1 ⎦  =  0   (perpendicular)
```

---

### Ex06 — Cross Product

The cross product takes two 3D vectors and returns a third vector **perpendicular** to both. Only defined in 3D.

```
u × v = [ u[1]*v[2] - u[2]*v[1] ]
        [ u[2]*v[0] - u[0]*v[2] ]
        [ u[0]*v[1] - u[1]*v[0] ]
```

**Interpretation:** if `u` and `v` define a plane, `u × v` points perpendicularly to that plane.

**Example:**
```
⎡ 1 ⎤      ⎡ 0 ⎤     ⎡ 0 ⎤
⎢ 0 ⎥  ×  ⎢ 1 ⎥  =  ⎢ 0 ⎥
⎣ 0 ⎦      ⎣ 0 ⎦     ⎣ 1 ⎦
```

**Property:** `u × v = -(v × u)` — the cross product is anticommutative.

---

### Ex07 — Linear Map, Matrix Multiplication

**Complexity: O(nm) for matrix×vector, O(nmp) for matrix×matrix**

A matrix represents a linear transformation. Multiplying it by a vector applies that transformation.

**Matrix × Vector** — dot product of each row with the vector:
```
⎡ 1 1 ⎤      ⎡ 4 ⎤     ⎡ 1*4 + 1*2 ⎤     ⎡ 6 ⎤
⎣ 1 1 ⎦  ×  ⎣ 2 ⎦  =  ⎣ 1*4 + 1*2 ⎦  =  ⎣ 6 ⎦
```

**Matrix × Matrix** — each element `result[i][j]` is the dot product of row `i` of A with column `j` of B:
```
A (m×n) × B (n×p) = result (m×p)

columns of A == rows of B  (required)
```

---

### Ex08 — Trace

**Complexity: O(n) in time**

The trace of a square matrix is the **sum of elements on the main diagonal** — elements where `row == column`.

```
⎡ 1 2 ⎤
⎣ 3 4 ⎦   →   trace = 1 + 4 = 5

⎡ 2  0  0 ⎤
⎢ 0  3  0 ⎥   →   trace = 2 + 3 + 1 = 6
⎣ 0  0  1 ⎦
```

---

### Ex09 — Transpose

**Complexity: O(nm) in time and space**

The transpose swaps rows and columns. The element at position `[i][j]` moves to `[j][i]`. An `m×n` matrix becomes an `n×m` matrix.

```
⎡ 1 2 3 ⎤ T      ⎡ 1 4 ⎤
⎣ 4 5 6 ⎦    →   ⎢ 2 5 ⎥
                   ⎣ 3 6 ⎦
```

---

### Ex10 — Row Echelon Form

**Complexity: O(n³) in time, O(n²) in space**

The reduced row echelon form transforms a matrix to get a "staircase" of 1s on the diagonal and 0s everywhere else. Algorithm: **Gauss-Jordan elimination**.

```
Input:            Output:
⎡ 1 2 ⎤          ⎡ 1 0 ⎤
⎣ 3 4 ⎦    →     ⎣ 0 1 ⎦

⎡ 4 2 ⎤          ⎡ 1 0.5 ⎤
⎣ 2 1 ⎦    →     ⎣ 0 0   ⎦
```

**Algorithm steps:**
1. Find the pivot (max absolute value in the column)
2. Swap with the current row
3. Normalize the pivot row (divide by pivot → pivot = 1)
4. Eliminate the column in all other rows

Forms the basis for ex11 (determinant), ex12 (inverse), and ex13 (rank).

---

### Ex11 — Determinant

**Complexity: O(n³) in time**

The determinant is a scalar that characterizes a square matrix. It represents the **volume scaling factor** after the linear transformation.

```
det = 0   →  the matrix collapses the space → not invertible
det ≠ 0   →  the matrix is invertible
det = 1   →  the transformation preserves volumes
det < 0   →  the transformation reverses orientation
```

Uses Gauss elimination and accumulates pivots. Each row swap flips the sign.

```
⎡ 1 2 ⎤
⎣ 3 4 ⎦   →   det = (1*4) - (2*3) = -2

⎡ 2 0 ⎤
⎣ 0 2 ⎦   →   det = 2 * 2 = 4
```

---

### Ex12 — Inverse

**Complexity: O(n³) in time, O(n²) in space**

The inverse of A is the matrix A⁻¹ such that `A * A⁻¹ = I`. The matrix equivalent of `1/x`. Only exists if `det(A) ≠ 0`.

**Method — augmented matrix:**
Append the identity matrix to the right of A, then apply Gauss-Jordan. When the left part becomes the identity, the right part is the inverse.

```
[ A | I ]  →  Gauss-Jordan  →  [ I | A⁻¹ ]

⎡ 1 2 | 1 0 ⎤       ⎡ 1 0 | -2    1  ⎤
⎣ 3 4 | 0 1 ⎦  →    ⎣ 0 1 | 1.5  -0.5 ⎦
```

---

### Ex13 — Rank

**Complexity: O(n³) in time**

The rank of a matrix is the **number of non-zero rows** in its row echelon form. It is also the dimension of the image space of the transformation.

```
⎡ 1 0 ⎤              ⎡ 1 1 ⎤
⎣ 0 1 ⎦  →  rank 2   ⎣ 1 1 ⎦  →  rank 1

⎡ 0 0 ⎤
⎣ 0 0 ⎦  →  rank 0
```

Applies Gauss elimination and counts non-zero rows in the result.

---

## Utilities

### `utils.h` / `utils.c`

Mathematical functions reimplemented without `math.h` (except `fmaf` which is explicitly allowed by the subject):

| Function | Description |
|----------|-------------|
| `ft_abs(x)` | Absolute value of a float |
| `ft_sqrt(x)` | Square root (Newton-Raphson method) |
| `ft_pow(x, n)` | Integer power |
| `exercise_header(label, name)` | Displays the exercise header |

Terminal color constants: `RESET`, `BOLD`, `RED`, `GREEN`, `YELLOW`, `GREY`.

---

### `display.h` / `display.c`

Mathematical display functions using `⎡ ⎢ ⎣` brackets for a clean render.

| Function | Description |
|----------|-------------|
| `display_vec(v)` | Displays a vector |
| `display_mat(m)` | Displays a matrix |
| `display_vec_result(op, u, v, result)` | Displays `u op v = result` for vectors |
| `display_mat_result(op, u, v, result)` | Displays `u op v = result` for matrices |
| `display_mat_scl(u, scalar, result)` | Displays `u * scalar = result` |
| `display_scalar_result(op, u, v, result)` | Displays `u op v = float` |
| `display_vec_label(label, v)` | Displays a vector with an aligned label |
