## UIClickHandlerWithBoundsCheck_0046b070 — UIClickHandlerWithBoundsCheck

**Summary:** UI click handler for key binding. Resets screen mode setting (dword_7CFF84 = 0), reads dual-field value, checks against two bounds obtained via vtable methods at offsets +24 and +32. If value is within both bounds, triggers KeyBindingUIPressKeyOrController.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x18 | R | — | vtable method at offset +24 — first bound getter |
| obj | 0x20 | R | — | vtable method at offset +32 — second bound getter |
| this | 0x0 | R | — | vtable pointer, used to dispatch bound methods |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cff84 | dword_7CFF84 | W | ScreenModeSetting [DERIVED] — reset to 0 on click |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0046b0c0 | KeyBindingUIPressKeyOrController | opens key/controller binding UI when within bounds |
| 00498880 | DualFieldRead | reads dual-field values for boundary comparison |

**Guard conditions:** v5 < first bound (vtable+24) → enters inner check. v5 < second bound (vtable+32) → calls binding UI. BLOCKED if either check fails.
