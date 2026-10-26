## MeshResourceAllocator_005450e0 — Mesh resource object allocator and initializer

**Summary:** Allocates a 572-byte mesh resource object, runs its constructor, stores an ID at offset 0x3C, copies a name string into it, and returns the pointer via `*a1`. On string-copy failure, runs destructor and frees memory, returning -1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitCrewMeshLoader (004a2010), PitCrewAnimationLoader (004a2a90), sub_4D0110 (004d0110)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | Output pointer written on success; zeroed on entry if non-null |

**Written-by note (persistence):**
- this 0x0: Written once on success (`*a1 = v5`). Zeroed on entry if a1 was non-null.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054a600 | sub_54A600 | Mesh resource object constructor/initializer |
| 0054a710 | TwoFunctionCallChain | Destructor/cleanup on allocation failure |
| 0054a730 | SelfCopyStringWithValidation | Copy name string into allocated mesh resource |
| 00587bcf | FreeWrapper_7bcf | Free allocated memory on failure |
| 00587c03 | OperatorNewNhMallocWrapper | Heap allocation of 572-byte mesh resource block |

**Guard conditions:** `SelfCopyStringWithValidation` return: PASSES (return 0, store pointer) when string copy succeeds; BLOCKED (run destructor, free, return -1) when copy fails (non-zero return).
