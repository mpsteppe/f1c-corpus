## EntityFlagSetSubInitChain_00551440 — EntityDataInitWithTimerStart

**Summary:** Sets flag bits on the entity data struct, copies parameter table data via PerEntityDataBlockCopyFromParameterTable, starts and resets a high-resolution timer, and zeros the timer field.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIListNodeManager (0054bb40), TimerBasedStateUpdateWithCap (005514c0), sub_551560 (00551560)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | QueryPerformanceCounter handle (used for timer start/reset) |
| this | 0x4 | RW | — | Flags — set bit 0x2000, clear bits 0x0FFF mask |
| this | 0x10 | RW | 0 | Timer accumulator field (zeroed after reset) |

**Written-by note (persistence):**
- this 0x4: Written with mask+set; external poke partially survives (only bits in 0x0FFF range cleared)
- this 0x10: Written unconditionally to 0; external poke overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00551390 | PerEntityDataBlockCopyFromParameterTable | Copy parameter table data into per-entity data blocks (index 0) |
| 005563e0 | TimerStartViaQueryPerformanceCounter | Start high-resolution timer via QPC |
| 00556440 | HighResolutionTimerReset | Reset the high-resolution timer to zero |

**Guard conditions:** none — always executes all operations unconditionally.
