## StructInitWithVtable_0040b560 — Object Constructor With VTable E6AC

**Summary:** Initializes struct with VTable_59E6AC and zeros 5 fields (offsets 0x4, 0x8, 0xC, 0x10, 0x14). Acts as a constructor.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ModuleAssetPathResolver (0040c3b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | VTable pointer (set to VTable_59E6AC) |
| this | 0x4 | RW | 0 | Object field 1 (zeroed) |
| this | 0x8 | RW | 0 | Object field 2 (zeroed) |
| this | 0xC | RW | 0 | Object field 3 (zeroed) |
| this | 0x10 | RW | 0 | Object field 4 (zeroed) |
| this | 0x14 | RW | 0 | Object field 5 (zeroed) |

**Written-by note (persistence):**
- this 0x0: Written unconditionally every call (to off_59E6AC). External poke does NOT survive.
- this 0x4: Written unconditionally every call (to 0). External poke does NOT survive.
- this 0x8: Written unconditionally every call (to 0). External poke does NOT survive.
- this 0xC: Written unconditionally every call (to 0). External poke does NOT survive.
- this 0x10: Written unconditionally every call (to 0). External poke does NOT survive.
- this 0x14: Written unconditionally every call (to 0). External poke does NOT survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e6ac | off_59E6AC | R | VTable_59E6AC [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — all writes execute unconditionally.
