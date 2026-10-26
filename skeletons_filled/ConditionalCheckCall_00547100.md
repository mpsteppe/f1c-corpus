## ConditionalCheckCall_00547100 — Conditional setter with 0x80000000 argument

**Summary:** Checks if a2 < this+0xA4 and this+0xA4 < 8; if both true, calls SimpleSetter_fc40(0x80000000) and FieldSetter_fca0(4). Resource object configuration with highest-bit flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ResourceObjectCreationWithConfig (005474d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA4 | R | — | comparison field (must be > a2 and < 8 to trigger setters) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054fc40 | SimpleSetter_fc40 | setter with literal 0x80000000 |
| 0054fca0 | FieldSetter_fca0 | setter with argument 4 |

**Guard conditions:** If a2 < this+0xA4 AND this+0xA4 < 8, PASSES: calls SimpleSetter_fc40(0x80000000) and FieldSetter_fca0(4). Otherwise BLOCKED: returns 0.
