## ArrayFill5_0054eec1 — 5-element integer array fill

**Summary:** Fills 5 consecutive DWORD slots at a given pointer with the same integer value. A utility function for small array/struct initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | First array element set to a2 |
| this | 0x4 | RW | — | Second array element set to a2 |
| this | 0x8 | RW | — | Third array element set to a2 |
| this | 0xC | RW | — | Fourth array element set to a2 |
| this | 0x10 | RW | — | Fifth array element set to a2 |

**Written-by note (persistence):**
- this 0x0-0x10: unconditionally overwritten each call; survives until next call or external modification

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — unconditionally writes to all 5 slots.
