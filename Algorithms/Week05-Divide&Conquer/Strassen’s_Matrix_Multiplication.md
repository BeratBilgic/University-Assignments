# Matrix multiplication: Strassen’s algorithm
<br />

```math
$$
\left(\begin{array}{cc} 
A11 & A12\\
A21 & A22
\end{array}\right)
X
\left(\begin{array}{cc} 
B11 & B12\\
B21 & B22
\end{array}\right)
=
\left(\begin{array}{cc} 
C11 & C12\\
C21 & C22
\end{array}\right)
$$
```

<br />

M1 = (A11 + A22)(B11 + B22) <br />
M2 = (A21 + A22)B11 <br />
M3 = A11(B12 − B22) <br />
M4 = A22(B21 − B11) <br />
M5 = (A11 + A12)B22 <br />
M6 = (A21 − A11)(B11 + B12) <br />
M7 = (A12 − A22)(B21 + B22) <br />

C11 = M1 + M4 − M5 + M7 <br />
C12 = M3 + M5 <br />
C21 = M2 + M4 <br />
C22 = M1 − M2 + M3 + M6 <br />

```math
$$
\left(\begin{array}{cc} 
C11 & C12\\
C21 & C22
\end{array}\right)
=
\left(\begin{array}{cc} 
M1 + M4 -M5 + M7 & M3 + M5\\
M2 + M4 & M1 - M2 + M3 + M6
\end{array}\right)
$$
```

<br />

### Standard Matrix Multiplication
W(n) = 8W(n/2) + O(n<sup>2</sup>) <br />
W(n) = O(n<sup>log<sub>2</sub><sup>8</sup></sup>) = O(n<sup>3</sup>) <br /> 
### Strassen’s Algorithm
W(n) = 7W(n/2) + O(n<sup>2</sup>) <br />
W(n) = O(n<sup>log<sub>2</sub><sup>7</sup></sup>) = O(n<sup>2.81...</sup>) <br />
