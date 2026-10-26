## ConditionalDispatchWithGuard_00511b5c — Conditional audio buffer recalc before packet encoding

**Summary:** Conditionally recalculates audio buffer size when flag bit 0x40 is clear, then always dispatches to packet field encoding.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_50210E (0050210e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5C | R | — | flags byte; bit 0x40 controls whether audio buffer recalculation is skipped |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005124de | PacketFieldEncoding | encode packet fields into output buffer |
| 0051868c | AudioBufferSizeCalc | recalculate audio buffer size |

**Guard conditions:** Checks if `(*(this+0x5C) & 0x40) == 0`. If bit 0x40 is CLEAR (PASS), calls AudioBufferSizeCalc. If bit 0x40 is SET (BLOCKED), skips audio buffer recalculation and proceeds directly to PacketFieldEncoding.
