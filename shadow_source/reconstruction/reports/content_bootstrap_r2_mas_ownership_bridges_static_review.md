# MAS ownership bridges static review

Scope: `0x00494FE0` and `0x00495010`, isolated into separate one-function packets with promoted root-load and single-node-removal dependencies. Six of six independent candidates validated. This review is static only.

## Checked-load adapter `0x00494FE0`

The wrapper calls the promoted root with `(output, filename_value)`, returns its result unchanged, and clears `*output` only when that result is nonzero. Candidate prose incorrectly described nonzero as success in places; the promoted root contract establishes `-2/-1` failure and zero success/no-op paths, while the raw branch itself establishes only the mechanical nonzero test. The reconciled record therefore avoids inverted semantic labels.

The wrapper does not initialize the slot before the root call and does not clear it after a zero return. Its sole caller `0x004979F0` declares the corresponding local without visible initialization. This reproduces the same zero-without-output hazard as the scene mark wrapper, but here the stale value is transferred into a bitmap/path-registry object. The proposed replacement policy must convert zero-without-object into failure at this consuming boundary.

## Shutdown-release bridge `0x00495010`

This function is a pure one-argument forwarding wrapper around promoted single-node removal `0x0053CE40`. The deterministic IR lists a global not visible in the raw body; it is not promoted as a direct wrapper global because all mutable list effects belong to the dependency. Caller `0x004963D0` uses the bridge while walking retained bitmap/path-registry records during resource-manager shutdown, then clears the stored archive pointer.

Candidate differences were kind labels, integer/pointer spelling, synthetic offset-zero layouts, redundant prose, and whether to attach a lifecycle label. None changed recovered control flow. Concrete types, thread confinement, and ABI remain unresolved.
