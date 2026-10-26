## SceneDataParser_004c5690 — Match scene file path to registry entry

**Summary:** Strips directory path and extension from an input scene file path, then iterates the scene registry comparing the base filename against each entry's path (also stripped). On match, sets `dword_8AC48C` to the matching index. Returns scene count on failure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneTextureApply (0045cf50), ClientGridDisplayTimer (00460380), SessionConfigBuilder (00461610), SessionConfigWriteback (00461900), PlayerFileInit (004b0540), LoadVehicleEntries (004b70b0), TrackSceneNodeAdd (004c28d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ac488 | dword_8AC488 | R | SceneFileCount [DERIVED] |
| 008ac48c | dword_8AC48C | W | CurrentSceneIndex [DERIVED] (also: ` — module list index) |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00596c80 | sub_596C80 | Compare two base filenames (without path/extension) for matching |

**Guard conditions:** If `dword_8AC488` (scene count) <= 0, return 0. Skips entries where stripped base filename is empty (`strlen(v15) == 0`). Match found when `sub_596C80` returns 0 (strings equal).
