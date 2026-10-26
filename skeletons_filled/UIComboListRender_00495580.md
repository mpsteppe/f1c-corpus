## UIComboListRender_00495580 — ComboBoxItemRender

**Summary:** Renders a combo box / dropdown list item with text label and background fill. Reads driver/device name string, renders it to a surface, computes centered position clamped to 800x600, and draws a background rect (animated scale or full size). Part of the UI widget rendering system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_496E90 (00496e90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x156C)+0x0) | 0x8 | R | — | Virtual method call (slot 2) on the device/current-object pointer — likely layout/position callback |
| *(this+0x156C) | 0x0 | R | — | Vtable pointer of the object at this+0x156C (used for virtual dispatch) |
| *(this+0x156C) | 0xC0 | R | — | String pointer (const char*) at offset 192 of the current object — label/display text |
| this | 0x5C | R | — | Base X position (used for centering calculation) |
| this | 0xCC | R | — | Float: current animation/scroll progress value |
| this | 0xD0 | R | — | Float: threshold/offset for progress comparison |
| this | 0xD4 | R | — | Float: smoothing step or animation duration factor |
| this | 0x156C | R | — | Pointer to current object (driver/device info struct) with display name and vtable |
| this | 0x1570 | RW | 0 | Last-seen pointer value from 0x156C (tracked for change detection) |
| this | 0x1588 | R | — | BYTE enable flag — must be non-zero to render |
| this | 0x158C | RW | — | Computed X position of rendered area (clamped to [0, 800 - width]) |
| this | 0x1590 | RW | — | Computed Y position of rendered area (clamped to [0, 600 - height]) |

**Written-by note (persistence):**
- this 0x1570: updated to current 0x156C pointer on change; reset to 0 on early-exit (guard fail)
- this 0x158C: recomputed and clamped every frame when pointer at 0x156C changes; survives external poke
- this 0x1590: recomputed and clamped every frame when pointer at 0x156C changes; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac9c0 | flt_5AC9C0 | R | Epsilon constant (0x33800000 ≈ 1.192e-7) used for float comparison threshold |
| 005ea438 | byte_5EA438 | R | Default application directory path string — fallback when device object has no custom name |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00490920 | Accessor | Retrieve render device/surface accessor for fill operation |
| 004918d0 | RenderSurfaceFillCopy | Fill background rectangle on render surface |
| 00497ec0 | DriverNameStringHandler | Format/process driver or device name string into render buffer |
| 004983b0 | TextRenderToSurface | Render display text to offscreen surface, returning dimensions |
| 00498550 | ShortComputation_8550 | Compute short label or numeric value when no driver name needs formatting |
| 00498560 | sub_498560 | Prepare/clear render surface at given offset for text |
| 00587bdc | CRTFtol | Convert float to integer (used for size/position rounding) |

**Guard conditions:** All three must PASS: (1) byte at 0x1588 ≠ 0, (2) float at 0xCC ≥ float at 0xD0 (progress threshold met), (3) pointer at 0x156C ≠ NULL. When any fails → BLOCKED: set 0x1570 = 0 and return. Inner guard: string at *(0x156C)+0xC0 must be non-empty (or fallback byte_5EA438 non-empty) to proceed with text rendering and background fill.
