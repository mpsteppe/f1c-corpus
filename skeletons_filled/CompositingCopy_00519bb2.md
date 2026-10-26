## CompositingCopy_00519bb2 — CompositingCopy

**Summary:** Copies composited sprite pixel data into destination buffers through sprite object descriptors, advancing frame when the current copy line reaches the buffer limit.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x124) | 0x4 | R | — | sprite object vtable/type index |
| *(this+0x124) | 0xC | R | — | sprite object width/stride per row |
| *(this+0x124) | 0x34 | R | — | sprite object row stride (copy count per row) |
| *(this+0x124) | 0x38 | R | — | sprite object number of rows |
| this | 0x4 | R | — | vtable pointer for allocation dispatch |
| this | 0x24 | R | — | not directly referenced in this function |
| this | 0x80 | R | — | current frame index in animation sequence |
| this | 0x118 | R | — | frame animation limit (total frames) |
| this | 0x120 | R | — | number of sprite objects to process |
| this | 0x124 | R | — | pointer to array of sprite object descriptors |
| this | 0x134 | R | — | buffer scan line limit (max lines) |
| this | 0x184 | R | — | pointer to frame copy state |
| this | 0x18C | R | — | vtable pointer for frame-complete callback |
| this | 0x194 | R | — | vtable pointer for buffer-ready check function |
| this | 0x198 | RW | 0 | current copy position in line |
| this | 0x19C | RW | — | current line position tracker |
| this | 0x1A0 | R | — | total buffer size limit |

**Written-by note (persistence):**
- this 0x198: conditional, zeroed when copy position passes limit; survives external poke
- this 0x19C: unconditional at exit, written with current i pointer value; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00519986 | SpriteFrameSelector | advances to next sprite frame when current line completes |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x124) | 0x38 | > | 0 | sprite object row count |
| this | 0x120 | <= | 0 | sprite object count check (skip objects) |
| this | 0x120 | > | 0 | sprite object count (enter allocation loop) |

**Guard interpretation:** this->0x120 > 0 PASSES (allocates per-object buffers). Inner copy loop PASSES only when *(object+0x38) > 0 (rows to copy). this->0x120 <= 0 skips object buffer allocation. Frame advance occurs when line position reaches this->0x134 limit — triggers SpriteFrameSelector or frame-complete callback.
