## TripleVirtualCall_004db520 — UIInitializationSequence

**Summary:** Calls two virtual methods (vtable+0x1C with arg 0, vtable+0x20 with arg 1000) followed by UILayoutDispatchWithDataPrep(640). Resets and initializes UI layout at 640px width.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x1C | R | — | Virtual method at vtable+0x1C, called with arg 0 (likely reset/clear) |
| obj | 0x20 | R | — | Virtual method at vtable+0x20, called with arg 1000 (likely initial setup) |
| this | 0x0 | R | — | Vtable pointer for virtual dispatch |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004db550 | UILayoutDispatchWithDataPrep | Sets up UI layout with width parameter 640 |

**Guard conditions:** None — all calls unconditional.
