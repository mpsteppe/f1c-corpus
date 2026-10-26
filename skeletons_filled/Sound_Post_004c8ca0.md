## Sound_Post_004c8ca0 — SoundPostCleanup

**Summary:** Post-cleanup for sound system: resets init status, clears scene camera parameter, dispatches guarded virtual call, and validates/resets entries in sound pointer table. Called from Game_Post.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Post (0042da30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d3398 | aDDevF119992002_24 | R | DefaultScenePath24 [DERIVED] |
| 005d340c | aEnteredSoundPo | R | EnteredSoundString [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 008ac4b0 | flt_8AC4B0 | R | SceneCameraParam [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c7e80 | sub_4C7E80 | Clears/zeros field at given address |
| 004c8180 | VirtualCallOnDAT008ac4c4 | Executes virtual call on InitStatus global |
| 004c8a10 | GlobalVirtualDispatchGuarded | Dispatches guarded virtual call |
| 004d7a50 | StringSplitLoop | Parses/splits string by delimiter with expected token count |
| 004d7aa0 | DebugLogWrite | Writes debug log message to buffer |

**Guard conditions:** StringSplitLoop return gates log. dword_5EB10C non-null AND vtable+8 non-zero AND flt_5EA618[699] in (0,291) gates vtable+12 call. Loop: iterates 20 entries at flt_5EA618[537]; each entry with value in (0,291) triggers StructInitWithSentinelValues.
