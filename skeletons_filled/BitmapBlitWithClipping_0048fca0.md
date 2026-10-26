## BitmapBlitWithClipping_0048fca0 — BlitClipped

**Summary:** Performs bitmap blit with source/destination rectangle clipping for a UI rendering system. Reads source bitmap data and destination bounds from this-context, clips source offset and dimensions against destination boundaries, then dispatches to final blit function.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x44) | 0x1C | R | — | Source bitmap width |
| *(this+0x44) | 0x20 | R | — | Source bitmap height |
| this | 0x1C | R | — | Destination clip top boundary |
| this | 0x20 | R | — | Destination clip bottom/height boundary |
| this | 0x24 | R | — | Destination clip left boundary |
| this | 0x28 | R | — | Destination clip right/width boundary |
| this | 0x38 | R | — | Pointer to source bitmap context structure |
| this | 0x44 | R | — | Pointer to source bitmap dimensions |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00494a30 | F_10ParamForwarder | Performs final blit with source/dest rect parameters |
| 00495150 | GlobalAccessor_5150 | Retrieves global rendering context state from unk_7CDE00 |

**Guard conditions:** Checks `this[14]` (offset 0x38) for null — BLOCKED (returns early) if null. Checks loaded pointer at `*(this[14]+12)` for null — BLOCKED if null. Then clips source x against `this[9]` (offset 0x24), source y against `this[7]` (offset 0x1C), clamps width against `this[10]` (offset 0x28), clamps height against `this[8]` (offset 0x20). All clipping is done with conditional assignments before final blit call.
