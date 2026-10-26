## ViewportRectSizeCalc_0048fdb0 — ViewportRectSizeCalc

**Summary:** Calculates viewport rectangle dimensions from a bounding box and stores them into the this-struct. Part of a UI layout system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ObjectNameComparison (00477280)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | — | Viewport width (computed from a2 right - left + 1, clamped to 0) |
| this | 0x10 | RW | 0 | Viewport height (computed from a2 bottom - top + 1, clamped to 0) |
| this | 0x30 | RW | — | Pointer to source bounding box (a2) |

**Written-by note (persistence):**
- this 0xC: Once — computed from bounding box; overwritten on next call.
- this 0x10: Once — computed each call; overwritten on next call.
- this 0x30: Once — set to a2 pointer; overwritten on next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks `a2` for null — BLOCKED (no fields written, returns 0) if null. PASSES when non-null: width computed from `a2[4] - a2[3]`, clamped to 0 if negative, stored as `(diff + 1)`. Height computed from `a2[2] - a2[1]`, clamped to 0 if zero/negative, stored as `(diff + 1)`.
