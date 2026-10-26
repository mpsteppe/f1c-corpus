## sub_4FF5B0_004ff5b0 — thunk to global function pointer off_16CB2B4

**Summary:** Marked `thunk` by IDA: forwards `this` and `a2` unchanged to the runtime-assigned function pointer off_16CB2B4 and returns its result. Fixed entry point in front of a runtime-installed implementation.

**Called by:** sub_4278D0 (004278d0), sub_4E6280 (004e6280)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 016cb2b4 | off_16CB2B4 | R | Global function pointer to the real implementation; invoked with (`this`, `a2`). |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional indirect call through off_16CB2B4; no checks or branches.
