## sub_4D8FB0_004d8fb0 — Release 4 audio/render handles

**Summary:** Releases four global resource handles (dword_8AD388 through dword_8AD394) by calling a release/destructor function on each non-null handle, then nulling the handle. Called to clean up existing resources before reloading.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UtilityFunction_8720 (004d8720), sub_4D8AB0 (004d8ab0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ad388 | dword_8AD388 | RW | File_MusicTrackPtr [DERIVED] — handle 1, released and nulled |
| 008ad38c | dword_8AD38C | RW | ResourceHandle_1 [DERIVED] — handle 2, released and nulled |
| 008ad390 | dword_8AD390 | RW | AudioHandleArray [DERIVED] — handle 3, released and nulled |
| 008ad394 | dword_8AD394 | RW | AudioEmitter3 [DERIVED] — handle 4, released and nulled |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053d130 | StringCompareLinkedListSearch | Releases/destructs a resource handle (despite name, acts as release/free) |

**Guard conditions:** Each of the 4 handles individually guarded: non-null → release + null; null → skip. All operations unconditional within each guard.
