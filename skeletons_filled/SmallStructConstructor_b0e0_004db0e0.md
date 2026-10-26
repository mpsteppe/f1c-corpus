## SmallStructConstructor_b0e0_004db0e0 — UIWidgetSubtypeConstructor

**Summary:** Initializes a UI widget object: sets vtable to off_5AD034, type field to 1, active flag to 1, and reserved field to 0. Small inline constructor used by the widget factory.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Direct3DObjectFactory (004daea0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer set to off_5AD034 (Vtable_UIWidgetFactory) |
| this | 0x4 | RW | 1 | Type/identifier code |
| this | 0x8 | RW | 1 | Active/visible flag |
| this | 0xC | RW | 0 | Reserved/initialized null |

**Written-by note (persistence):**
- this 0x0: Written once (vtable); fixed for object lifetime
- this 0x4: Written once to 1
- this 0x8: Written once to 1
- this 0xC: Written once to 0

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ad034 | off_5AD034 | R | Vtable_UIWidgetFactory [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — all writes unconditional.
