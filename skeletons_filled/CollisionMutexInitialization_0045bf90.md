## CollisionMutexInitialization_0045bf90 — CollisionMutexInit

**Summary:** Initializes global collision mutex: zeroes handle/flag, sets lock state to unlocked, creates unnamed mutex via CreateMutexA, and sets init flag on success. Part of collision system startup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1ac | CreateMutexA | R | Imported kernel32 CreateMutexA |
| 007cd264 | dword_7CD264 | W | GlobalMutexHandle [DERIVED] (also: ` — HANDLE, mutex handle) |
| 007cd268 | dword_7CD268 | W | MutexLockState [DERIVED] (also: ` — int, lock state (-1 = unlocked) |
| 007cd26c | byte_7CD26C | W | MutexInitFlag [DERIVED] (also: ` — int, initialized flag) |
| ff00000000005450 | byte_FF00000000005450 | W | unknown — not referenced in visible decompiled code |
| ff00000000005451 | byte_FF00000000005451 | W | unknown — not referenced in visible decompiled code |
| ff00000000005452 | byte_FF00000000005452 | W | unknown — not referenced in visible decompiled code |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — runs unconditionally. Post-condition: if CreateMutexA returns non-null, sets byte_7CD26C = 1 (initialized).
