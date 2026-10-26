## SceneClearReset_004a0690 — SceneClearReset

**Summary:** Resets/clears scene state: initializes array check, loads track scene from settings path (with fallback to default directory), resets sound system, initializes buffer defaults, and calls sub-initializer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 005eb10c | dword_5EB10C | R | SoundSystemPtr [DERIVED] (also: ` — engine interface pointer) |
| 007ce5ec | dword_7CE5EC | R | SettingsFilePath [DERIVED] |
| 007d2db0 | dword_7D2DB0 | R | RaceStandingsSortBuffer [CONFIRMED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004186a0 | BufferInitWith10fDefaults | Initializes buffer with 10f default values |
| 004a09f0 | sub_4A09F0 | Session scene sub-initializer |
| 004c2810 | ArrayCheckInit | Initializes array bounds check structure |
| 004c55b0 | TrackSceneLoader | Loads track scene from path string |

**Guard conditions:** dword_7CE5EC null fallback to byte_5EA438 (default directory); dword_5EB10C sound guard — non-null calls sound interface vtable+12
