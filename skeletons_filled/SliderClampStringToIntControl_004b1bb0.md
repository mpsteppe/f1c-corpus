## SliderClampStringToIntControl_004b1bb0 — String-to-int slider with clamping

**Summary:** Parses a string value to integer via ObjectHandleReader, clamps between lower bound (this+0x1C) and upper bound (this+0x20), stores result at this+0x14. Returns 0 if input is NULL/empty.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | RW | — | Stored integer value (clamped result) |
| this | 0x1C | R | — | Lower bound for clamping |
| this | 0x20 | R | — | Upper bound for clamping |

**Written-by note (persistence):**
- this 0x14: written unconditionally with parsed a2, then possibly clamped; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a1990 | ObjectHandleReader | Parse/read string to integer value |

**Guard conditions:** a2 == NULL or strlen(a2)==0 -> returns 0 immediately (early out). Otherwise parses string, stores at +0x14, clamps between bounds, returns 1.
