## SceneListSearchByPath_00477ba0 — SceneListSettingsPathMatcher

**Summary:** Searches a linked list of scene nodes for one whose sub-object path string (at offset 0x104) matches SettingsFilePath. On match, stores index and loads the track scene; falls back to first entry if no match found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameFilterSetup (00477830), GameContentFilterCheck (00477aa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xF0) | 0x0 | R | — | first list node's value pointer |
| *(this+0xF0) | 0x4 | R | — | first list node's name string at offset 4 |
| *(this+0xF0) | 0x3C | R | — | first node's path string pointer at offset 0x3C |
| this | 0xF0 | R | — | linked list head pointer |
| this | 0xF8 | R | — | traversal cursor |
| this | 0xFC | R | — | list count (iterated i < this[63]) |
| this | 0x174 | RW | 0 | match result index (set to matching index or 0 for fallback) |

**Written-by note (persistence):**
- this 0x174: set to matching index or 0 if no match; persists until next search

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007ce5ec | dword_7CE5EC | R | SettingsFilePath [DERIVED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c54f0 | AIW | finalization/init function after scene load (arg 0) |
| 004c55b0 | TrackSceneLoader | loads track scene by path string |

**Guard conditions:** `i < this[63]` (offset 0xFC) limits loop; node must exist and be non-null; sub-object at node offset 0x3C must be non-null; strcmp between sub-object offset 0x104 and `dword_7CE5EC` returns 0 → match found; no match in loop but list has entries → fallback to first entry with index 0
