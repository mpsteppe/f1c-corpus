## ObjectStateClear_004a5e80 — AIStateClearToZero

**Summary:** Resets AI state to 0 (offset 0x184) and flag to 0 (offset 0x180). If a sub-object pointer at offset 0x14 is non-null, calls ShortComputation_3fe0 on it. Inverse of StatePhaseSetter (which sets state to 4, flag to 1).

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4C6B60 (004c6b60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | Pointer to a sub-object (conditionally called ShortComputation_3fe0) |
| this | 0x180 | RW | 0 | Byte flag, cleared to 0 |
| this | 0x184 | RW | 0 | State/phase value cleared to 0 |

**Written-by note (persistence):**
- this 0x180: recalc every frame — external poke does NOT persist
- this 0x184: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Null-guard on pointer at offset 0x14. PASSES: calls ShortComputation_3fe0 on sub-object. BLOCKED: if pointer is null, skips the call.