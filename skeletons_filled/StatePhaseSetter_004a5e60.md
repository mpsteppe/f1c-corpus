## StatePhaseSetter_004a5e60 — AIStatePhase4Initializer

**Summary:** Sets AI state to phase 4 (offset 0x184) and flag to 1 (offset 0x180). If a sub-object pointer at offset 0x14 is non-null, calls ShortComputation_3fe0 on it.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4C6B60 (004c6b60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | Pointer to a sub-object (conditionally called ShortComputation_3fe0) |
| this | 0x180 | RW | 1 | Byte flag, set to 1 (phase indicator) |
| this | 0x184 | RW | 4 | State/phase value set to 4 |

**Written-by note (persistence):**
- this 0x180: recalc every frame — external poke does NOT persist
- this 0x184: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Null-guard on pointer at offset 0x14. PASSES: calls ShortComputation_3fe0 on the sub-object. BLOCKED: if pointer is null, skips the call.