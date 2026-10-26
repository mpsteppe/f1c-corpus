## TripleFieldCleanup_00491f60 — Close streams and zero three resource handles

**Summary:** Closes/dispatches three stream/resource handles (audio file read, file write streams), then zeros their slots. Called during audio resource cleanup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4944A0 (004944a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | Audio stream/read handle |
| this | 0x4 | RW | 0 | Write stream handle |
| this | 0x8 | RW | 0 | Second write/auxiliary stream handle |

**Written-by note (persistence):**
- this 0x0: conditional, zeroed after StreamFileTypeCheckWithDispatch if non-null
- this 0x4: conditional, zeroed after FileCloseWithLock if non-null
- this 0x8: conditional, zeroed after FileCloseWithLock if non-null

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005355a0 | StreamFileTypeCheckWithDispatch | Closes or dispatches audio stream by file type |
| 00587d02 | FileCloseWithLock | Closes file handle with mutex/lock protection |

**Guard conditions:** Each of the three fields (this[0], this[1], this[2]) checked for non-null before calling close/dispatch. If null, that field's cleanup is skipped.
