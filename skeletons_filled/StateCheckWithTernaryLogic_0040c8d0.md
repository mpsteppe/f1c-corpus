## StateCheckWithTernaryLogic_0040c8d0 — CameraModeStateResolver

**Summary:** Resolves camera mode from stored state fields. Falls back to sub-object field when primary is zero; maps value 1→1, 2→queue-dependent result, else→0 or 3.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraTargetUpdateOnPlayerChange (0040c7a0), SetDriverVisibility (004c7aa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | primary camera mode state value |
| this | 0x18 | R | — | pointer to sub-object whose +0x34 field provides fallback mode value |
| this | 0x4C | R | — | unknown (not directly accessed by this function) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cfcc8 | dword_7CFCC8 | R | QueuedModeFlag [DERIVED] — gates mode 2: returns 1 if clear, 0 if set |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** if this+0xC == 0 and *(*(this+0x18)+0x34) == 0, returns 3. Returns 1 when resolved value is 1. Returns dword_7CFCC8==0 when resolved value is 2. Returns 0 otherwise.
