## ObjectSetupWithBoundsCheck_0051eb6e — AllocateAndInitObjectWithBoundsCheck

**Summary:** Allocates a sub-object via factory function at this+0x4, initializes its fields with codec/function pointers, then conditionally clamps dimensions (width/height) based on thresholds at this+0x64 (>4) and this+0x54 (>256) by writing to the sub-object and dispatching a virtual call. Part of codec/decoder initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_516C7B (00516c7b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | Function pointer table start; set to CodecModeSelect during init |
| obj | 0x14 | RW | 56 | Bound/dimension field written when width exceeds 256 |
| obj | 0x18 | RW | 256 | Bound/dimension field written when width exceeds 256 |
| this | 0x0 | R | — | Pointer to sub-object (obj) with function table |
| this | 0x4 | R | — | Factory/allocation function pointer for creating obj |
| this | 0x4C | R | — | Codec mode selector; compared to 2 for VirtualArrayFill path |
| this | 0x54 | R | — | Width dimension; guards whether to clamp at 256 |
| this | 0x64 | R | — | Height/parameter; guards whether to clamp at 4 |
| this | 0x1A4 | RW | — | Stores pointer to newly allocated obj |

**Written-by note (persistence):**
- obj 0x14: written conditionally if width>256 (56) or height>4 (54); persists until overwritten
- obj 0x18: written conditionally if width>256 (256) or height>4 (4); persists until overwritten
- this 0x1A4: stores allocated pointer once; persists across function calls

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0051dfca | nullsub_4 | R | No-op callback stored at obj+0x8 |
| 0051ea90 | CodecModeSelect | R | Codec mode function pointer stored at obj+0x0 |
| 0051eb5a | VirtualCallWithIntegerSet | R | Callback stored at obj+0xC; dispatches virtual call with integer parameter |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051e2ba | ImageBufferStrideFill | Fills image buffer stride/layout information for this |
| 0051e3e7 | sub_51E3E7 | Further initialization after stride setup |
| 0051ea5a | VirtualArrayFill | Fills virtual array structure; called only when codec mode == 2 |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4C | == | 2 | Codec mode selector — PASSES (calls VirtualArrayFill) when equal to 2; BLOCKED when not 2 |
| this | 0x54 | > | 256 | Width bound — PASSES (clamps to 256) when greater than 256; BLOCKED when ≤256 |
| this | 0x64 | > | 4 | Height/param bound — PASSES (clamps to 4) when greater than 4; BLOCKED when ≤4 |

**Guard interpretation:** Three independent guards: (1) codec mode == 2 gates VirtualArrayFill call; (2) width > 256 gates width clamp to 256 with virtual dispatch; (3) height > 4 gates height clamp to 4 with virtual dispatch. All three are checked unconditionally in sequence.
