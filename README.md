# Classical Cryptography Algorithms in C

This repository contains C implementations of 13 classical cryptography algorithms (Crypto CIA Assignment).

## Algorithms

1. **Caesar Cipher** – Basic substitution cipher that shifts characters by a fixed key.  
2. **Atbash Cipher** – Reverses the alphabet (A ↔ Z, B ↔ Y, etc.).  
3. **August Cipher** – Similar to Caesar with a fixed offset (usually +1).  
4. **Affine Cipher** – Uses linear transformation for encryption (`E(x) = (ax + b) mod 26`).  
5. **Vigenère Cipher** – Polyalphabetic cipher using a keyword.  
6. **Gronsfeld Cipher** – Variant of Vigenère using digits instead of letters for the key.  
7. **Beaufort Cipher** – Similar to Vigenère but with reversed operations.  
8. **Autoclave / Running Key Cipher** – Extends the key with the plaintext itself.  
9. **N-gram Operation** – Splits text into n-length blocks (e.g., bigrams, trigrams).  
10. **Hill Cipher** – Uses matrix multiplication for encryption (mod 26).  
11. **Rail Fence Cipher** – Transposition cipher using zig-zag writing across rails.  
12. **Route Cipher** – Places plaintext in a matrix and reads it by column/route.  
13. **Myszkowski Cipher** – Transposition cipher with repeated key letters.

