# APPS microBench
A micro benchmark for Automatic Parallelization of Parallel Skeletons

Parallel skeletons supported:
* Map
* Reduce
* Scan
* Stencil

This micro benchmarks evaluates the capabilities of the automatic parallelization mechanism
for handling different skeleton constructions, such as:
* most basic construction
* scalar operations
* vector (array) operations
* aliasing
* indirect array accesses
