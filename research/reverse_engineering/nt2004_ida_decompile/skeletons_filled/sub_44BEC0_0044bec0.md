## sub_44BEC0_0044bec0 — HATPolyGaussianElimination

**Summary:** Solves a polynomial fitting problem using Gaussian elimination on a 6x6 (or fallback 3x3) linear system. Extracts polynomial coefficients for HAT (Height Above Terrain) surface approximation from input vertex data.

**Called by:** sub_44C310 (0044c310), IndexedVertexLookupFromStream [structural] (0044c3a0), sub_44D480 (0044d480), BezierPatchTessellation [structural] (0044d7b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | Polynomial coefficient C0 (constant term / X) |
| this | 0x4 | RW | 0 | Polynomial coefficient C1 |
| this | 0x8 | RW | 0 | Polynomial coefficient C2 |
| this | 0xC | RW | 0 | Polynomial coefficient C3 |
| this | 0x10 | RW | 0 | Polynomial coefficient C4 |
| this | 0x14 | RW | 0 | Polynomial coefficient C5 |
| this | 0x18 | RW | — | Polynomial coefficient C6 |
| this | 0x1C | RW | — | Polynomial coefficient C7 |
| this | 0x20 | RW | — | Polynomial coefficient C8 |
| this | 0x24 | RW | — | Polynomial coefficient C9 |
| this | 0x28 | RW | — | Polynomial coefficient C10 |
| this | 0x2C | RW | — | Polynomial coefficient C11 |
| this | 0x30 | RW | — | Polynomial coefficient C12 |
| this | 0x34 | RW | — | Polynomial coefficient C13 |
| this | 0x38 | RW | — | Polynomial coefficient C14 |
| this | 0x3C | RW | — | Polynomial coefficient C15 |
| this | 0x40 | RW | — | Polynomial coefficient C16 |
| this | 0x44 | RW | — | Polynomial coefficient C17 |
| this | 0x48 | RW | — | Polynomial coefficient C18 |
| this | 0x4C | RW | — | Polynomial coefficient C19 |
| this | 0x50 | RW | — | Polynomial coefficient C20 |
| this | 0x54 | RW | — | Polynomial coefficient C21 |
| this | 0x58 | RW | — | Polynomial coefficient C22 |
| this | 0xB4 | R | — | Input vertex index/pointer for 3D lookup |

**Written-by note (persistence):**
- this 0x0: written once during solve — external poke survives until next solve call
- this 0x4: written once during solve — external poke survives
- this 0x8: written once during solve — external poke survives
- this 0xC: written once during solve — external poke survives
- this 0x10: written once during solve — external poke survives
- this 0x14: written once during solve — external poke survives
- this 0x18: written once during solve — external poke survives
- this 0x1C: written once during solve — external poke survives
- this 0x20: written once during solve — external poke survives
- this 0x24: written once during solve — external poke survives
- this 0x28: written once during solve — external poke survives
- this 0x2C: written once during solve — external poke survives
- this 0x30: written once during solve — external poke survives
- this 0x34: written once during solve — external poke survives
- this 0x38: written once during solve — external poke survives
- this 0x3C: written once during solve — external poke survives
- this 0x40: written once during solve — external poke survives
- this 0x44: written once during solve — external poke survives
- this 0x48: written once during solve — external poke survives
- this 0x4C: written once during solve — external poke survives
- this 0x50: written once during solve — external poke survives
- this 0x54: written once during solve — external poke survives
- this 0x58: written once during solve — external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d5b98 | dbl_5D5B98 | R | Double constant (π) for angle normalization |
| 005d5e20 | dbl_5D5E20 | R | Double constant (2π) for angle normalization |
| 005fe4f0 | aGaussianElimin_0 | R | Error string "Gaussian elimination for HAT poly failed twice" |
| 005fe520 | aGaussianElimin | R | Error string "Gaussian elimination for HAT poly failed once" |
| 005fe550 | aDDevNascar2004_0 | R | Source file path "D:\\dev\\NASCAR_2004\\Source\\htree.cpp" |
| 007d73d0 | dword_7D73D0 | R | Unknown global (possibly sub result pointer) |
| 007d7920 | unk_7D7920 | R | Logging/error output channel |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f63d0 | IndexedArrayAccess [structural] | Looks up a vertex from index stream (via word at a2+26) |
| 00500f90 | sub_500F90 | Debug/logging level check |
| 00500fe0 | sub_500FE0 | Debug/logging output (prints Gaussian elimination failure) |
| 00579f40 | sub_579F40 | Performs Gaussian elimination on the assembled linear system matrix |

**Guard conditions:** After initial 6x6 solve via `sub_579F40(v64, 6)`: if it fails AND logging enabled, prints "failed once". Then extracts coefficients from result array into `this[0..11]`. Post-extraction: validates the fit by testing 3 input points — if any point has residual > 0.001, the fit is rejected. On rejection: rebuilds a smaller 3x3 system with additional data and calls `sub_579F40(v64, 3)`. If that also fails, prints "failed twice" and returns -1 (BLOCKED/ERROR). If 3-point validation passes, returns 0 (PASSES). If `a3` (third parameter) is true, adjusts coefficient at `this+0x28` (this[10]) by subtracting a value from the indexed vertex.

**String literals referenced (deterministic):**

- `Gaussian elimination for HAT poly failed twice`
- `Gaussian elimination for HAT poly failed once`
- `D:\dev\NASCAR_2004\Source\htree.cpp`
- `D:\dev\NASCAR_2004\Source\htree.cpp`
