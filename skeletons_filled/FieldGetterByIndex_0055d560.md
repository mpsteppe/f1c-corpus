## FieldGetterByIndex_0055d560 — Read alpha/scale factor by group index

**Summary:** Reads one of three alpha/scale factor fields (offset 0x14/0x24/0x34) based on index a2 (1/2/3), writes to output pointer a3 if non-null. Getter counterpart to UIPropertyValueSetter_0055d410.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_558E70 (00558e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | Alpha/scale factor for color group 1 — read when a2==1 |
| this | 0x24 | R | — | Alpha/scale factor for color group 2 — read when a2==2 |
| this | 0x34 | R | — | Alpha/scale factor for color group 3 — read when a2==3 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a3 (output pointer) == NULL: BLOCKED — returns without writing. a2 value: 1/2/3 selects which field to read; other values return without writing.
