## MultiFieldStructWriter_0049aa10 — StructFourFieldWriter

**Summary:** Writes four caller-supplied integer parameters into consecutive dword fields at offsets 0x14-0x20 of a struct. Returns the fourth parameter as result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalMultiParamDispatch (004861a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | RW | — | First stored value (parameter a2) |
| this | 0x18 | RW | — | Second stored value (parameter a3) |
| this | 0x1C | RW | — | Third stored value (parameter a4) |
| this | 0x20 | RW | — | Fourth stored value (parameter a5) |

**Written-by note (persistence):**
- this 0x14: overwritten unconditionally each call; external poke persists until next call
- this 0x18: overwritten unconditionally each call; external poke persists until next call
- this 0x1C: overwritten unconditionally each call; external poke persists until next call
- this 0x20: overwritten unconditionally each call; external poke persists until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always writes all four fields unconditionally
