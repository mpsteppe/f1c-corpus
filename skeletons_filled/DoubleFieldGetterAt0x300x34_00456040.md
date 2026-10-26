## DoubleFieldGetterAt0x300x34_00456040 — FieldGetter_0x30_0x34

**Summary:** Copies struct fields at offsets 0x30 and 0x34 to output pointers if non-null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_457000 (00457000), F_2DTransformStructCopy (00457b60), sub_458A60 (00458a60), sub_458DF0 (00458df0), sub_459330 (00459330), sub_45B5C0 (0045b5c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x30 | R | — | first output field (element [12]) |
| this | 0x34 | R | — | second output field (element [13]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 and a3 are nullable pointers; writes only occur when non-null.
