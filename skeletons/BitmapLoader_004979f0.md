## BitmapLoader_004979f0 — RegisterBitmapPathInList

**Summary:** Builds full path from base directory (dword_5EC408 or byte_5EA438) and filename `a2` via StringFormatWithBufferOverflowCheck. On validation success (ConditionalFieldClear returns 0), allocates PathRegistry entry and inserts 12-byte node into singly-linked list (head at 0xF0, next at +4, flag at +8). Increments counter at 0xFC.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4920B0 (004920b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xF0 | RW | — | Linked list head pointer |
| this | 0xF4 | RW | — | Linked list tail pointer |
| this | 0xF8 | RW | — | Secondary pointer (set to head on first insert) |
| this | 0xFC | R | — | Node count (incremented on each insert) |

**Written-by note (persistence):**
- this 0xF0: Written conditionally (only on first insert). External poke survives between inserts.
- this 0xF4: Written each insert. External poke does not survive.
- this 0xF8: Written conditionally (only on first insert). External poke survives between inserts.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | Format string "%s%s" for path construction |
| 005ea438 | byte_5EA438 | R | Default base directory path |
| 005ec408 | dword_5EC408 | R | Override base directory path pointer |
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00494fe0 | ConditionalFieldClear | Validates constructed path (returns 0 on success) |
| 00499ab0 | StructInitPathRegistry | Initializes path registry structure from filename and handle |
| 00587c03 | OperatorNewNhMallocWrapper | Allocates 12-byte node and PathRegistry memory |
| 0058815f | StringFormatWithBufferOverflowCheck | Safe string formatting for path construction |

**Guard conditions:** ConditionalFieldClear must return 0 (success) to proceed — non-zero causes immediate return 0. PathRegistry result v4 must be non-null to proceed with list insertion — null skips insert but still returns 1.
