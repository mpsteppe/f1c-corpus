## BufferBoundaryMarkerCheckSet_00599534 — BufferBoundaryMarkerCheckAndSet

**Summary:** Checks buffer boundary marker byte at data[-1] (this+0x4). If marker is non-zero and not 0xFF, validates via sub_599560. Then unconditionally sets marker to 0xFF (sentinel). Returns previous marker value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_598E9E (00598e9e), CharValidationAgainstEncodingTableWithLocaleFall (00598fd4), sub_5990AE (005990ae), sub_599ED6 (00599ed6), FileOffsetPositionValidation (0059a01e), sub_59A103 (0059a103)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | pointer to data block; boundary marker byte is at data[-1] |
| this | 0x8 | R | — | value passed to sub_599560 for boundary validation |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00599560 | sub_599560 | validate buffer boundary when marker is non-zero / non-sentinel |

**Guard conditions:** if this+0x4 is NULL, skip all marker operations. If marker byte is non-zero AND not 0xFF, call sub_599560 for validation. After check, unconditionally set marker to 0xFF.
