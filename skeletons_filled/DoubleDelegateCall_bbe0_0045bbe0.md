## DoubleDelegateCall_bbe0_0045bbe0 — UIRenderObjectPostInit

**Summary:** Post-initialization for UI render object. Calls audio collision helper, clears field at offset 0x31C in the object, then resets 8 per-index sub-structures. Returns result of last PerIndexStructFieldResetter call.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** OnScreen_Init (0049efa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x31C | RW | 0 | UI render object field at offset 0x31C: cleared to 0 during post-init |
| this | 0x0 | R | — | pointer to UI render object (previously allocated and initialized) |

**Written-by note (persistence):**
- obj 0x31C: written once to 0 during post-init. Survives until externally modified.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045b950 | sub_45B950 | configure audio collision settings |

**Guard conditions:** None — always executes all operations unconditionally. Loop runs exactly 8 iterations (v1 = 0..7).
