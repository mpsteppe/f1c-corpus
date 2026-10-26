## AddFloatToAnimationChannels_00556900 — AnimChannelAddFloatToFlagged

**Summary:** Iterates a linked list of animation channel nodes starting from `this+0x110 + 0x28`. For each channel whose flags at offset 0x18 have bit 0x400 set, adds a float parameter to the accumulator at offset 0x38. Part of animation system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_557120 (00557120)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x138)+0x5C)+0x54) | 0x18 | R | — | channel flags; bit 0x400 controls whether float is added |
| *(*(*(this+0x138)+0x5C)+0x54) | 0x38 | RW | — | channel float accumulator (value added to each frame) |
| *(*(this+0x138)+0x5C) | 0x54 | R | — | pointer to channel data block from linked list node |
| *(*(this+0x138)+0x5C) | 0x5C | R | — | linked list next node pointer |
| this | 0x110 | R | — | pointer to animation list head structure |
| this | 0x138 | R | — | pointer to animation state/controller |

**Written-by note (persistence):**
- *(*(*(this+0x138)+0x5C)+0x54) 0x38: float accumulator at offset 0x38 is updated every iteration for flagged channels; accumulates over time

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** 
1. `result == NULL` (head of list is null) → loop body never executes, return null
2. Per-node: `(*(_DWORD *)(v3 + 24) & 0x400) == 0` → skip this channel (float not added)
   PASSES: bit 0x400 set → add parameter a2 to channel's float accumulator at offset 0x38
   BLOCKED: linked list exhausted (next pointer is null) OR channel flag doesn't have bit 0x400