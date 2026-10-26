## DisplayModeQueryWrapper_005633d0 — AllocateStructAndPushAudio

**Summary:** Allocates a struct via StructAllocInitWithSwitchBasedType using type selector from this+0x94, then pushes to the audio stack via AudioStackPushWithOverflowRealloc. Returns the allocated struct.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkConnection (00563260)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x94 | R | — | type selector parameter for StructAllocInitWithSwitchBasedType |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005642f0 | StructAllocInitWithSwitchBasedType | allocates struct with type determined by switch parameter |
| 005648d0 | AudioStackPushWithOverflowRealloc | pushes entry to audio stack, handling reallocation if overflow |

**Guard conditions:** none — unconditional allocation and push.

