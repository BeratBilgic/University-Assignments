# Matrix Chain Multiplication

Matrix Chain Multiplication is an algorithm that is applied to determine the lowest cost way for multiplying matrices. The actual multiplication is done using the standard way of multiplying the matrices.

Matrix chain multiplication algorithm is only applied to find the minimum cost way to multiply a sequence of matrices. Therefore, the input taken by the algorithm is the sequence of matrices while the output achieved is the lowest cost parenthesization.

## Pseudocode
```
MATRIX-CHAIN-MULTIPLICATION(p)
   n = p.length ─ 1
   let m[1…n, 1…n] and s[1…n ─ 1, 2…n] be new matrices
   for i = 1 to n
      m[i, i] = 0
   for l = 2 to n // l is the chain length
      for i = 1 to n - l + 1
         j = i + l - 1
         m[i, j] = ∞
         for k = i to j - 1
            q = m[i, k] + m[k + 1, j] + pi-1pkpj
            if q < m[i, j]
               m[i, j] = q
               s[i, j] = k
return m and s
```