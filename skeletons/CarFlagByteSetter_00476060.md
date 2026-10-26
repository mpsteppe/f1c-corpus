## CarFlagByteSetter_00476060 — CarStateFlagByteSetter

**Summary:** Sets a byte flag at offset 0x2C of a car object to the specified value and returns the same value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2C | RW | — | Car state/flag byte (setter) |

**Written-by note (persistence):**
- this 0x2C: set unconditionally each call; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guards — always executes fully.
