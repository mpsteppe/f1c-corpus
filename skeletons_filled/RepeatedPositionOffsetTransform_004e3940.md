## RepeatedPositionOffsetTransform_004e3940 — RepeatedPositionOffsetTransform

**Summary:** Computes position offset vector from reference point (offsets 0x48/0x4C/0x50), then dispatches to sub_4DEF70 for each entry in array at stride 748 bytes starting from offset 0xBAC. Count controlled by field at offset 0xBA8. Repeated spatial transform for sub-elements.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B3400 (004b3400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x48 | R | — | reference position X for offset subtraction |
| this | 0x4C | R | — | reference position Y for offset subtraction |
| this | 0x50 | R | — | reference position Z for offset subtraction |
| this | 0xBA8 | R | — | count of sub-elements to iterate |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004def70 | sub_4DEF70 | compute position offset and insert into sorted LRU array |

**Guard conditions:** If count (this+0xBA8) > 0, iterate sub-elements (PASS). If <= 0, skip loop (BLOCKED).
