## StateReset_005115c4 — JPEG decoder state reset

**Summary:** Resets all JPEG decoder state fields to zero: slot table pointer, command counter, current marker, byte-stuffing flag, control flag, and byte counter. Prepares the context for a fresh decode session.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5115EE (005115ee)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x190) | 0x50 | RW | 0 | byte-stuffing mode flag — reset to 0 (raw mode) |
| *(this+0x190) | 0x51 | RW | 0 | control flag byte — reset to 0 |
| this | 0x7C | RW | 0 | command counter — reset to 0 |
| this | 0xC4 | RW | 0 | slot lookup table pointer — reset to 0 (null) |
| this | 0x178 | RW | 0 | current marker byte — reset to 0 (triggers marker read) |
| this | 0x190 | R | — | pointer to sub-object with flags and counter |
| this | 0x1E8 | RW | 0 | byte counter — reset to 0 |

**Written-by note (persistence):**
- *(this+0x190) 0x50: reset to 0 unconditionally
- *(this+0x190) 0x51: reset to 0 unconditionally
- this 0x7C: reset to 0 unconditionally
- this 0xC4: reset to 0 unconditionally
- this 0x178: reset to 0 unconditionally
- this 0x1E8: reset to 0 unconditionally

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No conditional guards — all fields are unconditionally reset to 0.
