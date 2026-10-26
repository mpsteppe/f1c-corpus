## InputDispatch_0048d590 — ListNavigationInputDispatch

**Summary:** Processes a set of input codes (short array) for UI list navigation. Handles code 203 (scroll up/previous) and code 205 (scroll down/next) by incrementing or decrementing the selected index, clamping via a virtual bounds check, and signaling a change.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | Vtable offset 44 — signal content/index changed |
| obj | 0xA4 | R | — | Vtable offset 164 — post-update/reindex callback |
| obj | 0xB4 | R | — | Vtable offset 180 — get mutable pointer to selected index for clamping |
| this | 0x0 | R | — | Vtable pointer |
| this | 0xE0 | R | — | Current selected index (this[56]), read/incremented/decremented |
| this | 0xF0 | R | — | Byte flag: 0 = int mode, non-zero = ptr mode for index storage |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00488970 | ShortComputation_8970 | Post-update computation after index change |

**Guard conditions:** PASS: a4 > 0 (input codes count). Iterates codes. Code 203: decrement index (with bounds clamp). Code 205: increment index (with bounds clamp). BLOCKED: a4 <= 0 → return 0 immediately.
