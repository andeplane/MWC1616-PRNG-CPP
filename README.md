MWC1616-PRNG-CPP
================

Super-Fast MWC1616 Pseudo-Random Number Generator	for Intel/AMD Processors (using SSE or SSE4 instruction set)

Should be compiled with Intel compiler and optimization flags
-xCORE-AVX-I -O3 -ipo 
for example: icpc -xCORE-AVX-I -O3 -ipo -g -o main example.cpp random.cpp