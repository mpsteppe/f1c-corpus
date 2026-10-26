## GlobalFlagBasedStateSetter_0045d490 — GlobalFlagBasedStateSetter

**Summary:** Checks game module state; if valid, updates object state by calling sub_45CD70 then sets byte flag at this+1 from global boolean byte_7D0F94.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionTypeSetter (00463f70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1 | RW | 0 | State/flag byte set from global boolean (byte_7D0F94) |

**Written-by note (persistence):**
- this 0x1: conditional — set to 0 or 1 based on byte_7D0F94 only when StateCheckWrapper passes; otherwise unchanged

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007d0f94 | byte_7D0F94 | R | GlobalBooleanFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045cd70 | sub_45CD70 | Update object state (called on this) |
| 00461dc0 | StateCheckWrapper | Validate game module state before proceeding |

**Guard conditions:** 
- StateCheckWrapper(dword_7CD25C) returns 0 → early return (this+1 unchanged, returns 0).
- StateCheckWrapper passes (nonzero) → calls sub_45CD70, then sets this+1 = byte_7D0F94 (0 or 1).
