## DebugLogWrite_004d7aa0 — DebugLogMessageWriter

**Summary:** Writes a formatted message to the debug log file handle at this[4]. Calls FileWriteWrapperWithLock to write the buffer, then LockCallUnlockWrapper to flush/sync the file handle.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** (extensive list — called from throughout the game)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | file handle for the debug log output |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00589ffd | LockCallUnlockWrapper | flushes/synchronizes the file handle after write |
| 0058a163 | FileWriteWrapperWithLock | writes formatted data to file handle with locking |

**Guard conditions:** None; always writes the message and flushes.
