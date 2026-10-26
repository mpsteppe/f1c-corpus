## ConstantReturnSetter_004db100 — FloatFourInitializer

**Summary:** Sets float field at offset 0x10 to 4.0f and returns the raw bit pattern. Simple constant-field initializer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | 1082130432 → 4.0f | Float field initialized to constant 4.0 |

**Written-by note (persistence):**
- this 0x10: Written unconditionally to 4.0f; persists until explicitly changed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acf5c | dword_5ACF5C | R | Unk_RaceState_Flag [DERIVED] (xref present in IDB but not directly used in this function's code) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — single unconditional write.
