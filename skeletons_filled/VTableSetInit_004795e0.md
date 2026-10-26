## VTableSetInit_004795e0 — VTableSetInit

**Summary:** UI constructor helper: calls UIConstructorWithVTableParams then sets vtable pointer to off_5A4AD8.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UISliderConstructor (00479690), ObjectInit (004796c0), sub_479700 (00479700)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_5A4AD8 | vtable pointer for UI component type |

**Written-by note (persistence):**
- this 0x0: once per call, set to off_5A4AD8 (vtable init)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a4ad8 | off_5A4AD8 | R | vtable pointer assigned to UI component object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048d3a0 | UIConstructorWithVTableParams | base UI component constructor with parameters |

**Guard conditions:** none (no branches — unconditional initialization)
