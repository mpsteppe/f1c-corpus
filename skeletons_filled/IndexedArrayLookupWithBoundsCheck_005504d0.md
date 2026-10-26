## IndexedArrayLookupWithBoundsCheck_005504d0 — ArrayFrameLookupWithBinkReset

**Summary:** Bounds-checked lookup into an array of animation/material frames (148-byte stride), with optional Bink video decoder reset when frame type is terminal and texture effect gate is set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5550E0 (005550e0), sub_55CF50 (0055cf50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA4 | R | — | Array element count (upper bound for a3 index) |
| this | 0xA8 | R | — | Array base pointer (frame entries, 148 bytes each) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b6ac4 | dword_8B6AC4 | R | TextureEffectGate — gates the Bink video decoder reset path |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00551dd0 | BinkVideoFrameDecoder | Reset/decode Bink video frame when frame type is terminal |

**Guard conditions:** 
- a3 >= this[41] (this+0xA4): index out of bounds → return 0. PASS when a3 < count.
- v4[18] ≤ 1: terminal frame type → check Bink reset path and return frame pointer directly. BLOCKED when > 1 (falls through).
- a2 == -1 (when v4[18] > 1): return frame pointer directly without index arithmetic. PASS when -1.
- v4[36] == 0 or dword_8B6AC4 == 0: skip Bink video decoder reset. PASS when both non-zero.
