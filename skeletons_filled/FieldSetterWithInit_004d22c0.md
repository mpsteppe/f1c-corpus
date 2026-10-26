## FieldSetterWithInit_004d22c0 — Field setter with init and dispatch

**Summary:** Initializes struct fields: zeroes byte flag at 0xC1, stores current session time at 0xB0, copies value from source at 0xB4, then dispatches via sub_42D140 using session type and source data.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B3400 (004b3400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB0 | RW | — | Timestamp field — set to current session time |
| this | 0xB4 | RW | — | Copied value — receives data from source struct a2+12 |
| this | 0xC1 | RW | 0 | Byte flag — zeroed unconditionally each call |

**Written-by note (persistence):**
- this 0xB0: Written unconditionally to current session time. External poke overwritten on next call.
- this 0xB4: Written unconditionally from a2+12. External poke overwritten on next call.
- this 0xC1: Written to 0 unconditionally. External poke overwritten on next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c569c | dword_7C569C | R | SessionType5 (5=server) — passed to sub_42D140 as dispatch target |
| 008afea0 | dbl_8AFEA0 | R | SessionTime — current time stored into this+0xB0 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — all writes are unconditional.
