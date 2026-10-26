## FieldSetterAt0x410_00587710 — Set DWORD at offset 0x410

**Summary:** Simple DWORD setter — stores `a2` into field at offset 0x410 and returns the same value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_584130 (00584130), LinkedListWalkWithInputDispatch (00585320)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x410 | RW | a2 | DWORD field set from parameter |

**Written-by note (persistence):**
- this 0x410: written from a2 each call; external poke overwrites it

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional write.
