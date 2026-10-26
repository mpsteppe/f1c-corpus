## sub_4D8AB0_004d8ab0 — Audio/render resource loader with screen dimensions

**Summary:** Loads 4 audio/render resources (dword_8AD388–8AD394) from path-constructed filenames using base directory (override or default) plus vtable-derived suffixes. Configures each loaded resource with normalized screen dimensions (this[57]/this[58]) at offset 92/96. Cleans up existing resources before reloading.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RaceInitWithConstants (004d8220)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xE4 | R | — | Normalized screen width — written to loaded resource at offset 92 |
| this | 0xE8 | R | — | Normalized screen height — written to loaded resource at offset 96 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005d4a48 | off_5D4A48 | R | Vtable/name suffix for resource 1 (dword_8AD388) |
| 005d4a4c | off_5D4A4C | R | Vtable/name suffix for resource 2 (dword_8AD38C) |
| 005d4a50 | off_5D4A50 | R | Vtable/name suffix for resource 3 (dword_8AD390) |
| 005d4a54 | off_5D4A54 | R | Vtable/name suffix for resource 4 (dword_8AD394) |
| 005d4a58 | off_5D4A58 | R | Common suffix/extension appended to resource names |
| 005d4a5c | off_5D4A5C | R | Suffix for directory/path construction |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec408 | dword_5EC408 | R | OverridePathPtr [DERIVED] (also: ` — override path pointer (docs/19) |
| 008ad388 | dword_8AD388 | R | File_MusicTrackPtr [DERIVED] |
| 008ad38c | dword_8AD38C | R | ResourceHandle_1 [DERIVED] |
| 008ad390 | dword_8AD390 | R | AudioHandleArray [DERIVED] |
| 008ad394 | dword_8AD394 | R | AudioEmitter3 [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d8fb0 | sub_4D8FB0 | Cleans up/releases existing resource at dword_8AD388 before reload |
| 0053cbc0 | sub_53CBC0 | Opens/initializes a temporary handle from constructed path |
| 0053ce40 | PhysicsObjectLinkedListRemoval | Cleans up temporary handle after resource loading |
| 0053cfe0 | sub_53CFE0 | Loads resource from file path into global handle with flags 0x20800 |
| 00552fd0 | MaskedFieldSetter | Sets state flags (0, 192=0xC0) before configuring resource dimensions |
| 0058815f | StringFormatWithBufferOverflowCheck | Formats path strings with "%s%s" patterns |

**Guard conditions:** `dword_8AD388` non-null → calls sub_4D8FB0 (cleanup before reload). `dword_5EC408` null → uses default path `byte_5EA438`. Temporary handle `v5` must be non-zero for any resource loading. Each `sub_53CFE0` result (dword_8AD388/8AD38C/8AD390/8AD394) must be non-null for MaskedFieldSetter and dimension write to execute.
