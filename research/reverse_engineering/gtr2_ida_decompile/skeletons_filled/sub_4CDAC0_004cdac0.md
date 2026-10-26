## sub_4CDAC0_004cdac0 — state reset helper (states 2/3 → 0)

**Summary:** Small `__thiscall` reset routine: if the state index this[0x84] is 2 or 3 it issues a transition to state 0 through virtual slot +0x2C; regardless of state it then clears the dword at this+0x108 and returns 0.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal + value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | Vtable slot +0x2C; transition setter invoked as (this, 0) when the state is 2 or 3 |
| this | 0x0 | R | — | Vtable pointer of the object, used to resolve the call at +0x2C |
| this | 0x84 | R | — | State index (this[33]); only 2 and 3 trigger the transition |
| this | 0x108 | RW | 0 | Dword (this[66]) cleared to 0 on every call (state/result field reset) |

**Written-by note (persistence):**
- this 0x108: Written to 0 unconditionally on every call (in both the state-3 early path and the common tail); an external poke is erased by the next invocation.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x84 | == | 3 | State index; matches the second branch (transition to 0, then reset and return 0) |
| this | 0x84 | == | 2 | State index; matches the first branch (transition to 0, then reset and return 0) |

**Guard interpretation:** The virtual transition to state 0 PASSES only when this[0x84] is exactly 2 or 3. Any other state (0, 1, 4, …) BLOCKS the transition — only this+0x108 is cleared. All paths end with this[0x108] = 0 and a 0 return.
