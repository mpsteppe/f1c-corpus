## CollisionInvDistanceStore_0045f2a0 — CollisionInvDistanceStore

**Summary:** Stores the inverse of a float parameter (1.0 / a2) into struct field at this+4. Used for collision inverse distance calculation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionTypeSetter (00463f70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | Inverse distance float (stores 1.0 / a2) |

**Written-by note (persistence):**
- this 0x4: once per call — overwritten unconditionally with 1.0/a2; survives until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] — float threshold for contact aging overflow |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** unconditional — always writes this[1] = 1.0 / a2.
