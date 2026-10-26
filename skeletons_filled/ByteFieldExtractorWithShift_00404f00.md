## ByteFieldExtractorWithShift_00404f00 — Indirect byte field reader

**Summary:** Reads a single byte from offset 0x14 of a target structure accessed via an indirect pointer stored at `this+0x0`. A simple indirection helper for retrieving a flag or status byte from a referenced object.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ConditionalFlagReturn (00404f10), SessionMenuModeSwitch (004a0c60), RestartGate (004a0fd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x14 | R | — | target byte field within the dereferenced structure (flag/status) |
| this | 0x0 | R | — | pointer to target structure (dereferenced to access obj) |

**Globals referenced:** none

**Functions called:** none

**Guard conditions:** None — no conditional checks; always dereferences and returns the byte.
