## VTableDispatchWithConditionalCreation_0046fdc0 — ObjectLookupAndNameMatch

**Summary:** Creates/looks up an object via dispatch interface vtable call (offset 28, arg 12). If object exists, compares its name with `this` parameter. Always returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface [DERIVED] — dispatch interface used to create/look up object by type 12 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00477280 | ObjectNameComparison | compare created object's name with `this` parameter |
| 0048fec0 | ShortComputation_fec0 | preliminary setup/computation |
| 00490160 | BooleanFlagSetterVirtualCall | set boolean flag to 0 (false) |

**Guard conditions:** Return value from dispatch interface (v2) checked for null before calling ObjectNameComparison. If null, name comparison is skipped.
