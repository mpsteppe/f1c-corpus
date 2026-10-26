## DualFieldGetter_60a0_004560a0 — FieldGetter_0x4C_0x50

**Summary:** Copies struct fields at offsets 0x4C and 0x50 to output pointers if non-null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_456670 (00456670), sub_457000 (00457000), sub_457670 (00457670), F_2DTransformStructCopy (00457b60), sub_458A60 (00458a60), sub_459330 (00459330)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4C | R | — | first output field (element [19]) |
| this | 0x50 | R | — | second output field (element [20]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 and a3 are nullable pointers; writes only occur when non-null.
