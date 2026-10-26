## BinkVideoClose_00551ce0 — BinkVideoClose

**Summary:** Closes a Bink video handle by calling BinkClose on field at this+0x0. Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalFreeWithBinkClose (00551f80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Bink handle (HBINK) to close |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e338 | _BinkClose@4 | R | Bink API function to close/open handle |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard. Always calls BinkClose with field value. Assumes this[0] is a valid Bink handle or NULL (BinkClose handles NULL safely).
