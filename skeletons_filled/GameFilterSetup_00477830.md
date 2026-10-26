## GameFilterSetup_00477830 — GameFilterUISetup

**Summary:** Builds the "Game Filter" UI screen by cleaning up previous widget state, iterating over track scene files, creating UI objects with car icon textures and track names, and laying out the viewport. Part of the UI/game-setup screen system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xF0)+0x0) | 0x0 | R | — | vtable pointer of first element in UI widget linked list (used for virtual destructor call) |
| *(this+0xF0) | 0x0 | R | — | head pointer of first UI widget linked list (iterated for cleanup) |
| *(this+0xF4) | 0x4 | R | — | second field within structure pointed to by this+0xF4 (next-pointer in linked list) |
| this | 0xF0 | RW | 0 | first UI widget linked list head (destroyed and zeroed on each setup) |
| this | 0xF4 | RW | 0 | second UI widget linked list head (zeroed) |
| this | 0xF8 | RW | 0 | third UI widget linked list head (zeroed) |
| this | 0xFC | RW | 0 | fourth UI widget linked list head (zeroed) |

**Written-by note (persistence):**
- this 0xF0: written once during setup (after full cleanup) — external poke survives until next setup call
- this 0xF4: written once during setup — external poke survives until next setup call
- this 0xF8: written once during setup — external poke survives until next setup call
- this 0xFC: written once during setup — external poke survives until next setup call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c6a04 | aDfcariconBmp | R | UI_CarIconBitmap [DERIVED] |
| 005c7130 | aGameFilter | R | GameFilterString [DERIVED] (also: ` — "Game Filter" string constant) |
| 005c7150 | dword_5C7150 | R | GameFilterString [DERIVED] |
| 005c7154 | dword_5C7154 | R | Renderer_ShaderFlag_5C7154 [DERIVED] |
| 005c7158 | word_5C7158 | R | word_5C7158 [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004761c0 | UIObjectInit | allocate and initialize a new UI widget object |
| 00477ba0 | SceneListSearchByPath | search scene list by path for UI layout |
| 0048ebd0 | UIDimensionCapture | capture current UI dimension/screen metrics |
| 0048f5d0 | DoublyLinkedListAppend_f5d0 | append UI widget to doubly-linked display list |
| 0048f640 | UIViewportLayoutCalculator | calculate and apply viewport layout for all widgets |
| 0048fc80 | StructFieldCopy_fc80 | copy texture/sprite field data to widget structure |
| 00497ad0 | sub_497AD0 | load texture/resource by file path (car icon BMP or fallback) |
| 004c55b0 | TrackSceneLoader | load track scene data by name |
| 004c5920 | TrackNameReader | read track display name from scene data |
| 004c62c0 | ResourceListCleanup_62c0 | cleanup resource list at this+0x60 (offset 96 from widget base) |
| 004c6330 | SceneFileFilterBuilder | build filtered list of scene files matching game criteria |
| 004c6780 | LinkedListRandomAccess | random-access lookup into linked list by index |
| 00566650 | StringCopyWithBufferRealloc | copy string with buffer reallocation |
| 005681f0 | ConditionalDispatch_81f0 | conditional dispatch for "Game Filter" string processing |
| 005871f0 | ReadFieldAtOffset0x14 | read count field at offset 0x14 from resource list (item count) |
| 00587bcf | FreeWrapper_7bcf | free heap-allocated memory |
| 00587c03 | OperatorNewNhMallocWrapper | allocate memory with no-throw malloc wrapper |

**Guard conditions:** Linked-list iteration guard: while list head pointer (this+0xF0) is non-null, iterates through nodes checking byte at node+12 and vtable pointer — active nodes get virtual destructor call, all nodes freed. Track list iteration guard: loops while index < item count (from ReadFieldAtOffset0x14) — PASSES for each track scene file. Texture load fallback: if primary bitmap path fails, retries with "dfcaricon.bmp" fallback path. No early-return guards; function always returns 0 after full setup.