## MultiFieldGetter_004560e0 — FieldGetter_0x64_0x68_0x6C

**Summary:** Copies struct fields at offsets 0x64, 0x68, and 0x6C to three output pointers if non-null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_456670 (00456670), sub_457000 (00457000), sub_457670 (00457670), F_2DTransformStructCopy (00457b60), sub_458A60 (00458a60), sub_459330 (00459330)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x64 | R | — | first output field (element [25]) |
| this | 0x68 | R | — | second output field (element [26]) |
| this | 0x6C | R | — | third output field (element [27]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2, a3, a4 are nullable pointers; writes only occur when non-null.
