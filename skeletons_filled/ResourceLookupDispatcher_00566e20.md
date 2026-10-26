## ResourceLookupDispatcher_00566e20 — dispatch resource query: buffer or file

**Summary:** Returns resource data/size based on mode flag at this[4]. If non-zero, reads from audio stream buffer via AudioStreamBufferRead. If zero, queries file size via FileSizeQueryWrapper. Resource loading subsystem.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIScreenLoad (0048aed0), FileSettingsScanner (004a1b90), FileHandleCloseRegistration (004b4470), sub_4B44A0 (004b44a0), NetworkBufferRead (004b7c80), LoadingPhase1 (004b87c0), sub_4F7460 (004f7460)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | handle/resource identifier |
| this | 0x10 | R | — | mode flag: zero=file size query, non-zero=audio buffer read |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058ace6 | FileSizeQueryWrapper | query file size by handle |

**Guard conditions:** If this[4] == 0 → FileSizeQueryWrapper path. If this[4] != 0 → AudioStreamBufferRead path.
