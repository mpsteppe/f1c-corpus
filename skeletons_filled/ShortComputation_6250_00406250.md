## ShortComputation_6250_00406250 — SynchronizationObjectDestructorCleanup

**Summary:** Destructor/cleanup for synchronization object. Resets vtable, removes from linked list, closes mutex handle, and frees allocated string buffers before reverting to base vtable.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_6230 (00406230)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to ThreadObjectVTable then VTable_FileMutex) |
| this | 0x50 | RW | 0 | mutex handle (closed and set to 0) |
| this | 0x58 | R | — | initialized flag (checked before closing handle) |

**Written-by note (persistence):**
- this 0x0: written during cleanup — vtable swapped to base type
- this 0x50: written conditionally — set to 0 only if handle was closed successfully

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a8 | CloseHandle | R | Windows API to close mutex handle |
| 0059e4ec | off_59E4EC | R | ThreadObjectVTable [DERIVED] |
| 0059e50c | off_59E50C | R | VTable_FileMutex [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004064c0 | ViewCameraReset | resets slot entry data to default state |
| 00407c90 | LinkedListNodeRemovalWithVTableRelease | removes object from linked list |
| 00587bcf | FreeWrapper_7bcf | frees string buffer allocations from slot entries |

**Guard conditions:** checks this[88] (offset 0x58, initialized flag) before calling CloseHandle — if flag is 0, skips handle close
