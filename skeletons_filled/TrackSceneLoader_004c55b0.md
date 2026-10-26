## TrackSceneLoader_004c55b0 — Find and set current scene by name

**Summary:** Normalizes an input scene name and searches the scene registry array for a matching entry by name comparison. If found, sets `dword_8AC48C` to the matching index. Returns scene count if no match.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameFilterSetup (00477830), SceneListSearchByPath (00477ba0), SessionSceneInitChain (004a0630), SceneClearReset (004a0690), SessionActiveCheck (004a09a0), TrackEnvironmentSelect (004ade20), sub_4C1050 (004c1050), SessionConfigReader (004c11e0), VidMan_Init (004fa320)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ac488 | dword_8AC488 | R | SceneFileCount [DERIVED] |
| 008ac48c | dword_8AC48C | W | CurrentSceneIndex [DERIVED] (also: ` — module list index) |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00589901 | sub_589901 | Normalize/transform scene name string (uppercase, trim, etc.) |

**Guard conditions:** If `dword_8AC488` (scene count) <= 0, skip search and return 0. Otherwise iterate all entries comparing normalized names; set `dword_8AC48C` to match index on success.
