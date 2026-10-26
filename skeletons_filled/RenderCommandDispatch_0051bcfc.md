## RenderCommandDispatch_0051bcfc — RenderCommandDispatch

**Summary:** Processes a render data chunk through a processing function, writes output to destination buffer, and returns count of items processed.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x188) | 0xC | R | — | source data identifier passed to processing function |
| *(this+0x188) | 0x10 | R | — | maximum items to process per call (clamp value) |
| *(this+0x19C) | 0x4 | R | — | processing function vtable entry (does transform/copy) |
| *(this+0x1A4) | 0x4 | R | — | output function vtable entry (writes processed data) |
| this | 0x188 | R | — | pointer to render state struct |
| this | 0x19C | R | — | vtable pointer for processing function |
| this | 0x1A4 | R | — | vtable pointer for output function |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Clamps request count (a7 - *a6) to max *(state+0x10). No early-exit guards; always calls processing and output functions with clamped count.
