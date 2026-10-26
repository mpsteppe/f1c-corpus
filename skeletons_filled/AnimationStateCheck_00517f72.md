## AnimationStateCheck_00517f72 — AnimationStateCheck

**Summary:** Evaluates animation state flags to determine whether animation state has changed, by comparing current state bytes (via ByteArrayToInt) against stored CRC32 accumulator. Calls CallbackDispatchWithNullGuard regardless.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_518828 (00518828)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5C | R | — | flags register (bits 8-9: condition for state-change skip) |
| this | 0x5D | R | — | flags register low byte (bit 3: condition for state-change check) |
| this | 0x100 | R | — | stored CRC32 accumulator for comparison |
| this | 0x10C | R | — | control flags (bit 5: selects which flag path to evaluate) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00513bd1 | CallbackDispatchWithNullGuard | dispatches state notification to registered callbacks |
| 00517f35 | ByteArrayToInt | converts current 4-byte state bytes to integer for CRC comparison |

**Guard conditions:**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10C | AND | 0x20 | control flags, bit 5 |
| this | 0x5C | AND | 0x300 | flags register, bits 8-9 |
| this | 0x5D | AND | 0x8 | flags register low byte, bit 3 |

**Guard interpretation:** If this->0x10C bit 5 set AND this->0x5C bits 8+9 both set (0x300), state comparison is SKIPPED (v2=0). If bit 5 not set AND this->0x5D bit 3 not set (0x8 == 0), state comparison also SKIPPED (v2=0). Only when v2 remains 1 does the function compare current bytes vs stored CRC; returns true if they differ (state changed).
