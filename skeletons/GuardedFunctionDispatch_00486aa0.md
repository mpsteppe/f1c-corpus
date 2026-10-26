## GuardedFunctionDispatch_00486aa0 — GuardedDispatchTableAccess

**Summary:** Checks guard flag at this+0x40; if set, forwards to LookupDispatch with sentinel -1; otherwise returns -1 immediately. Part of guarded function dispatch system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameMode (0046d6d0), sub_46FC30 (0046fc30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x40 | R | — | guard flag — enables dispatch when non-zero |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00497940 | LookupDispatch | perform dispatch lookup with sentinel -1 |

**Guard conditions:** If this[16] (offset 0x40) is zero → return -1 (blocked, no dispatch). If non-zero → pass to LookupDispatch(a2, -1).
