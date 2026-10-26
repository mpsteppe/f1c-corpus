## FontResourceLoader_0048e3a0 — FontResourceLoader

**Summary:** Loads a font resource for the UI. Frees any existing resource at this+0xE4, constructs a font object path from a base directory (dword_5EC3F0 or default), allocates a 128-byte path buffer, creates the resource via ObjectCreationWithRollbackOnFailure, and extracts font metrics (width/height from offsets +0xC and +0x10 of the created object) if successful. Calls sub_551EB0 to configure a DSP parameter on success.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xE4) | 0xC | R | — | Font glyph width (from created resource object) |
| *(this+0xE4) | 0x10 | R | — | Font glyph height (from created resource object) |
| this | 0xB0 | R | — | Font directory path string (this[44]) |
| this | 0xB8 | R | — | Font name/identifier string (this[46]) |
| this | 0xE4 | RW | 0 | Font resource object pointer (this[57]), allocated via ObjectCreationWithRollbackOnFailure |
| this | 0xE8 | RW | 0 | Font metrics width (this[58]), set from created resource |
| this | 0xEC | RW | 0 | Font metrics height (this[59]), set from created resource |
| this | 0xF0 | RW | — | Unknown dimension/offset (this[60]) |
| this | 0xF4 | RW | — | Unknown dimension/offset (this[61]) |
| this | 0xF8 | RW | 0 | Active flag (this[62], byte at 0x248) |

**Written-by note (persistence):**
- this 0xE4: set to created resource pointer; cleared on success; survives external poke
- this 0xE8: set from resource object field; survives external poke
- this 0xEC: set from resource object field; survives external poke
- this 0xF0: unknown; survives external poke
- this 0xF4: unknown; survives external poke
- this 0xF8: set to 0 every call; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3f0 | dword_5EC3F0 | R | ExtraDirPath [DERIVED] (also: ` — font directory path) |
| 007cf2cc | flt_7CF2CC | R | DSPTransformParam [DERIVED] (also: ` — DSP transform parameter) |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00551eb0 | sub_551EB0 | Set DSP transform parameter |
| 00551f10 | ObjectCreationWithRollbackOnFailure | Create resource object with rollback on failure |
| 00551f80 | ConditionalFreeWithBinkClose | Close and free existing Bink resource |
| 005665b0 | sub_5665B0 | String transformation/copy for path building |
| 00566650 | StringCopyWithBufferRealloc | String copy/reallocation for path construction |
| 00587bcf | FreeWrapper_7bcf | Free temporary path buffer |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate 128-byte path buffer |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xE4 | == | 0 | Existing font resource handle |

**Guard interpretation:** PASS: this+0xE4 != 0 → free old resource before creating new one. BLOCKED: this+0xE4 == 0 → skip free, proceed directly to creation.
