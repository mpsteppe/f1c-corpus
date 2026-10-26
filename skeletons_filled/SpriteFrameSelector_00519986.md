## SpriteFrameSelector_00519986 — SpriteFrameSelector

**Summary:** Selects current sprite frame index based on position within an animation sequence, writing frame data and zeroing output fields on the frame info struct.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CompositingPass (005199d5), CompositingCopy (00519bb2)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x80 | R | — | current animation index position |
| this | 0x118 | R | — | animation frame limit (end value, compared as limit-1) |
| this | 0x120 | R | — | animation mode selector, <= 1 uses frame selection logic |
| this | 0x124 | R | — | pointer to sprite frame data array |
| this | 0x130 | R | — | not directly referenced here |
| this | 0x16C | R | — | not directly referenced here |
| this | 0x184 | R | — | pointer to output frame info struct |
| this | 0x198 | RW | 0 | output frame info field (result[5]), zeroed |
| this | 0x19C | RW | 0 | output frame info field (result[6]), zeroed |
| this | 0x1A0 | RW | 1 | output frame info field (result[7]), set to frame data or 1 |

**Written-by note (persistence):**
- this 0x198: unconditional, set to 0; survives external poke
- this 0x19C: unconditional, set to 0; survives external poke
- this 0x1A0: unconditional, set to frame data value or 1; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x120 | <= | 1 | animation mode selector |

**Guard interpretation:** this->0x120 <= 1 PASSES (enters frame selection logic): compares this->0x80 < (this->0x118 - 1) to choose frame data from offset +12 (current frame) or +72 (last frame) in frame data array. this->0x120 > 1 BLOCKED (sets result[7] = 1, fixed frame).
