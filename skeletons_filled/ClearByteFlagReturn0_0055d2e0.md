## ClearByteFlagReturn0_0055d2e0 — Clear byte flag and return 0

**Summary:** Clears byte at this+0x58 to 0 and returns 0. Minimal flag-reset helper.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5454A0 (005454a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x58 | RW | 0 | Byte flag — cleared to 0 on each call |

**Written-by note (persistence):**
- this 0x58: Set to 0 every call. External poke does not survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always executes unconditionally.
