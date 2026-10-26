## CounterIncrementDecrementByFlag_00587230 — Increment or decrement byte counter at offset 0x19

**Summary:** Adjusts byte counter at offset 0x19: if `a2` is non-zero, increments; otherwise decrements (but only if current value > 0). Returns the value before modification.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MutexCallbackDispatch (0057e3a0), sub_580DE0 (00580de0), NetworkFileTransferAcceptHandler (0058119a), sub_5813E0 (005813e0), NetworkBufferSearch (00581600), sub_585870 (00585870)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x19 | RW | — | Byte counter: incremented (a2 != 0) or decremented (a2 == 0, value > 0) |

**Written-by note (persistence):**
- this 0x19: modified conditionally each call; external poke overwrites it

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** `a2` flag selects operation. If a2 == 0 and current value is 0, decrement is skipped (value stays 0). No upper bound protection on increment.
