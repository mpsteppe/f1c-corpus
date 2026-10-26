## ConditionalScaleApply_0053b350 — ConditionalScaleApplyTransform

**Summary:** Conditionally applies three scale factors to groups of fields in a transform/data struct based on a bit flag. Clears the flag after applying to prevent re-application.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_558E70 (00558e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Flags bitfield (bit 1 = scale-pending flag) |
| this | 0x1C | R | — | Scale factor A |
| this | 0x20 | R | — | Scale factor B |
| this | 0x24 | R | — | Scale factor C |
| this | 0x28 | RW | — | Group A data field 0 (scaled by factor A) |
| this | 0x2C | RW | — | Group A data field 1 (scaled by factor A) |
| this | 0x30 | RW | — | Group A data field 2 (scaled by factor A) |
| this | 0x38 | RW | — | Group B data field 0 (scaled by factor B) |
| this | 0x3C | RW | — | Group B data field 1 (scaled by factor B) |
| this | 0x40 | RW | — | Group B data field 2 (scaled by factor B) |
| this | 0x48 | RW | — | Group C data field 0 (scaled by factor C) |
| this | 0x4C | RW | — | Group C data field 1 (scaled by factor C) |
| this | 0x50 | RW | — | Group C data field 2 (scaled by factor C) |

**Written-by note (persistence):**
- this 0x0: conditional — bit 1 cleared only when set; external poke can re-set
- this 0x28: conditional — written only when bit 1 was set; external poke survives
- this 0x2C: conditional — written only when bit 1 was set; external poke survives
- this 0x30: conditional — written only when bit 1 was set; external poke survives
- this 0x38: conditional — written only when bit 1 was set; external poke survives
- this 0x3C: conditional — written only when bit 1 was set; external poke survives
- this 0x40: conditional — written only when bit 1 was set; external poke survives
- this 0x48: conditional — written only when bit 1 was set; external poke survives
- this 0x4C: conditional — written only when bit 1 was set; external poke survives
- this 0x50: conditional — written only when bit 1 was set; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks bit 1 (value 2) of field at offset 0 (flags). If set, scale factors are applied to data groups and bit is cleared. If not set, function returns immediately without modifications.
