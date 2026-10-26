## ResourceManagerFrameCleanup_004651c0 — Per-frame resource manager cleanup

**Summary:** Per-frame cleanup: computes timestep via HighResolutionTimerDelta (clamped to [0.001, 1.0]), calls FloatFractionFromInt, clears two linked lists (freeing nodes with flag check), zeroes 14560-byte array of bytes at +0x3E, resets accumulator at +0xE40C to 0.0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TeamRadioNetworkMessageProcessing (0045f710)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x6C)+0x4) | 0x4 | R | — | Next pointer of node in first linked list |
| *(*(obj+0x7C)+0x4) | 0x4 | R | — | Next pointer of node in second linked list |
| *(obj+0x6C) | 0x0 | R | — | Embedded data pointer of node in first list |
| *(obj+0x6C) | 0x8 | R | — | Flag byte of node in first list (whether to free embedded data) |
| *(obj+0x7C) | 0x0 | R | — | Embedded data pointer of node in second list |
| *(obj+0x7C) | 0x8 | R | — | Flag byte of node in second list (whether to free embedded data) |
| obj | 0x60 | RW | — | Timestep accumulator (this[24] = clamped delta time) |
| obj | 0x6C | RW | 0 | First linked list head pointer (cleared to 0) |
| obj | 0x70 | RW | 0 | First linked list tail1 pointer (cleared to 0) |
| obj | 0x74 | RW | 0 | First linked list tail2 pointer (cleared to 0) |
| obj | 0x78 | RW | 0 | First linked list count (cleared to 0) |
| obj | 0x7C | RW | 0 | Second linked list head pointer (cleared to 0) |
| obj | 0x80 | RW | 0 | Second linked list tail1 pointer (cleared to 0) |
| obj | 0x84 | RW | 0 | Second linked list tail2 pointer (cleared to 0) |
| obj | 0x88 | RW | 0 | Second linked list count (cleared to 0) |
| obj | 0xE40C | RW | — | Accumulator float (index 14595, reset to 0.0) |
| this | 0x0 | R | — | Pointer to resource manager object |

**Written-by note (persistence):**
- obj 0x60: overwritten with clamped delta time each frame
- obj 0x6C-0x88: all cleared to 0 after list cleanup
- obj 0xE40C: reset to 0.0 each frame

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e600 | flt_59E600 | R | SteeringForceThreshold [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00464ef0 | FloatFractionFromInt | Processes fractional timestep through accumulator |
| 00568cf0 | HighResolutionTimerDelta | Gets high-resolution timer delta for current frame |
| 00587bcf | FreeWrapper_7bcf | Memory deallocation wrapper |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(obj+0x6C) | 0x8 | == | 0 | Node flag byte in first linked list |
| *(obj+0x7C) | 0x8 | == | 0 | Node flag byte in second linked list |

**Guard interpretation:** Timer delta < 0.001 clamps to 0.001; > 1.0 clamps to 1.0. For each linked list, if node flag byte at node+8 == 0, skip freeing that node's embedded data (but still free the node itself). If node flag byte != 0, free both embedded data and node.
