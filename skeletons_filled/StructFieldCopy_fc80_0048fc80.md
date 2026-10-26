## StructFieldCopy_fc80_0048fc80 — ExternalBoundsFieldCopy

**Summary:** Copies rectangle dimensions from an external source struct into local fields: stores source pointer at offset 0x38, reads rectangle width from *(src+12)+28 into offset 0xC, and reads rectangle height from *(src+12)+32 into offset 0x10. Returns the source structure pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameFilterSetup (00477830), ProfileBitmapBrowser (00477cb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | — | rectangle width copied from external source |
| this | 0x10 | RW | — | rectangle height copied from external source |
| this | 0x38 | RW | — | stored pointer to external source struct |

**Written-by note (persistence):**
- this 0xC: set unconditionally; survives until next copy
- this 0x10: set unconditionally; survives until next copy
- this 0x38: set unconditionally; survives until next copy

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional field copy with no branches.
