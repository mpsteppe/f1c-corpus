## ParserDispatchWrapper_0045c3d0 — ParserDispatchWrapper

**Summary:** Dispatches to UtilityFunction_8a60 using byte at offset 1 as selector. Returns result or zeroes output on failure. Part of particle/sound parameter parsing.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ParticleSoundEffectSpawner (004607a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1 | R | — | Selector byte passed to UtilityFunction_8a60 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00568a60 | UtilityFunction_8a60 | Generic parameter parser; returns non-zero on success |

**Guard conditions:** UtilityFunction_8a60 must return non-zero to succeed. On failure, output a3 zeroed and function returns 0.
