## ShortComputation_6600_00476600 — HUDTextNodeDestructor

**Summary:** Destructor for a HUD text node in a UI class hierarchy. Sequentially sets vtable pointers and frees nested child objects at offsets 0x3C, 0x30, and 0x04.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (written 3× during destruction chain) |
| this | 0x4 | R | — | child object pointer at offset 0x04 (freed third) |
| this | 0x30 | R | — | child object pointer at offset 0x30 (freed second) |
| this | 0x3C | R | — | child object pointer at offset 0x3C (freed first) |

**Written-by note (persistence):**
- this 0x0: written 3× sequentially during destructor; external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a443c | off_5A443C | R | VTable_ControlBase [DERIVED] |
| 005a4450 | off_5A4450 | R | VTable_HUDTextNode [DERIVED] |
| 005a448c | off_5A448C | R | VTable for intermediate HUD node class |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | frees a heap-allocated block |

**Guard conditions:** `this[12]` (offset 0x30) == NULL → skip second free; `this[15]` (offset 0x3C) == NULL → skip first free; `this[1]` (offset 0x04) == NULL → skip third free; `(a2 & 1) == 0` → skip self-free
