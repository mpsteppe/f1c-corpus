## ConditionalNetworkSystemDispatch_00461f90 — ConditionalNetworkDispatch

**Summary:** Queries network capability and sets flag on network system pointer if capable and non-null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x1B79C | R | — | Network system pointer (checked non-null before use) |
| this | 0x0 | R | — | This pointer dereference |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00563e70 | sub_563E70 | Query if network/system is capable of initialization |

**Guard conditions:** Blocked when network system pointer (this+0x1B79C) is null. Further blocked when sub_563E70 returns 0 (network not capable).
