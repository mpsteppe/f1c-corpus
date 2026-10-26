## sub_44EDD0_0044edd0 — CollectAudioSourceEntry

**Summary:** If flag bit 0 at struct offset 0x1C (field at a1+28) is set, stores the value at offset 0x18 into audio source array dword_7CC9CC[dword_7CD07C] and increments counter. Returns whether counter < 8 (buffer not full).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | R | — | Audio source identifier to store if flag set |
| this | 0x1C | R | — | Flag byte (bit 0) controlling whether source is collected |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cc9cc | dword_7CC9CC | W | CollisionAudioSource [DERIVED] |
| 007cd07c | dword_7CD07C | RW | Dword_Unknown_Render [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Bit 0 of byte at (a1+28) must be set to PASS (store source and advance). If clear, entry is BLOCKED/skipped. Return value also tests counter < 8 (buffer full gate).
