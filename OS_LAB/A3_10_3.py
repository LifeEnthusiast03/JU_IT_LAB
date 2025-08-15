#!/usr/bin/python3

"""
"" Name - Sougata Saha, Soham Chakraborty
"" Roll - 002311001037, 002311001042
"" Team N0 - 10
"" Date - 12/08/2025
""
"" <Usage>
"" python3 A3_10_3.py <n> <p> <mod> <print_switch>
""
"" <All Command Line Parameter Description>
"" n : Dimension of square matrices (n x n)
"" p : Number of parallel worker processes (1..CPU cores)
"" mod : Modulus for random init; elements in 0..mod-1
"" print_switch : 1 = print matrices; 0 = do not print matrices
""
"" <What this Program Does>
"" Generates two n x n matrices with random unsigned integers,
"" multiplies them in parallel using multiprocessing,
"" measures only the multiplication time (excludes initialization),
"" and prints matrices only when print_switch=1.
""
"" <Sample Input/Output Sets>
"" Input : python3 A3_10_3.py 1000 1 1000 0
"" Output: Generating matrices...
"" Multiplying with 1 processes...
"" Multiplication took 54.8074 seconds
"" Since last value is 0, matrices are not displayed
""
"" Input : python3 A3_10_3.py 1000 2 1000 0
"" Output: Generating matrices...
"" Multiplying with 2 processes...
"" Multiplication took 31.5112 seconds
"" Since last value is 0, matrices are not displayed
""
"" Input : python3 A3_10_3.py 1000 3 1000 0
"" Output: Generating matrices...
"" Multiplying with 3 processes...
"" Multiplication took 20.5132 seconds
"" Since last value is 0, matrices are not displayed
""
"" Input : python3 A3_10_3.py 1000 4 1000 0
"" Output: Generating matrices...
"" Multiplying with 4 processes...
"" Multiplication took 16.0740 seconds
"" Since last value is 0, matrices are not displayed
""
"" Input : python3 A3_10_3.py 1000 5 1000 0
"" Output: Generating matrices...
"" Multiplying with 5 processes...
"" Multiplication took 13.4345 seconds
"" Since last value is 0, matrices are not displayed
""
"" Input : python3 A3_10_3.py 1000 6 1000 0
"" Output: Generating matrices...
"" Multiplying with 6 processes...
"" Multiplication took 11.4005 seconds
"" Since last value is 0, matrices are not displayed
""
"" <Input Details>
"" Command-line arguments:
"" n : Size of the square matrices (creates A and B of size n x n)
"" p : Number of parallel worker processes used for multiplication
"" mod : Modulus for random initialization; values in range 0..mod-1
"" print_switch : 1 = print matrices A, B, C; 0 = do not print matrices
"" Data generated inside the program:
"" Two n x n matrices (A, B) initialized with randint(0, mod-1).
"" Rows of A are split across p processes; result matrix C = A x B.
""
"" <Output Details>
"" When print_switch=0: only timing + message that matrices are not displayed.
"" When print_switch=1: timing + matrices A, B, and C are printed.
""
"" <Time Taken ::: System Details>
"" Dataset: n=1000, mod=1000, print_switch=0
"" Measured Compute Times:
"" p=1 : 54.8074 s
"" p=2 : 31.5112 s
"" p=3 : 20.5132 s
"" p=4 : 16.0740 s
"" p=5 : 13.4345 s
"" p=6 : 11.4005 s
"" CPU Utilization (aggregate across cores during multiply):
"" p=1 ≈ 90% total CPU
"" p=2 ≈ 180% total CPU
"" p=3 ≈ 270% total CPU
"" p=4 ≈ 360% total CPU
"" p=5 ≈ 450% total CPU
"" p=6 ≈ 540% total CPU
""
"" System:
""  <#cores : 6>, <RAM - 16GB>
"""

import sys
import random
import time
from multiprocessing import Pool

def multiply_chunk(args):
    A_chunk, B = args
    n = len(B)
    result_chunk = []
    for row in A_chunk:
        result_row = [sum(row[k] * B[k][j] for k in range(n)) for j in range(n)]
        result_chunk.append(result_row)
    return result_chunk

def split_rows(A, p):
    n = len(A)
    p = max(1, min(p, n))
    base = n // p
    rem = n % p
    chunks = []
    start = 0
    for i in range(p):
        size = base + (1 if i < rem else 0)
        end = start + size
        if size > 0:
            chunks.append(A[start:end])
        start = end
    return chunks

def main():
    if len(sys.argv) != 5:
        print(f"Usage: python {sys.argv[0]} n p mod print_switch")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
        p = int(sys.argv[2])
        mod = int(sys.argv[3])
        print_switch = int(sys.argv[4])
    except ValueError:
        print("All arguments must be integers: n p mod print_switch")
        sys.exit(1)

    if n <= 0 or p <= 0 or mod <= 0 or print_switch not in (0, 1):
        print("Constraints: n>0, p>0, mod>0, print_switch in {0,1}")
        sys.exit(1)

    print("Generating matrices...")
    A = [[random.randint(0, mod - 1) for _ in range(n)] for _ in range(n)]
    B = [[random.randint(0, mod - 1) for _ in range(n)] for _ in range(n)]

    chunks = split_rows(A, p)

    print(f"Multiplying with {p} processes...")
    start_time = time.perf_counter()
    with Pool(processes=len(chunks)) as pool:
        result_chunks = pool.map(multiply_chunk, [(chunk, B) for chunk in chunks])
    end_time = time.perf_counter()

    C = [row for chunk in result_chunks for row in chunk]

    print(f"Multiplication took {end_time - start_time:.4f} seconds")

    if print_switch == 1:
        print("Matrix A:")
        for row in A:
            print(row)
        print("\nMatrix B:")
        for row in B:
            print(row)
        print("\nMatrix C (Result):")
        for row in C:
            print(row)
    else:
        print("Since last value is 0, matrices are not displayed")

if __name__ == "__main__":
    main()

