## TwoFieldSetter_00497d00 — SetDwordAndFlag

**Summary:** Stores parameter `a2` to DWORD field at offset 0x18A8 and sets byte flag at offset 0x18EC to 1. Returns a2. Simple two-field setter.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49A5D0 (0049a5d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18A8 | RW | — | DWORD field storing incoming parameter a2 |
| this | 0x18EC | RW | 1 | Byte flag set to 1 (activation/dirty flag) |

**Written-by note (persistence):**
- this 0x18A8: Written unconditionally each call. External poke does not survive.
- this 0x18EC: Written unconditionally to 1 each call. External poke does not survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — writes both fields and returns unconditionally.
