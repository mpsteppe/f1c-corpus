## UtilityFunction_e360_0048e360 — FontResourceDestructor

**Summary:** Destructor for a font resource object. Resets vtable to off_5AC490, conditionally frees a Bink video resource at this+0xE4 via ConditionalFreeWithBinkClose, frees a secondary allocation at this+0xFC via FreeWrapper_7bcf, then calls InitWithVTableCleanup for base teardown.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer, reset to off_5AC490 |
| this | 0xE4 | R | — | Bink video resource handle (this[57]), freed if non-null |
| this | 0xFC | R | — | Secondary allocation (this[63]), freed if non-null |

**Written-by note (persistence):**
- this 0x0: set every call; survives external poke (vtable restoration)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac490 | off_5AC490 | R | VTable_5AC490 [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00551f80 | ConditionalFreeWithBinkClose | Close and free Bink video resource |
| 00587bcf | FreeWrapper_7bcf | Heap memory deallocation |

**Guard conditions:** PASS: this+0xE4 non-null → Bink resource freed. PASS: this+0xFC non-null → secondary allocation freed. BLOCKED (each separately): null pointer → skip that free.
