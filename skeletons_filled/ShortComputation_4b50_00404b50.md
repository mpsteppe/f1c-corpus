## ShortComputation_4b50_00404b50 — ObjectFlagsZeroInit

**Summary:** Zero-initializes three fields (offsets 0x14, 0x15, 0x1C) on an object obtained by dereferencing the this pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Options_Setup (004a0eb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x14 | RW | 0 | byte flag zeroed on init |
| obj | 0x15 | RW | 0 | byte flag zeroed on init |
| obj | 0x1C | RW | 0 | dword field zeroed on init |
| this | 0x0 | R | — | pointer to the target object to zero-init |

**Written-by note (persistence):**
- obj 0x14: zeroed once per call; external poke survives until next call
- obj 0x15: zeroed once per call; external poke survives until next call
- obj 0x1C: zeroed once per call; external poke survives until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none unconditional writes, no branches.
