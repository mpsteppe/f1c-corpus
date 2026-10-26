## ScrollProgressHandler_0048d4b0 — ScrollProgressHandler

**Summary:** Calculates and updates scroll bar thumb position for a UI scroll area. Computes progress ratio from current scroll value vs range, converts to pixel position, and triggers redraw if the thumb position changed.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x18 | R | — | Vtable offset 24 — method to get scroll value from source object |
| obj | 0x20 | R | — | Vtable offset 32 — method to get area/container size |
| obj | 0x2C | R | — | Vtable offset 44 — method to signal content changed |
| obj | 0xB0 | R | — | Vtable offset 176 — refresh/update method |
| obj | 0xB4 | R | — | Vtable offset 180 — method to get mutable scroll value pointer |
| this | 0x0 | R | — | Vtable pointer of the scroll area |
| this | 0xE0 | RW | — | Current thumb pixel position (updated when changed) |
| this | 0xF0 | R | — | Byte flag: 0 = float scroll range, non-zero = int scroll range |
| this | 0xF4 | R | — | Scroll range min (this[61] as float) |
| this | 0xF8 | R | — | Scroll range max (this[62] as float) |

**Written-by note (persistence):**
- this 0xE0: conditionally set when thumb position changes; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00488970 | ShortComputation_8970 | Post-update computation / validation |
| 00587bdc | CRTFtol | Float-to-int conversion for pixel position |

**Guard conditions:** PASS: scroll range > 0 AND source object exists (non-null v2). BLOCKED: range <= 0 or source object null → thumb reset to 0, signal change via vtable+56.
