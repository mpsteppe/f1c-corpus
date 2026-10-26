## UIDimensionCapture_0048ebd0 — UI Element Dimension Measurement & Layout

**Summary:** Captures and computes UI element dimensions (position/size) by querying child widgets via indexed accessors and applying fallback defaults. Part of the UI layout system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SubCallFieldZero (00477080), GameFilterSetup (00477830), ProfileBitmapBrowser (00477cb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x40 | R | — | child object pointer, traversed by ConditionalDelegation_6460 to reach nested widget |
| this | 0x0 | R | — | vtable pointer; used for virtual method dispatch at offset 64 |
| this | 0x4 | R | — | default dimension 1 (used as fallback when computed width < 0) |
| this | 0x8 | R | — | default dimension 2 (used as fallback when computed width < 0) |
| this | 0xC | R | — | default dimension 3 (used as fallback when computed height < 0) |
| this | 0x10 | R | — | default dimension 4 (used as fallback when computed height < 0) |
| this | 0xE4 | RW | — | computed sub-widget dimension from ConditionalDelegation_6460 (delegate index 6) |
| this | 0xE8 | RW | — | computed sub-widget dimension from ConditionalDelegation_6460 (delegate index 7) |
| this | 0xEC | RW | — | computed sub-widget dimension from ConditionalDelegation_6460 (delegate index 5) |
| this | 0x104 | R | — | parameter passed to virtual method call (vtable[16]); context value for layout computation |
| this | 0x110 | RW | — | dimension value from sub_487060(child index 0); element 0 of 8-int array |
| this | 0x114 | RW | — | dimension value from sub_487060(child index 1); element 1 of 8-int array |
| this | 0x118 | RW | — | dimension value from sub_487060(child index 2); element 2 of 8-int array |
| this | 0x11C | RW | — | dimension value from sub_487060(child index 3); element 3 of 8-int array |
| this | 0x120 | RW | — | dimension value from sub_487060(child index 4); element 4 of 8-int array; guarded (<0 check) |
| this | 0x124 | RW | — | dimension value from sub_487060(child index 5); element 5 of 8-int array; guarded (<0 check) |
| this | 0x128 | RW | — | dimension value from sub_487060(child index 6); element 6 of 8-int array |
| this | 0x12C | RW | — | dimension value from sub_487060(child index 7); element 7 of 8-int array |
| this | 0x130 | RW | — | dimension value from sub_4870E0(child index 0); element 0 of 8-int array |
| this | 0x134 | RW | — | dimension value from sub_4870E0(child index 1); element 1 of 8-int array |
| this | 0x138 | RW | — | dimension value from sub_4870E0(child index 2); element 2 of 8-int array |
| this | 0x13C | RW | — | dimension value from sub_4870E0(child index 3); element 3 of 8-int array |
| this | 0x140 | RW | — | dimension value from sub_4870E0(child index 4); element 4 of 8-int array; guarded (<0 check) |
| this | 0x144 | RW | — | dimension value from sub_4870E0(child index 5); element 5 of 8-int array; guarded (<0 check) |
| this | 0x148 | RW | — | dimension value from sub_4870E0(child index 6); element 6 of 8-int array |
| this | 0x14C | RW | — | dimension value from sub_4870E0(child index 7); element 7 of 8-int array |
| this | 0x168 | RW | 0 | layout-state flag; explicitly zeroed after text setup |
| this | 0x174 | RW | 0 | layout-initialization flag; explicitly zeroed early in the function |

**Written-by note (persistence):**
- this 0xE4: written once, survives — overwritten each call by ConditionalDelegation_6460
- this 0xE8: written once, survives — overwritten each call by ConditionalDelegation_6460
- this 0xEC: written once, survives — overwritten each call by ConditionalDelegation_6460
- this 0x110: written once, survives — overwritten each call by sub_487060
- this 0x114: written once, survives — overwritten each call by sub_487060
- this 0x118: written once, survives — overwritten each call by sub_487060
- this 0x11C: written once, survives — overwritten each call by sub_487060
- this 0x120: written once, survives — overwritten each call by sub_487060; may be overwritten by fallback default if <0
- this 0x124: written once, survives — overwritten each call by sub_487060; may be overwritten by fallback default if <0
- this 0x128: written once, survives — overwritten each call by sub_487060
- this 0x12C: written once, survives — overwritten each call by sub_487060
- this 0x130: written once, survives — overwritten each call by sub_4870E0
- this 0x134: written once, survives — overwritten each call by sub_4870E0
- this 0x138: written once, survives — overwritten each call by sub_4870E0
- this 0x13C: written once, survives — overwritten each call by sub_4870E0
- this 0x140: written once, survives — overwritten each call by sub_4870E0; may be overwritten by fallback default if <0
- this 0x144: written once, survives — overwritten each call by sub_4870E0; may be overwritten by fallback default if <0
- this 0x148: written once, survives — overwritten each call by sub_4870E0
- this 0x14C: written once, survives — overwritten each call by sub_4870E0
- this 0x168: written once (set to 0) — survives until next call
- this 0x174: written once (set to 0) — survives until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | default application directory path; copied into string buffer for text setup |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486460 | ConditionalDelegation_6460 | traverses delegate chain to retrieve sub-widget dimension value from nested object at obj+0x40 |
| 00487060 | sub_487060 | queries first axis (e.g. width/left) dimension of child widget by index 0-7 |
| 004870e0 | sub_4870E0 | queries second axis (e.g. height/top) dimension of child widget by index 0-7 |
| 0048f9f0 | UIWindowTextSetup | initializes text/label rendering state for this UI element |
| 00566650 | StringCopyWithBufferRealloc | copies the application directory path string into a managed string buffer |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x120 | < | 0 | sub_487060 result for child index 4; negative means unset |
| this | 0x124 | < | 0 | sub_487060 result for child index 5; negative means unset |
| this | 0x140 | < | 0 | sub_4870E0 result for child index 4; negative means unset |
| this | 0x144 | < | 0 | sub_4870E0 result for child index 5; negative means unset |

**Guard interpretation:** Each guard checks if a queried child dimension is negative (unset/missing). If so, the value is replaced with a default dimension from this+0x4/this+0x8/this+0xC/this+0x10. PASSES: dimension is negative → fallback applied. BLOCKED: dimension >= 0 → queried value used as-is.
