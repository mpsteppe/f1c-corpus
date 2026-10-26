## StateQueryDispatch_0048c940 — StateQueryDispatch

**Summary:** Dispatches state-dependent action through vtable[16] with different args. If byte at this+0x100 is true, calls vtable[16](5). Otherwise checks ShortComputation_6720 result; if ==5, calls vtable[16](0). Always calls vtable[43] afterward. Used for state-based branching in collision/HUD system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x40 | R | — | VTable entry 16 (offset 64) — state-dependent action dispatcher |
| obj | 0xAC | R | — | VTable entry 43 (offset 172) — always-called update/cleanup |
| this | 0x0 | R | — | VTable pointer (to read vtable entries at obj+0x40 and obj+0xAC) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486710 | ByteFieldGetterAt100 | Reads flag byte at this+0x100; determines which dispatch path |
| 00486720 | ShortComputation_6720 | Returns integer state value; compared against 5 for second path |

**Guard conditions:** If ByteFieldGetterAt100 returns nonzero (true state at this+0x100) → PASSES: vtable[16](5). If ByteFieldGetterAt100 returns 0 and ShortComputation_6720 result == 5 → PASSES: vtable[16](0). If ByteFieldGetterAt100 returns 0 and ShortComputation_6720 result != 5 → vtable[16] skipped. vtable[43] always called in both branches.
