## UISliderConstructor_00479690 — UISliderConstructor

**Summary:** UI slider constructor: calls VTableSetInit with default float value (0.8 = 1061997773) for initial slider position, overrides vtable to off_5A4B90.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_5A4B90 | vtable pointer for UI slider type |

**Written-by note (persistence):**
- this 0x0: once per call, set to off_5A4B90 (vtable init, overrides VTableSetInit)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a4b90 | off_5A4B90 | R | vtable pointer assigned to UI slider object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004795e0 | VTableSetInit | base UI component constructor with default params (0, 0.8f) |

**Guard conditions:** none (no branches — unconditional initialization)
