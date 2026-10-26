## VirtualFactoryStore_00478090 — Cache virtual factory object from global dispatch

**Summary:** Retrieves a virtual factory/interface object (ID 20) from the global game command dispatch interface and caches it in instance field at offset 0xE0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xE0 | RW | — | cached virtual factory / interface object reference |

**Written-by note (persistence):**
- this 0xE0: written once when dispatch returns non-null; survives as cached reference

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd8c0 | dword_7CD8C0 | R | game command dispatch interface pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If dispatch returns null for ID 20, skip write (field retains prior value). No other guard.
