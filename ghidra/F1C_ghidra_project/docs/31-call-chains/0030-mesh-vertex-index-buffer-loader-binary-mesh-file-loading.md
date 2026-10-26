# Chain: Mesh Vertex/Index Buffer Loader — Binary Mesh File Loading

Seed: FUN_00550ad0  |  System: docs/20-math-utilities.md  |  Depth: 3  |  Functions: 11

---

## Overview

Reads mesh vertex and index data from binary files. Two modes: indexed (vertices + indices, stride 0x2c per vertex) and non-indexed (vertex batches, stride 0xc per batch). Uses temp read buffers DAT_008b8f30/8b8f34. Decompresses if needed (FUN_0059b260). Post-processes via FUN_00589901. Allocates structs for mesh storage.

## Call Tree

```
FUN_00550ad0 — Mesh Vertex/Index Buffer Loader  [called from resource loading]
  +-- FUN_0058ace6 — File Size Query Wrapper  [docs/08: file size via stream lock]
  |     +-- FUN_0058c1b1 — Stream Buffer Lock via Critical Section
  |     +-- FUN_0058ad08 — File Size Query (128 bytes)
  +-- FUN_00587f64 — String Format Wrapper  [docs/08: file seek positioning]
  |     +-- FUN_0058c1b1 — Stream Buffer Lock via Critical Section
  |     +-- FUN_00587f90 — File Tell/Seek Position Query
  +-- FUN_0058803f — Thread-Safe Read Wrapper  [docs/20: file read with lock]
  |     +-- FUN_0058c1b1 — Stream Buffer Lock via Critical Section
  |     +-- FUN_0058806e — File Read (232 bytes)
  +-- FUN_0059b260 — [undocumented: decompress?]
  +-- FUN_0054a5c0 — Global Buffer Copy with Advance  [docs/20: stream read]
  +-- FUN_00589901 — Post-Processing  [docs/20]
  +-- FUN_00587bcf — Free Wrapper  [docs/01: thunk to FUN_0058aa6f]
  |     +-- FUN_0058aa6f — Heap Deallocation  [docs/20]
  +-- FUN_005507e0 — Struct Init with Vtable Zero  [docs/01]
  |     +-- FUN_0053c2a0 — Global Zero Init
  +-- FUN_005507a0 — 8-Dword Struct Initializer  [docs/20]
  |     +-- FUN_0053b490 — Identity Function
  +-- FUN_005593b0 — Struct Zero-Init  [docs/20]
  |     +-- FUN_0053c2a0 — Global Zero Init
  +-- FUN_00550800 — Dual Field Zero-Init  [docs/01]
```

## Step-by-Step Trace

### Level 0: FUN_00550ad0 — Mesh Vertex/Index Buffer Loader

**Trigger:** Resource loading path — mesh file needs to be loaded from disk
**Called by:** No callers in call_graph.json (likely called via vtable dispatch)
**Purpose:** Reads mesh vertex and index data from binary file, allocates buffer structures.

**Key actions:**
1. Reads file size via FUN_0058ace6, seeks via FUN_00587f64
2. Reads file data via FUN_0058803f into temp buffers (DAT_008b8f30/8b8f34)
3. If indexed mode (bit 0): allocates stride 0x2c per vertex, stores at param_1[4]; 0x20-byte sub-buffers per vertex at param_1[4]+0x28
4. If non-indexed (bit 1): allocates stride 0xc per batch, each batch has sub-arrays of 0x24-byte elements
5. Computes vertex positions: stride * (DAT_0059e43c / param_1[1])
6. Calls decompress (FUN_0059b260) and post-process (FUN_00589901)
7. Allocates struct init wrappers for mesh storage

### Level 1-2: File I/O Sub-chain

**FUN_0058ace6 — File Size Query Wrapper** [docs/08-file-formats.md]
- Locks stream buffer via critical section (FUN_0058c1b1)
- Queries file size via FUN_0058ad08
- Unlocks and returns

**FUN_00587f64 — String Format Wrapper** [docs/08-file-formats.md]
- Locks stream buffer (FUN_0058c1b1)
- Seeks to position via FUN_00587f90

**FUN_0058803f — Thread-Safe Read Wrapper** [docs/20-math-utilities.md]
- Locks stream buffer (FUN_0058c1b1)
- Reads data via FUN_0058806e (232-byte read routine)

### Level 1: Struct Initializers

All struct init wrappers are leaf or near-leaf zero-init operations:
- FUN_005507e0 (vtable zero, calls FUN_0053c2a0)
- FUN_005507a0 (8 dwords, calls FUN_0053b490 identity)
- FUN_005593b0 (zero-init, calls FUN_0053c2a0)
- FUN_00550800 (dual field zero-init)

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| DAT_008b8f30/8b8f34 | file bytes | buffer read | raw mesh data |
| FUN_0059b260 | raw data | decompress | decompressed mesh |
| FUN_0054a5c0 | decompressed data | stream copy with advance | structured vertex data |
| FUN_005507e0 | mesh struct | zero-init vtable | initialized mesh object |

## Notes

- FUN_0059b260 is undocumented — likely a deflate/LZ decompression routine
- FUN_00589901 is a post-processing step (vertex transform or normal computation)
- FUN_0058c1b1 (critical section lock) appears in 3 different callees — shared I/O locking primitive

---
