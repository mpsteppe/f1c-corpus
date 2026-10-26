## VidMan_Post_004fac00 — VidManPostCleanupAndScenePathRegister

**Summary:** Post-race video manager cleanup — resets frame rate counter, releases collision geometry handle, clears global state, extracts directory path from current scene struct (strips filename) and registers it via string matching.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Post (0042da30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d6dc4 | aDDevF119992002_26 | R | PathPrefix [DERIVED] |
| 005d6ed0 | aEnteredVidmanP | R | EnteredVidmanString [DERIVED] |
| 008ac48c | dword_8AC48C | R | CurrentSceneIndex [DERIVED] (also: ` — module list index) |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afca8 | dword_8AFCA8 | R | RenderDisplayListPtr [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |
| 008afe88 | dword_8AFE88 | RW | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | format message string with path prefix |
| 004d7aa0 | DebugLogWrite | write debug log message |
| 004f8ea0 | FrameRateCounterInitReset | reset frame rate counter/timer |
| 0053c900 | StringMatchWithFlagSet | match string against known paths and set associated flag |
| 0053d400 | SingleGlobalSetter | set a global variable to given value |
| 005461b0 | MutexSemaphoreCleanup | release/destroy mutex or semaphore handle |

**Guard conditions:** StringSplitLoop returns 0 → skip debug log. Scene ptr (396*index + base) == 0 → skip path extraction and StringMatchWithFlagSet. String length <= 0 → skip backslash-finding loop. Character == '\\' (0x5C) → break from backslash loop. If last character is backslash → null-terminate at that position (strip trailing separator).
