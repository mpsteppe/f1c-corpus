## StringMatchWithWildcard_004f81d0 — ObjectFindByString

**Summary:** Looks up an object by string identifier through the InitStatus (dword_8AC4C4) virtual method table. Returns handle in `*a1`. Uses default directory path if string is empty (sets output to 0).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4F70C0 (004f70c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | Output handle/object ID; set to 0 if string empty, else set by lookup |

**Written-by note (persistence):**
- this 0x0: Written once per call; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ac4c4 | dword_8AC4C4 | R | InitStatus [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Both `a1` and `a2` must be non-null to proceed. Empty string shortcut (sets output to 0, returns 1). `dword_8AC4C4` must be non-null to perform the virtual method lookup.
