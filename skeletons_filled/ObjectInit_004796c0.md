## ObjectInit_004796c0 — ObjectInit

**Summary:** UI object constructor: calls VTableSetInit with default float value (0.2 = 1045220557), overrides vtable to off_5A4C48.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_5A4C48 | vtable pointer for UI object type |

**Written-by note (persistence):**
- this 0x0: once per call, set to off_5A4C48 (vtable init, overrides VTableSetInit)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a4c48 | off_5A4C48 | R | vtable pointer assigned to UI object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004795e0 | VTableSetInit | base UI component constructor with default params (0, 0.2f) |

**Guard conditions:** none (no branches — unconditional initialization)
