## AbsValueFieldSetter_00499eb0 — ClampToNonNegativeFieldSetter

**Summary:** Sets two fields at offsets 0x60 and 0x64 to the input values, clamping negative inputs to 0 (taking the absolute/non-negative value). Returns the original a3 value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_493060 (00493060)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x60 | RW | — | field set to max(a2, 0) |
| this | 0x64 | RW | — | field set to max(a3, 0) |

**Written-by note (persistence):**
- this 0x60: written unconditionally; external poke survives
- this 0x64: written unconditionally; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 < 0 — if true, field 0x60 set to 0 (else set to a2). a3 < 0 — if true, field 0x64 set to 0 (else set to a3). Each clamped independently.
