## sub_40CCF0_0040ccf0 — CarSelectionListBuilder

**Summary:** Builds the list of selectable cars for career/race mode — loads .gdb car files, iterates available vehicles, creates linked list of car entries with skin/model data. Also handles career-mode car filtering.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x14 | R | — | unknown object field read |
| obj | 0x18 | R | — | unknown object field read |
| this | 0x0 | R | — | vtable pointer (virtual dispatch at offsets 0x14 and 0x18) |
| this | 0x4 | RW | — | head of car-entry linked list |
| this | 0x8 | RW | — | tail of car-entry linked list |
| this | 0xC | RW | — | another tail pointer (prev pointer) |
| this | 0x10 | RW | — | count of car entries in list |
| this | 0x24 | RW | — | unknown |
| this | 0x64 | R | — | number of opponents count |
| this | 0x66 | RW | 1 | list-initialized flag |

**Written-by note (persistence):**
- this 0x4: written once during initialization — survives until next rebuild
- this 0x8: written once during initialization — survives until next rebuild
- this 0xC: written once during initialization — survives until next rebuild
- this 0x10: written once during initialization — survives until next rebuild
- this 0x24: written once during initialization — survives until next rebuild
- this 0x66: written once at start — set to 1, persists as flag

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d5718 | off_5D5718 | R | unknown |
| 005d5744 | off_5D5744 | R | unknown |
| 005d5748 | off_5D5748 | R | unknown |
| 005fb7e8 | Format | R | sprintf format "%s%s" |
| 005fc044 | dword_5FC044 | R | file extension prefix bytes |
| 005fc048 | dword_5FC048 | R | file extension bytes |
| 005fc04c | dword_5FC04C | R | file extension bytes |
| 005fc050 | off_5FC050 | R | file extension suffix |
| 005fc054 | aCareer_0 | R | string "career" — used to match career-mode cars |
| 005fc05c | aAndNascarClose | R | string "AND: NASCAR ClosedWheel 2003" — audio/file identifier |
| 00629120 | byte_629120 | R | empty string sentinel |
| 0062a068 | dword_62A068 | R | pointer to base path |
| 007663e0 | byte_7663E0 | R | unknown |
| 007665d8 | dword_7665D8 | R | default car path/name |
| 007d6a58 | dword_7D6A58 | R | number of loaded vehicles |
| 007d6a5c | dword_7D6A5C | R | vehicle data array pointer |
| 007d6b74 | dword_7D6B74 | R | vehicle paint/skin data reference |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00405480 | sub_405480 | sprintf wrapper (formatted string) |
| 0040e4c0 | sub_40E4C0 | get car filename for given ID |
| 0040efc0 | sub_40EFC0 | set car color/skin data |
| 00413700 | sub_413700 | create car 3D model / render object |
| 004cd5b0 | PathTruncationUtility [structural] | truncate/manipulate file path |
| 004e2420 | LinkedListDestruction_f640 [structural] | destroy temporary linked list |
| 004e2570 | sub_4E2570 | get number of selectable vehicles |
| 004e28f0 | VehicleArrayIndexAccessor [structural] | get vehicle entry by index |
| 004ed5c0 | sub_4ED5C0 | set car skin/paint |
| 004ed6e0 | sub_4ED6E0 | get paint scheme data |
| 004ed6f0 | sub_4ED6F0 | get paint array entry |
| 004ed7b0 | sub_4ED7B0 | apply paint to car |
| 00504470 | sub_504470 | initialize temporary buffer |
| 00578600 | StringCopyWithBufferRealloc [structural] | copy string with buffer management |
| 00579060 | sub_579060 | compare car data / check match |
| 0057a6d0 | sub_57A6D0 | get config value |
| 0057a6e0 | LinkedListCount [exact] | count entries in linked list |
| 0057ac50 | AudioFileLoadDecode [structural] | load audio/gdb data file |
| 0057ae50 | sub_57AE50 | find config section |
| 005be8e3 | ??2@YAPAXI@Z | operator new |
| 005beab0 | _strncpy | standard strncpy |
| 005bec89 | _atoi | standard atoi |
| 005bf290 | __strcmpi | standard stricmp |

**Guard conditions:** Loop over sub_4E2570 result — only processes when VehicleArrayIndexAccessor returns non-null. Career car matching: compares filename stem against "career" with sub_579060 check for paint match. If no career car found, defaults to dword_7665D8.

**String literals referenced (deterministic):**

- `%s%s`
- `%s%s`
- `_createACar.skn`
- `career`
- `AND: NASCAR ClosedWheel 2003`
