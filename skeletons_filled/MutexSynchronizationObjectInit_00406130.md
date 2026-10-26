## MutexSynchronizationObjectInit_00406130 — MutexSyncObjectInit

**Summary:** Initializes a mutex synchronization object with two-phase setup: first as file-based mutex (3 file path entries), then as thread mutex via CreateMutexA. Sets vtable, timeout value, and config parameter. Called once during object construction.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LinkedListNodeInsert_78a0 (004078a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer — init to FileMutex vtable, then switched to ThreadObject vtable |
| this | 0x4 | RW | 1065353216 → 1.0f | Timeout value in seconds (1.0f) for lock operations |
| this | 0x8 | RW | — | Configuration parameter `a2` passed from caller |
| this | 0xC | RW | 0 | Counter or state flag |
| this | 0x10 | RW | 0 | Unused/reserved DWORD |
| this | 0x14 | RW | 18446744073709551615 | File path slot 0 handle (-1 = invalid) |
| this | 0x18 | RW | 18446744073709551615 | File path slot 1 handle (-1 = invalid) |
| this | 0x1C | RW | 18446744073709551615 | File path slot 2 handle (-1 = invalid) / first entry of second 3-element array |
| this | 0x20 | RW | 0 | Boolean flags array (3 bytes for 3 path slots, last byte reserved) |
| this | 0x50 | RW | 0 | OS mutex handle from CreateMutexA |
| this | 0x54 | RW | 18446744073709551615 | Mutex timeout value (-1 = infinite wait) |
| this | 0x58 | RW | 1 | Mutex initialized flag (1 = created successfully) |
| this | 0x5C | RW | 18446744073709551615 | Reserved timeout/interval (-1 = unused) |

**Written-by note (persistence):**
- this 0x0: init once — external poke persists
- this 0x4: init once — external poke persists
- this 0x8: init once — external poke persists
- this 0xC: init once — external poke persists
- this 0x10: init once — external poke persists
- this 0x14: init once — external poke persists
- this 0x18: init once — external poke persists
- this 0x1C: init once — external poke persists
- this 0x20: init once — external poke persists
- this 0x50: init once — external poke persists
- this 0x54: init once — external poke persists
- this 0x58: init once — external poke persists
- this 0x5C: init once — external poke persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1ac | CreateMutexA | R | Windows API — create named/non-named mutex |
| 0059e4ec | off_59E4EC | R | ThreadObjectVTable [DERIVED] — final vtable for mutex sync object |
| 0059e50c | off_59E50C | R | VTable_FileMutex [DERIVED] — initial vtable for file-based mutex |
| 005ea438 | byte_5EA438 | R | Default application directory path string for file mutex path construction |
| ff00000000005450 | byte_FF00000000005450 | W | Stack-local variable misidentified as global |
| ff00000000005451 | byte_FF00000000005451 | W | Stack-local variable misidentified as global |
| ff00000000005452 | byte_FF00000000005452 | W | Stack-local variable misidentified as global |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00406700 | MutexLockWithTimeout | Acquire mutex lock with timeout (called after init if mutex handle valid) |
| 00566650 | StringCopyWithBufferRealloc | Copy/reallocate string buffer for default path used in file mutex entries |

**Guard conditions:** this+0x58 (mutex init flag) checked after CreateMutexA: nonzero → lock acquired via MutexLockWithTimeout. If CreateMutexA fails (v4 == 0), flag stays 0 and lock is skipped.
