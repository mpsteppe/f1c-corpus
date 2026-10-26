## AnimationStateFlagSet_00512322 — Set animation flag when state equals 16

**Summary:** Conditionally sets bit 0x10 on flags DWORD at offset 0x60 when the animation-state byte at offset 0x117 equals 16.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_50210E (0050210e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x60 | RW | — | flags DWORD; bit 0x10 set conditionally |
| this | 0x117 | R | — | animation state byte; compared to 16 |

**Written-by note (persistence):**
- this 0x60: OR-write sets bit 0x10 conditionally; persists until cleared

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x117 | == | 16 | animation state byte |

**Guard interpretation:** PASSES (sets bit 0x10 on flags) when byte at offset 0x117 == 16. BLOCKED (no flag modification) when state != 16.
