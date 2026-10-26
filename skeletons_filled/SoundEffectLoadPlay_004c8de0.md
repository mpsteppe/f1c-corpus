## SoundEffectLoadPlay_004c8de0 — SoundEffectLoadPlay

**Summary:** Loads and plays a sound effect by index (a1 < 8) with parameter a2. Lazily initializes singleton manager from InitStatus. Builds file path from base directory + sound name table entry.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetCommPlayerSlotSync (0045fc50), SessionStateDispatch (004a0df0), sub_4B3400 (004b3400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005d3234 | off_5D3234 | R | Audio_WelcomePtrTable [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3e0 | dword_5EC3E0 | R | AudioDirBasePath [DERIVED] |
| 008ac4c4 | dword_8AC4C4 | R | InitStatus [DERIVED] |
| 008ac4d0 | dword_8AC4D0 | RW | SingletonMgrPtr_3 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | Copies string, reallocating buffer if needed |
| 00587bcf | FreeWrapper_7bcf | Frees allocated heap buffer |
| 0058815f | StringFormatWithBufferOverflowCheck | Safe string format with overflow protection |

**Guard conditions:** (1) InitStatus must be non-null; if null, skips to SingletonMgrPtr_3 check. (2) If SingletonMgrPtr_3 is null, creates via InitStatus vtable+96 then retries. (3) a1 < 8 gates the load/play path; if a1 >= 8, returns without loading.
