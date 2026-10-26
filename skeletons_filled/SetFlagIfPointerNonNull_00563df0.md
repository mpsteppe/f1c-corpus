## SetFlagIfPointerNonNull_00563df0 — SetRunningFlagIfInitialized

**Summary:** Checks if the object at this+0x0 is non-null (already initialized). If so, sets this+0x74 (running/active flag) to 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StartNetworkUpdate (00461de0), sub_563410 (00563410)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | pointer to sub-object; non-null indicates initialized state |
| this | 0x74 | RW | 1 | running/active flag; set to 1 when this+0x0 is non-null |

**Written-by note (persistence):**
- this 0x74: set to 1 conditionally when *this is non-null. Once set, persists until explicitly cleared.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** *this (offset 0x0) non-null → set this+0x74 to 1. If *this is null, do nothing.

