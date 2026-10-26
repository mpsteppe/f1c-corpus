## UtilityFunction_4bb0_00464bb0 — Accumulator with threshold check

**Summary:** Adds a2 to accumulator at this[26], stores result, returns true if accumulator >= a3.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** EntityVisibilityGridManager (00465460)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x68 | RW | — | Accumulator float value (this[26]); incremented then compared |

**Written-by note (persistence):**
- this 0x68: overwritten every call with new accumulated value

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always adds a2 and returns comparison result.
