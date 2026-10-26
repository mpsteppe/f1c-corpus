## CombinatorialPermutationGenerator_0051e1ef — CombinatorialPermutationGenerator

**Summary:** Generates combinatorial permutations of indices for multi-channel encoding. Computes minimum factoradial value meeting target count, fills permutation array, and advances to next combination. Uses lookup table for index remapping in mode 2.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ImageBufferStrideFill (0051e2ba)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | object vtable pointer |
| obj | 0x14 | RW | 55 | error code set when base permutation too small |
| obj | 0x18 | RW | — | error value (computed factorial) |
| this | 0x0 | R | — | object vtable pointer |
| this | 0x28 | R | — | mode flag (2 = use remap lookup table) |
| this | 0x54 | R | — | dimension count (a1[21]) |
| this | 0x64 | R | — | permutation base (a1[25]) |

**Written-by note (persistence):**
- obj 0x14: set to 55 when permutation base fails
- obj 0x18: set to computed factorial on error

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b06c8 | dword_5B06C8 | R | CombinatoricsLookupTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x28 | == | 2 | mode flag = use remap lookup table |

**Guard interpretation:** When this+0x28 == 2, indices are remapped through dword_5B06C8 lookup table before permutation generation (line 66-67). PASSES: remap applied. BLOCKED: direct indexing used (default).
