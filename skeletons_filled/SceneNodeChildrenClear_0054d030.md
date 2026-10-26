## SceneNodeChildrenClear_0054d030 — Scene node child element audio cleanup

**Summary:** Frees audio resources for each child element in the vertex element array when the 0x8000000 active flag is set, then clears the flag. Companion teardown to the mesh processing functions.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TreeActiveCheck (00544e20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | RW | — | Flags word; bit 27 (0x8000000) is the active/dirty flag that guards this cleanup and is cleared at end |
| this | 0x118 | R | — | Child element count |
| this | 0x11C | R | — | Child element array pointer (64-byte stride per entry) |

**Written-by note (persistence):**
- this 0x14: bit 0x8000000 cleared after cleanup; was set by mesh processing functions

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00540cb0 | AudioResourceFree | Frees an audio resource via SoundManager |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x118 | > | 0 | Child element count |

**Guard interpretation:** Outer guard: if `this[5] & 0x8000000` is zero, BLOCKED entirely (no work to do). Inner guard: if this[70] (child element count at +0x118) > 0, PASSES: iterates and frees audio resources for each child. If <= 0, BLOCKED: skip audio cleanup, still clear the flag bit.
