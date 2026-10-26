## TireCompoundClamp_004af220 — TireCompoundClamp

**Summary:** Clamps tire compound selection to valid range. Selects compound value (12/14/16) and index (0/1/2/3) based on compound mode (1-4), then clamps both against per-object min/max bounds.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_472510 (00472510), TrackEnvironmentSelect (004ade20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xD98 | RW | 16 | tire compound value, set to 12/14/16 per mode, clamped to [0xDA0, 0xDA4] |
| this | 0xDA0 | R | — | tire compound minimum bound |
| this | 0xDA4 | R | — | tire compound maximum bound |
| this | 0x1170 | RW | 3 | tire compound index (0/1/2/3), clamped to [0x1178, 0x117C] |
| this | 0x1178 | R | — | tire compound index minimum bound |
| this | 0x117C | R | — | tire compound index maximum bound |
| this | 0x1B34 | R | — | tire compound mode selector (1-4, switch variable) |

**Written-by note (persistence):**
- this 0xD98: set each call based on compound mode then clamped; survives until next call
- this 0x1170: set each call based on compound mode then clamped; survives until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004af384 | jpt_4AF231 | R | jump table for switch on compound mode |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Switch on this[1741] (tire compound mode at offset 0x1B34). Cases 1-4 set compound value and index, then clamp to bounds. Default: return immediately with no changes (result = this[1741] - 1). Blocked: compound mode < 1 or > 4.
