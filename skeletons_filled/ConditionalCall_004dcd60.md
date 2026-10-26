## ConditionalCall_004dcd60 — Guarded dispatch with device fallback

**Summary:** If the object's first field (*this) is non-null, dispatches to a render/setup function using the provided device pointer (or dword_8B8DC8 fallback if null).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UICursorSelectionRectangleRenderWithInterpolatio (0045b660), F_2DTextRenderingWithScissorRectangle (0049b370), ShortComputation_f070 (0049f070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Enable/guard field: if non-null, dispatch proceeds |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8dc8 | dword_8B8DC8 | R | RenderDevicePtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks `*this` (offset 0x0) for non-null. PASSES (dispatches) when non-null. BLOCKED (no-op) when null. Inside pass path, if `a2` (device ptr) is null, substitutes `dword_8B8DC8` (RenderDevicePtr).
