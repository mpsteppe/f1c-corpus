## ResourceQueryAndStoredSetup_00478320 — ResourceQueryAndStoredSetup

**Summary:** Queries game command dispatch (dword_7CD8C0) for resource ID 18, stores result pointer at this[0xE0], then triggers profile icon path update.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xE0 | RW | — | resource handle/structure pointer stored from dispatch |

**Written-by note (persistence):**
- this 0xE0: written once per call when dispatch returns non-null

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface [DERIVED] (also: ` — game command dispatch interface pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00478390 | ProfileIconPathSetter | updates profile icon file path from stored resource |

**Guard conditions:** dispatch result must be non-null (skip store + path update if null)
