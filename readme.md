# Pollard RSA Cracker

Accelerated RSA cracking using Pollard's p-1 algorithm implemented in C

## Why does this work?

https://en.wikipedia.org/wiki/Pollard%27s_p_%E2%88%92_1_algorithm

Pollard's p-1 algorithm is an integer factorization algorithm, that is used to find prime factors of a number.
The algorithm is based on the fact that if a number n is a prime number, then n-1 is a composite number.

It works if the key was generated with small primes

## Performance

> Test CPU: Ryzen 7 2700X

- The __Python__ version _did not_ terminate after __1 hour__ of running
- The __C/C++__ version _completed_ in about __17 minutes__
