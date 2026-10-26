## SelfCopyStringWithOffset_00548e80 — CopyStringToInternalBuffer

**Summary:** Copies a string from a2 to the internal buffer at this+8, calls sub_589901 string normalization, then stores the caller value a3 into this[4]. Returns a3.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_55A790 (0055a790)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | Stores value of a3 (index/metadata passed by caller) |

**Written-by note (persistence):**
- this 0x4: Written once unconditionally; external poke survives after execution

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00589901 | sub_589901 | String normalization (e.g., uppercase/lowercase) applied to internal buffer at this+8 |

**Guard conditions:** None — string copy loop copies characters until null terminator is found. Function always writes this[4] and returns.
