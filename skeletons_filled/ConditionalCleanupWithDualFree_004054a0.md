## ConditionalCleanupWithDualFree_004054a0 — FileHandleAndBufferCleanup

**Summary:** Conditionally closes a file handle at offset 0xC and frees a heap buffer at offset 0x18, then reinitializes the struct via CameraViewStructInitializer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiStageCleanupWithFree (00405410)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | 0 | file handle (closed via FileCloseWithLock if non-null, then zeroed) |
| this | 0x18 | R | — | heap buffer pointer (freed via FreeWrapper_7bcf if non-null) |

**Written-by note (persistence):**
- this 0xC: zeroed after file close; external poke survives until next cleanup

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00405630 | StructInitWithVTableDispatchAndZeroFill | initializes a vtable-backed sub-struct and zero-fills |
| 00587bcf | FreeWrapper_7bcf | standard heap free wrapper |
| 00587d02 | FileCloseWithLock | closes a file handle with locking |

**Guard conditions:** Checks field at offset 0xC != NULL before closing file handle. Checks field at offset 0x18 != NULL before freeing buffer. PASSES: file closed and handle zeroed; buffer freed. BLOCKED: null fields skipped.
