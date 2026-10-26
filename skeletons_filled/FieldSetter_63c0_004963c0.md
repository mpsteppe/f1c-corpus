## FieldSetter_63c0_004963c0 — FlagSetter_0x28_Enable

**Summary:** Sets the DWORD at offset 0x28 to 1 and returns 0. A simple boolean flag enable/setter function for an object state.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_485B90 (00485b90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x28 | RW | 1 | DWORD flag at offset 0x28; set to 1 unconditionally — enables or activates some object state |

**Written-by note (persistence):**
- this 0x28: written unconditionally to 1; persists until explicitly cleared externally

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — executes unconditionally.
