## StructInitWithConditionalDefaultRead_00567900 — struct init with conditional field get

**Summary:** Initializes struct: stores pointer a2 at offset 0, sets sentinels (-1) at offsets 0x14 and 0x1C, zeroes offsets 0x4-0x10, 0x18, 0x24, 0x28. If a2 is non-null, retrieves value via FieldGetter_79d0 into offset 0x20; else keeps -1. File data processing init.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FileDataProcessor (00567fb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | pointer/reference (stored from a2 parameter) |
| this | 0x4 | RW | 0 | counter/index (zeroed) |
| this | 0x8 | RW | 0 | state/cursor (zeroed) |
| this | 0xC | RW | 0 | mode/flag (zeroed) |
| this | 0x10 | RW | 0 | count/total (zeroed) |
| this | 0x14 | RW | -1 (0xFFFFFFFF) | sentinel value |
| this | 0x18 | RW | 0 | progress/offset (zeroed) |
| this | 0x1C | RW | -1 (0xFFFFFFFF) | sentinel / end marker |
| this | 0x20 | RW | — | result from FieldGetter_79d0 (or -1 if a2 null) |
| this | 0x24 | RW | 0 | extra field (zeroed) |
| this | 0x28 | RW | 0 | extra field (zeroed) |

**Written-by note (persistence):**
- this 0x0: overwritten each call; external poke does not survive
- this 0x4-0x10: unconditionally zeroed; external poke does not survive
- this 0x14: unconditionally set to -1; external poke does not survive
- this 0x18: unconditionally zeroed; external poke does not survive
- this 0x1C: unconditionally set to -1; external poke does not survive
- this 0x20: overwritten each call; external poke does not survive
- this 0x24-0x28: unconditionally zeroed; external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004979d0 | FieldGetter_79d0 | retrieve field value from a2 object |

**Guard conditions:** If a2 == NULL → skip FieldGetter_79d0, keep offset 0x20 as -1. If a2 != NULL → call FieldGetter_79d0 and store result.
