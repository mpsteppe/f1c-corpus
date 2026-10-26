## AudioVolumeLoadComputation_00545f50 — Compute audio buffer load and call system callback

**Summary:** Computes audio buffer load percentage based on buffer state counter (1/2/3). Calculates fill ratio using buffer sizes and data pointers, then invokes a callback function pointer with the computed float load value. Returns 0 when callback is null or load is below 0.25 threshold.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VertexBufferResourceAllocation (00543fa0), AudioEngineInitialization (00546010), LinkedListWalkInterlockedDec (005487a0), SceneNode (0055a910)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00545ff8 | jpt_545F6C | R | Jump table for buffer state switch |
| 0059e43c | flt_59E43C | R | Physics constant (unused in this path) |
| 0059e7f8 | flt_59E7F8 | R | Anti-roll mixing factor (unused in this path) |
| 0059e8ec | flt_59E8EC | R | Speed deadzone (unused in this path) |
| 0059e990 | flt_59E990 | R | Physics constant (unused in this path) |
| 008b8ee8 | dword_8B8EE8 | R | Audio buffer size in bytes |
| 008b8eec | Addend | R | Audio half-buffer size in bytes |
| 008b8ef0 | dword_8B8EF0 | R | Audio buffer data pointer/reference |
| 008b8ef4 | dword_8B8EF4 | R | Total audio sample data size |
| 008b8ef8 | dword_8B8EF8 | R | Audio buffer ready state counter (1/2/3) |
| 008b8f00 | dword_8B8F00 | R | Audio system callback function pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** `dword_8B8F00` (callback) null check: BLOCKED (return 0) when null; PASSES (process state) when non-null. `dword_8B8EF8` switch: case 1/2/3 process load; default: return 0. Within cases 1/2: computed load < 0.25 -> return 0 (load too low to report); >= 0.25 -> invoke callback.
