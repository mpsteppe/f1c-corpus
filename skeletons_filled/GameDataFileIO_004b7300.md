## GameDataFileIO_004b7300 — GameDataFileLoader

**Summary:** Loads or resets game data files (3D scene models, audio streams) for a track/vehicle. In cleanup mode (a3 true) it frees existing node data and reinitializes paths; in load mode (a3 false) it opens an audio stream and loads a model/scene file. Part of the game data I/O system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x6C0) | 0x8 | R | — | next-pointer within linked list node (node->next, used in iteration) |
| this | 0x6C0 | RW | 0 | linked list head pointer (freed in cleanup mode) |
| this | 0x6C4 | RW | 0 | linked list tail/secondary pointer (zeroed) |
| this | 0x6C8 | RW | 0 | linked list state field (zeroed) |
| this | 0x6CC | RW | 0 | linked list state field (zeroed) |
| this | 0x6E4 | R | — | file handle / data-loaded pointer (guard: != 0 means data loaded) |
| this | 0x700 | RW | 2 | load-mode flag (2 = model loaded, 1 = settings found, 0 = fallback) |
| this | 0x704 | R | — | path/to/file string pointer (used for existence check / sub_566940) |
| this | 0xD28 | RW | 0 | state/flag field zeroed during init |
| this | 0xF1C | RW | — | player vehicle data reference (copied from VehiclePtrArray[currentIdx]+18580) |
| this | 0xF20 | RW | — | session type (copied from dword_7C56A4) |
| this | 0xF24 | RW | 0 | state field zeroed during init |
| this | 0xF28 | RW | 0 | state field zeroed during init |
| this | 0xF2C | RW | 0 | state field zeroed during init |
| this | 0xF30 | R | — | angle float value (read for AngleClampWrap normalization) |
| this | 0xF78 | RW | 0 | byte flag zeroed during init |

**Written-by note (persistence):**
- this 0x6C0: once (cleared in cleanup mode; external writes survive)
- this 0x6C4: once (cleared in cleanup mode; external writes survive)
- this 0x6C8: once (cleared in cleanup mode; external writes survive)
- this 0x6CC: once (cleared in cleanup mode; external writes survive)
- this 0x700: once (set per load; external writes survive)
- this 0xD28: once (zeroed in cleanup mode; external writes survive)
- this 0xF1C: once (set per load; external writes survive)
- this 0xF20: once (set per load; external writes survive)
- this 0xF24: once (zeroed in cleanup mode; external writes survive)
- this 0xF28: once (zeroed in cleanup mode; external writes survive)
- this 0xF2C: once (zeroed in cleanup mode; external writes survive)
- this 0xF78: once (zeroed in cleanup mode; external writes survive)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007c54e4 | dword_7C54E4 | R | CurrentVehicleIndex [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007ce5d0 | dword_7CE5D0 | R | CurrentTrackPath [DERIVED] |
| 007ce608 | dword_7CE608 | R | secondary path global (track/vehicle dependent data path) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b5e50 | sub_4B5E50 | prepares/initializes internal data structures for loading |
| 004b5f60 | LinkedBufferTransfer | transfers data from linked buffer chain into target |
| 004b6c90 | ModelSceneFileLoader | loads a 3D model/scene file from disk and populates internal structures |
| 004b7500 | sub_4B7500 | initializes loader state (called with arg 1 at start) |
| 004b8010 | FileSettingExistenceCheck | checks if a game settings/data file exists at the constructed path |
| 004b86e0 | AngleClampWrap | normalizes a float angle value to a valid range |
| 004b9830 | sub_4B9830 | processes/extracts the filename from a full path string |
| 004bb3d0 | NodeDataFree | frees all data associated with a scene graph node |
| 00566650 | StringCopyWithBufferRealloc | copies a string into a buffer with reallocation if needed |
| 00566940 | sub_566940 | tests if a file or directory exists at the given path |
| 00566b20 | AudioStreamOpen | opens an audio stream file for playback |
| 00566b90 | ConditionalFileHandleCloseWithFlagDispatch | conditionally closes a file handle based on internal flag |
| 00587bcf | FreeWrapper_7bcf | frees a heap-allocated memory block |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x6E4 | != | 0 | file handle / data pointer: PASSES when data is loaded (return value check for caller) |

**Guard interpretation:** this+0x6E4 != 0 → PASSES: data handle is valid, function returns TRUE to caller indicating successful load; BLOCKED: returns FALSE (handle null/invalid)
