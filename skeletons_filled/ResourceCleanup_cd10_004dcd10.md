## ResourceCleanup_cd10_004dcd10 — Dual-resource cleanup/destructor

**Summary:** Frees two resource pointers stored in the object: calls destructor then frees memory for pointer at offset +4, and calls cascade cleanup on pointer at offset +0 if non-null. Returns result of ShortComputation_cb70.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49B0A0 (0049b0a0), StaticArrayCleanup (0049b1c0), sub_4DCBA0 (004dcba0), ShortComputation_d000 (004dd000)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Primary resource pointer (cascade cleanup) |
| this | 0x4 | R | — | Secondary resource pointer (destructor + free) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005502c0 | DestructorWithConditionalFreeFlagClear | Run destructor on object and clear free flag |
| 005539f0 | ResourceCascadeCleanup | Cascade cleanup of primary resource tree |
| 00557470 | EmptyStub_7470 | Empty stub (no-op or debug placeholder) |
| 00587bcf | FreeWrapper_7bcf | Free memory wrapper (operator delete) |

**Guard conditions:** Checks `this[1]` (offset +4) for non-null before destructor/free sequence. Checks `*this` (offset +0) for non-null before ResourceCascadeCleanup. Both guard blocks (skip if null).
