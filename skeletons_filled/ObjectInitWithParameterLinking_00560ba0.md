## ObjectInitWithParameterLinking_00560ba0 — ObjectInitAndLink

**Summary:** Initialize object with default values and link it to a2's child list at offset 560. Sets float default (0.2f), zeroes most fields, stores a3 parameter, sets state flag to 2.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LinkedListNodeInsert_5930 (00545930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 1045220557 → 0.2f | Float property, default 0.2f |
| this | 0x4 | RW | 0 | Integer field, zeroed |
| this | 0x8 | RW | 0 | Integer field, zeroed |
| this | 0xC | RW | 0 | Integer field, zeroed |
| this | 0x10 | RW | 0 | Integer field, zeroed |
| this | 0x14 | RW | 0 | Integer field, zeroed |
| this | 0x18 | RW | — | Stores a2 (parent pointer) |
| this | 0x1C | RW | 0 | Integer field, zeroed |
| this | 0x20 | RW | 0 | Integer field, zeroed |
| this | 0x24 | RW | 2 | State/flag field (set to 2) |
| this | 0x28 | RW | — | Stores a3 (parameter value) |
| this | 0x2C | RW | 0 | Integer field, zeroed |
| this | 0x30 | RW | 0 | Integer field, zeroed |
| this | 0x34 | RW | 0 | Integer field, zeroed |

**Written-by note (persistence):**
- all fields: set once during init; may be modified externally later

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053c2a0 | GlobalZeroInit_c2a0 | Zero-initialize whole object memory |

**Guard conditions:** None
