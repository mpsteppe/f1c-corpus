## LineReaderFromBuffer_00559a70 — ReadLineFromInputBuffer

**Summary:** Reads one line from a buffer into internal line buffer, copying bytes until newline (0x0A) or buffer exhaustion. Part of scene file line-by-line reader system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_55A060 (0055a060), sub_55A500 (0055a500), sub_55A790 (0055a790), SceneNode (0055a910), SceneFileTopLevelParser (0055b200), sub_55B8C0 (0055b8c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 3 | Line reader status code (3 = buffer exhausted) |
| this | 0x4 | RW | — | Current read offset/position in buffer |
| this | 0x8 | R | — | Total buffer size (end bound) |
| this | 0x310 | R | — | Pointer to buffer data base (offset into raw data) |

**Written-by note (persistence):**
- this 0x0: set to 3 when buffer exhausted; otherwise returns existing status after line read. Conditional — set only on end-of-buffer.
- this 0x4: incremented after each byte read. Survives external poke (acts as cursor).

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00559ad0 | sub_559AD0 | Post-process parsed line (trim, tokenize key=value pairs) |

**Guard conditions:** Loop reads bytes while `this[1] < this[2]` (position < size). PASSES: bytes copied to line buffer until newline (0x0A) hit. BLOCKED: buffer exhaustion sets status to 3 and breaks loop; newline terminates read with goto.
