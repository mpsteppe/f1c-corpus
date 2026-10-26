## ResourceDestroy_004d5840 — FileResourceHandleDestroy

**Summary:** If *this (a file handle) is non-zero, performs cleanup: writes 8 zero bytes to state, reads 4 bytes back, closes the file handle, and sets *this to 0. File handle destroy/close sequence.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** WheelDynamicsInit (0043e230), sub_4A0250 (004a0250), TelemetryDataDump (004d4a80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | file/resource handle (non-zero means resource is open) |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587d02 | FileCloseWithLock | closes the resource file handle with lock |
| 00587f64 | sub_587F64 | zeroes/writes state data associated with the handle |
| 00588678 | FileReadWrapperWithLock | reads back from the file handle (confirms/syncs) |

**Guard conditions:** If *this (handle) is 0, returns immediately (nothing to destroy). Otherwise performs full cleanup sequence and resets handle to 0.
