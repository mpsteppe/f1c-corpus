## DriverStateFlagSet_00512334 — Set driver flag and state byte when state below 8

**Summary:** When the state byte at offset 0x117 is less than 8, sets bit 4 on flags DWORD at offset 0x60 and writes 8 to the driver-state byte at offset 0x118.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_50210E (0050210e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x60 | RW | — | flags DWORD; bit 4 set conditionally |
| this | 0x117 | R | — | state byte; compared to threshold 8 |
| this | 0x118 | RW | 8 | driver-state byte; written to 8 when guard passes |

**Written-by note (persistence):**
- this 0x60: OR-write sets bit 4 conditionally; persists until cleared
- this 0x118: written to 8 conditionally; survives until next write

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x117 | < | 8 | state byte threshold |

**Guard interpretation:** PASSES (sets bit 4 on flags, writes 8 to state byte at 0x118) when byte at offset 0x117 < 8. BLOCKED (no modification) when state >= 8.
