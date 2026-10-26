## ObjectFieldInitializer_004fc901 — InitThreeFloatFields

**Summary:** Initializes three fields of an object: first (offset 0xC) set from ECX parameter, next two (offsets 0x10, 0x14) set to 20.0f.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | — | field set from ECX parameter |
| this | 0x10 | RW | 1101004800 → 20.0f | initialization value (20.0f) |
| this | 0x14 | RW | 1101004800 → 20.0f | initialization value (20.0f) |

**Written-by note (persistence):**
- this 0xC: always — set from ECX on every call; external poke survives until next call
- this 0x10: always — set to 20.0f on every call; external poke survives until next call
- this 0x14: always — set to 20.0f on every call; external poke survives until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional writes.
