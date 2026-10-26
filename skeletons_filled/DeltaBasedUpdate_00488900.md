## DeltaBasedUpdate_00488900 — DeltaBasedPositionUpdate

**Summary:** Reads position delta from DualFieldRead, compares to stored value at 0xE0; if changed and flag at 0xED is set, updates stored delta, calls ShortComputation_8970 to recompute layout, then invokes virtual method at +44 (notify change).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIScrollWidgetUpdate (00488a30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x18 | R | — | Virtual method +24 return value — current position/size |
| obj | 0x1C | R | — | Virtual method +28 return value — related size/bound |
| obj | 0x24 | R | — | Virtual method +36 return value — another bound |
| obj | 0x2C | R | — | DualFieldRead output — external delta source |
| this | 0x0 | R | — | Vtable pointer for virtual dispatch |
| this | 0xE0 | RW | — | Stored delta/scroll offset value |
| this | 0xED | R | — | Flag controlling whether delta update executes |

**Written-by note (persistence):**
- this 0xE0: Written conditionally — only when 0xED is set AND delta differs from current value. Survives between calls.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00488970 | ShortComputation_8970 | Recompute scroll/content layout after delta change |
| 00498880 | DualFieldRead | Read two-field pair (position/delta input) |

**Guard conditions:** Checks byte at 0xED (this[237]); if zero (false), skips entire delta-update body and returns early.
