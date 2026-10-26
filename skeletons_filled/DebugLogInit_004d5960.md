## DebugLogInit_004d5960 — DebugLogOutputInitializer

**Summary:** Initializes the debug logging subsystem. Writes a null byte via sub_4D5BE0, conditionally sets global debug mode constants based on dword_5C753C(), processes a double constant via sub_447F30, stores a float result in this[2], then writes 228 bytes of data via sub_4D5BE0.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MainGameTickUpdate (0042c690)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | debug log float state field, set from processed output |

**Written-by note (persistence):**
- this 0x8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00447f30 | sub_447F30 | processes a double constant into float array for debug setup |
| 004d5be0 | sub_4D5BE0 | debug data writer/encoder (shift register + file I/O) |

**Guard conditions:** None; always writes initialization data unconditionally.
