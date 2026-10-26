## ConditionalUICleanupDispatch_005528f0 — ConditionalUICleanupDispatch

**Summary:** Conditionally dispatches UI cleanup on the font texture object. If flag bit 0x20000 at offset 0x24 is set and the pointer at offset 0x868 is non-null, calls UICleanupIterator on it.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalInitBranch (004f8f10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | Flags (bit 0x20000 = texture mode gate) |
| this | 0x868 | R | — | Pointer to font texture object (passed to UICleanupIterator) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager global |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00554d70 | UICleanupIterator | Iterates and cleans up UI elements stored in a container |

**Guard conditions:** BIT 0x20000 NOT set OR offset 0x868 is NULL: return early (no cleanup). PASS: calls UICleanupIterator(this[538]).
