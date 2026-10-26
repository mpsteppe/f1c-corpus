## sub_48BEB0_0048beb0 — clear flag bytes at this+0x11C and this+0x11D

**Summary:** Writes 0 to the two consecutive byte flags at this+0x11C and this+0x11D and returns 0. Counterpart of sub_48BEA0; likely disables a boolean state/mode flag pair.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x11C | RW | 0 | Primary flag byte cleared to 0 (disabled state) |
| this | 0x11D | RW | 0 | Second flag byte cleared to 0 alongside the primary |

**Written-by note (persistence):**
- this 0x11C: written unconditionally to 0 on each call — an external poke set to 1 survives until this clear runs again.
- this 0x11D: written unconditionally to 0 on each call — external pokes overwritten whenever the routine runs.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None. Always writes both zeros and returns 0.
