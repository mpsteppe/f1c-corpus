## CollisionMutexInitialization_0045bf90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1ac | CreateMutexA | R | [LLM] |
| 007cd264 | dword_7CD264 | W | GlobalMutexHandle [DERIVED] (also: ` — HANDLE, mutex handle) |
| 007cd268 | dword_7CD268 | W | MutexLockState [DERIVED] (also: ` — int, lock state (-1 = unlocked) |
| 007cd26c | byte_7CD26C | W | MutexInitFlag [DERIVED] (also: ` — int, initialized flag) |
| ff00000000005450 | byte_FF00000000005450 | W | [LLM] |
| ff00000000005451 | byte_FF00000000005451 | W | [LLM] |
| ff00000000005452 | byte_FF00000000005452 | W | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
