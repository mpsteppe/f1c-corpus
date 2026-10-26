## sub_6CD9DB_006cd9db — Build object-ordering tables and run the optimizer

**Summary:** Allocates and fills every working array of the object-ordering optimizer for the world at +0x4: per-object dependency counts/offsets and two flat index lists built from each object's +0x8 and +0x10 arrays (skipping objects whose word at +2 has none of bits 4..15), the counter (+0x28), offset (+0x2C), flag (+0x34), order (+0x3C), backup (+0x40), pointer (+0x44) and work-order (+0x30) arrays, then loops calling sub_6CD96E until it succeeds, applies the resulting permutation to the world object table and frees all buffers. Returns 0 on success, 0x8007000E on allocation failure; with a2 == 0 it just frees the buffers (teardown).

**Called by:** sub_68C799 (0068c799)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0xC | R | — | world object count, copied into this+0x38 as the table size |
| *(this+0x4) | 0x18 | R | — | world array of object pointers; read while building dependency lists and rewritten with the final permutation |
| this | 0x4 | R | — | pointer to the shared world/context struct |
| this | 0x8 | RW | 0 | per-object count of list A entries (filled by sub_6CD1F0, prefix-summed into +0xC) |
| this | 0xC | RW | 0 | per-object start offset into the flat index array at +0x10 |
| this | 0x10 | RW | 0 | flat index array (list A), one entry per recorded dependency, sorted by sub_6CD379 |
| this | 0x14 | RW | — | allocated object-id buffer, filled by the refinement pass (working set) |
| this | 0x18 | RW | — | allocated object-id buffer, filled by the refinement pass (temp set) |
| this | 0x1C | RW | 0 | per-object count of list B entries (filled by sub_6CD265, prefix-summed into +0x20) |
| this | 0x20 | RW | 0 | per-object start offset into the flat index array at +0x24 |
| this | 0x24 | RW | 0 | flat index array (list B), one entry per recorded dependency, sorted by sub_6CD379 |
| this | 0x28 | RW | 0 | per-object balance counter array, recomputed by sub_6CD3BF |
| this | 0x2C | RW | 0 | per-object offset array written by sub_6CD3BF (allocated at end of this function) |
| this | 0x30 | RW | 0 | work-order array: identity permutation, sorted and iterated by sub_6CD96E |
| this | 0x34 | RW | 0 | per-object skip flag: 1 when the object has no bits 4..15 at word +2 or sub_680F76 returns non-zero |
| this | 0x38 | RW | — | table size, set once from world+0xC |
| this | 0x3C | RW | 0 | order list: initialized to identity by sub_6CD96E, permuted by the refinement runs |
| this | 0x40 | RW | — | backup copy of the order list, taken by each sub_6CD96E invocation |
| this | 0x44 | RW | — | array of object pointers matching +0x3C order indices, used to apply the final permutation |
| this | 0x48 | RW | 0 | round/visit counter, zeroed here and incremented by each refinement pass |

**Written-by note (persistence):**
- this 0x8: zeroed at entry, filled by the two edge-recording passes, then read-only during refinement; written once per build call — an external poke survives until the next build/cleanup call.
- this 0xC: same lifecycle — zeroed then prefix-summed from +0x8; stable after the call, poke survives until next build.
- this 0x10: allocated, filled by sub_6CD1F0/sub_6CD265, sorted once; stable after the call, poke survives until next build.
- this 0x14: allocated here; only written later by the refinement pass inside the same call; stable afterwards — external poke survives until next build.
- this 0x18: allocated here; only written later by the refinement pass inside the same call; stable afterwards — external poke survives until next build.
- this 0x1C: zeroed at entry, filled by the edge-recording passes, then read-only; stable after the call.
- this 0x20: same — zeroed then prefix-summed from +0x1C; stable after the call.
- this 0x24: allocated, filled and sorted once; stable after the call.
- this 0x28: zeroed at entry, then recomputed by sub_6CD3BF in every refinement pass of the same call; final value stable after return.
- this 0x2C: zeroed at entry (and allocated near the end), recomputed by sub_6CD3BF; final value stable after return.
- this 0x30: zeroed, then filled with the identity permutation and sorted by sub_6CD96E; stable after the call.
- this 0x34: zeroed, then written once per object from the word-mask/sub_680F76 test; never updated afterwards until the next build.
- this 0x38: written once from world+0xC; constant for the whole build.
- this 0x3C: zeroed, then identity-initialized and permuted by each refinement run; final order stable after return.
- this 0x40: allocated, then overwritten with a copy of +0x3C at each sub_6CD96E call; stable after return.
- this 0x44: zeroed, then filled once with the object pointers; stable after return.
- this 0x48: zeroed once, then incremented by the refinement passes inside this call; stable after return.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00630739 | ??2@YAPAXI@Z | C++ operator new — allocates each working array (4 bytes per entry) |
| 006308d3 | j__free | CRT free — releases all 15 working buffers on exit/teardown |
| 00680f76 | sub_680F76 | per-object test; non-zero result (or simple object, word+2 mask == 0) sets the skip flag at +0x34 to 1 |
| 00686074 | sub_686074 | world-side preparation called once before the arrays are filled (details not visible here) |
| 006cd1f0 | sub_6CD1F0 | records one dependency edge into the flat per-object list using the object's +0x8 array entries |
| 006cd265 | sub_6CD265 | records one dependency edge into the flat per-object list using the object's +0x10 array entries |
| 006cd379 | sub_6CD379 | sorts each per-object index list in place (base pointer + count by reference) |
| 006cd96e | sub_6CD96E | runs the full ordering refinement; returns 1 = success, 0 = retry, negative = error |

**Guard conditions:** every allocation is checked — any failure jumps to the error path setting v26 = -2147024882 (0x8007000E, E_OUTOFMEMORY), frees all buffers and returns it. If a2 == 0 the function skips the optimizer loop entirely, frees all buffers and returns v26 (0 if all allocations succeeded) — teardown path. Dependency recording runs only for objects with `(*(_WORD *)(object+2) & 0xFFF0) != 0` (both passes); the skip flag is 1 when that mask is zero OR sub_680F76(object) returns non-zero, otherwise 0. In the main loop: negative result from sub_6CD96E is returned immediately (no free); result == 1 applies the permutation to the world object table, frees and returns 0; result == 0 loops and retries.
