## CompositingPass_005199d5 — CompositingPass

**Summary:** Renders composited sprite scan lines onto a buffer by iterating through visible sprite objects and dispatching their draw functions, advancing frame when current line completes.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x124) | 0x4 | R | — | sprite object vtable/type index |
| *(this+0x124) | 0x24 | R | — | sprite object stride (pitch) |
| *(this+0x124) | 0x30 | R | — | sprite object base Y offset |
| *(this+0x124) | 0x34 | R | — | sprite object height/count |
| *(this+0x124) | 0x38 | R | — | sprite object element count per object |
| *(this+0x124) | 0x3C | R | — | sprite object stride in output |
| *(this+0x124) | 0x40 | R | — | sprite object Y multiplier |
| *(this+0x124) | 0x44 | R | — | sprite object Y offset for high lines |
| *(this+0x124) | 0x48 | R | — | sprite object scan line threshold |
| this | 0x80 | R | — | current frame index in animation sequence |
| this | 0x88 | R | — | counter incremented per processed scan line |
| this | 0x118 | R | — | frame animation limit (total frames) |
| this | 0x120 | R | — | number of sprite objects to composite |
| this | 0x124 | R | — | pointer to array of sprite object descriptors |
| this | 0x134 | R | — | buffer scan line limit (max lines to process) |
| this | 0x13C | R | — | buffer size multiplier (shift left 7 = *128) |
| this | 0x184 | R | — | pointer to frame compositing state |
| this | 0x18C | R | — | vtable pointer for frame-complete callback |
| this | 0x194 | R | — | vtable pointer for buffer-ready check function |
| this | 0x198 | RW | 0 | current copy position in scan line |
| this | 0x19C | RW | — | current scan position in buffer |
| this | 0x1A0 | R | — | total buffer size limit |
| this | 0x1A4 | R | — | not directly referenced in this function |

**Written-by note (persistence):**
- this 0x198: conditional, zeroed when scan position passes limit; survives external poke
- this 0x19C: unconditional at exit, written with current scan position; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005159a8 | MemoryZeroFill | clears destination buffer before compositing each scan line |
| 00519986 | SpriteFrameSelector | advances to next sprite frame when current line completes |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x120 | > | 0 | sprite object count |

**Guard interpretation:** this->0x120 > 0 PASSES (processes sprite objects in inner compositing loop). When 0 or less, skip sprite rendering but still advances scan position. Frame advance occurs when current scan position (this->0x19C) reaches buffer limit (this->0x1A0) — triggers this->0x80 increment + possible SpriteFrameSelector call.
