## DelegationWrapperToFUN0040ed10_00410b60 — ArrayIndexedDelegationWrapper

**Summary:** Extracts an index from an input struct (offset 0x4), uses it to look up a 36-byte-stride array element from `this+0x10`, and delegates to sub_40ED10. Thin wrapper for indexed per-element processing.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SceneRenderUpdate (004c6d90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | Base pointer to array of 36-byte elements |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040ed10 | sub_40ED10 | Per-element processing callback (receives pointer to array element) |

**Guard conditions:** None — no branch checks; always computes array address and delegates.
