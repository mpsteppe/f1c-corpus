## GraphicsConfigStateSetter_005408f0 — Graphics configuration state setter (0/1/2)

**Summary:** Sets two state fields at 0x13DC-0x13E0 based on mode parameter: 0→both 0, 1→both 1, 2→0x13E0=2 and 0x13DC=1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VidMan_Enter (004fa000)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x13DC | RW | 0 | state field 1 (this[1271]) — 0/1 based on mode |
| this | 0x13E0 | RW | 0 | state field 2 (this[1272]) — 0/1/2 based on mode |

**Written-by note (persistence):**
- this 0x13DC: set to 0/1 based on mode parameter — persists until next call
- this 0x13E0: set to 0/1/2 based on mode parameter — persists until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 == 0 → both 0; a2 == 1 → both 1; a2 == 2 → 0x13E0=2, 0x13DC=1. Other values unchanged.
