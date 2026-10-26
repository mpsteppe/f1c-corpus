## F_3FieldInitCall_004bd7d0 — ThreeFieldZeroInit

**Summary:** Zeros three struct fields (offsets 0x8, 0x14, 0x20) then calls StructCleanup for additional teardown. Called by AudioMixerChannelInit.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioMixerChannelInit (004bdb90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 0 | first field zeroed |
| this | 0x14 | RW | 0 | second field zeroed |
| this | 0x20 | RW | 0 | third field zeroed |

**Written-by note (persistence):**
- this 0x8: set to 0 unconditionally; external poke overwritten
- this 0x14: set to 0 unconditionally; external poke overwritten
- this 0x20: set to 0 unconditionally; external poke overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bd800 | StructCleanup | performs additional teardown/cleanup on the struct |

**Guard conditions:** none — unconditional initialization
