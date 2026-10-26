## FlagSetterWithGlobalUpdate_004a1da0 — FlagSetterWithGlobalUpdate

**Summary:** Sets a byte flag at offset 0x10 of an object and synchronizes a global pointer. When flag is non-zero, stores object address in SessionCatchupFlag; when zero, clears the global.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlayerOptionsInitializer (004aa270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | — | boolean flag field for session catchup state |

**Written-by note (persistence):**
- this 0x10: written unconditionally to the caller-provided a3 value; persists as object state

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ce2e8 | dword_7CE2E8 | W | SessionCatchupFlag [DERIVED] (also: ` — conditional flag) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always writes the byte at offset 0x10. If a3 is non-zero, sets global to object pointer; if zero, sets global to NULL.
