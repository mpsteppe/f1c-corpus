## CUBESceneLoaderEntry_0048e8d0 — CUBESceneDataLoadEntry

**Summary:** Entry point for loading CUBE scene data: validates directory path matches default, traverses child linked list, attempts audio engine initialization; on failure stores result handle and optionally dispatches fallback utility calls; on success relocates strings and logs debug message on split error.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StateInitializerWithFlagCheck (00466300)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x40 | R | — | child linked list pointer for traversal |
| this | 0xE0 | R | — | directory path pointer for loading |
| this | 0xE8 | R | — | audio engine initialization result handle |
| this | 0xEC | RW | — | secondary result / state set on failure path |

**Written-by note (persistence):**
- this 0xEC: set conditionally on audio init failure; survives until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005cc220 | aCubeErrorLoadi_1 | R | String_CubeError [DERIVED] |
| 005cc248 | aDDevF119992002_27 | R | Str_DevF119992002_27 [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00496e40 | LinkedListTraversalWithVirtualCall | traverse child linked list |
| 004d7a50 | StringSplitLoop | split string and load parsed data |
| 004d7aa0 | DebugLogWrite | write error message to debug log |
| 0053c5b0 | StringRelocationCopy | copy/relocate string data |
| 00541ca0 | sub_541CA0 | unknown utility called on failure path |
| 00541cd0 | UtilityFunction_1cd0 | unknown utility called on failure path |
| 00545020 | SimpleGetter_5020 | retrieve a simple value for storage |
| 00546010 | AudioEngineInitialization | initialize audio engine for CUBE scene |
| 00588410 | sub_588410 | path comparison / directory validation |

**Guard conditions:**
- If this[56] is null → substitute default path byte_5EA438
- If sub_588410(path, default) returns 0 → BLOCKED (return 0, load aborted)
- If AudioEngineInitialization() returns 0 (failure) → enter failure path: conditionally store result at EC, optionally dispatch utilities, return 0
- If AudioEngineInitialization() returns non-zero (success) → enter success path: relocate strings, check StringSplitLoop, optionally log error, return 1
