## StateDependentVirtualDispatch_004780d0 — Conditionally cache factory interface based on session state

**Summary:** Checks current session state; if in-game (state 3), caches interface ID 23, otherwise caches ID 21 from global dispatch interface into field at offset 0xE0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xE0 | RW | — | cached factory/interface object reference |

**Written-by note (persistence):**
- this 0xE0: written conditionally; persists as cached reference

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd25c | dword_7CD25C | R | game module manager |
| 007cd8c0 | dword_7CD8C0 | R | game command dispatch interface pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461cd0 | SessionStateCheck | return current session state (3 = in-game) |

**Guard conditions:** SessionStateCheck result == 3 → dispatch ID 23; else dispatch ID 21. If dispatch returns null, skip write (field unchanged).
