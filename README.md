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
* false-positive

The benchmark consists of several functions, each one concerning one of the parallel skeletons
where a few obstacles or complex characteristics are incorporated in the skeleton implementation.

## Some challenges related to automatic compiler parallelization

Automatic compiler parallelization is difficult due to
numerous challenges, such as
analyzing pointer aliasing,
control flow, irregular array accesses, and dynamic loop
limits as well as handling inter-procedural analysis
complicate static dependence analysis.
These difficulties introduce imprecision into dependence
relations, limit the accuracy of parallelism estimates, and
force conservative synchronization to safely handle
potential dependencies [allen01][chen03].

Traditional techniques can not be used to parallelize loops with indirect
array accesses.
Govindarajan and Anantpur present a dynamic solution for identifying
loops with cross iteration dependencies due to indirect memory accesses.
The most common use of indirect array access
is A[B[i]] where i is the loop index. Since the contents of
array B are not known at compile time, the compiler can
not make any assumptions about the accesses to array A and
hence conservatively computes the data dependences on array A [govindarajan13].


### References

[chen03] M.K. Chen and K. Olukotun. The jrpm system for dynamically parallelizing java
programs. In Computer Architecture, 2003. Proceedings. 30th Annual International
Symposium on, pages 434–445, June 2003.

[allen01] Allen, R and Kennedy, K. Optimizing Compilers for Modern
Architectures: A Dependence-based Approach.
Morgan Kaufmann Publishers, San Francisco, CA, 2001.

[govindarajan13] R. Govindarajan and Jayvant Anantpur. Runtime dependence computation and
execution of loops on heterogeneous systems. In Proceedings of the 2013 IEEE/ACM
International Symposium on Code Generation and Optimization (CGO), CGO ’13,
pages 1–10, Washington, DC, USA, 2013. IEEE Computer Society.


