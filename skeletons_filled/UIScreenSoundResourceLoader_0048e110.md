## UIScreenSoundResourceLoader_0048e110 — SoundResourceLoader

**Summary:** Loads a sound resource for a UI screen. Frees any existing Bink sound resource at this+0xE0, constructs a sound object via ObjectCreationWithRollbackOnFailure using the path from this+0xB0 (or default directory), then creates a second resource by concatenating a subdirectory path (dword_5EC3F0) with the screen path, and calls sub_551EB0 to set a DSP transform parameter on success.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB0 | R | — | Screen path string pointer (this[44]) |
| this | 0xE0 | RW | 0 | Bink sound resource handle (freed then reset via creation) |
| this | 0xE4 | RW | — | Secondary resource handle (this[57]) |

**Written-by note (persistence):**
- this 0xE0: zeroed then reassigned every call; survives external poke
- this 0xE4: set to created resource handle every call; survives external poke

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
| 00551eb0 | sub_551EB0 | Set DSP transform parameter for audio |
| 00551f10 | ObjectCreationWithRollbackOnFailure | Create resource object with rollback on failure |
| 00551f80 | ConditionalFreeWithBinkClose | Close and free existing Bink sound resource |
| 00566650 | StringCopyWithBufferRealloc | String copy/reallocation for path construction |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xE0 | == | 0 | Existing sound resource handle |

**Guard interpretation:** PASS: this+0xE0 != 0 → free old resource before creating new one. BLOCKED: this+0xE0 == 0 → skip free, proceed directly to creation.
