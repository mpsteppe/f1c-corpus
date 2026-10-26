## TimerBasedStateUpdateWithCap_005514c0 — TimedStateUpdateWithCascadeDispatch

**Summary:** Updates entity timer via QPC, caps at a maximum duration, and dispatches to cascade update or sub-init chain based on flag state. Resets accumulator on audio flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LinkedListTraversalWithConditionalTimerUpdate (00551760)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1C) | 0x8 | R | — | Time cap value (maximum duration for this state) |
| this | 0x0 | R | — | QueryPerformanceCounter handle |
| this | 0x4 | RW | — | Flags: 0x1000=audio reset, 0x8000=timer active, 0x20000=cascade mode |
| this | 0x8 | RW | — | Timer accumulator (reset to 0.0 on audio reset) |
| this | 0x10 | RW | — | Current elapsed time (set from QPC, capped to max) |
| this | 0x1C | R | — | Pointer to time cap/duration structure |

**Written-by note (persistence):**
- this 0x4: Multiple bitwise operations; external poke partially survives
- this 0x8: Set to 0.0 on audio reset path; external poke overwritten
- this 0x10: Set from QPC each frame, capped; external poke overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00551210 | sub_551210 | Apply current timer value to entity state |
| 00551440 | EntityFlagSetSubInitChain | Init sub-chain: set flags, copy parameter data, start timer |
| 00551480 | AudioFlagSet | Set audio timer flag (0x1000) |
| 005514a0 | FlagUpdateWithCascade | Cascade update path (used when 0x20000 flag set) |
| 00556440 | HighResolutionTimerReset | Reset high-resolution timer |
| 005565b0 | HighPrecisionTimerCounterArithmetic | Query elapsed time from QPC |

**Guard conditions:** 
- this[7] (offset 0x1C) == 0: skip entire function (no time cap structure). PASS when non-null.
- this[1] & 0x1000: audio reset path → clear timer, set flag 0x8000. PASS when bit set.
- this[1] byte1 & 0x80 (bit 15 = 0x8000): timer active → query QPC and update. PASS when bit set.
- v5 (elapsed) < *(v6+8) (time cap): skip cap logic, go directly to sub_551210. PASS when ≥ cap (cap applied, sub-init or cascade runs).
- this[1] & 0x20000 (when capped): cascade update path instead of sub-init. PASS when set → FlagUpdateWithCascade + sub_551210 + return. BLOCKED when clear → EntityFlagSetSubInitChain + AudioFlagSet then fall through to sub_551210.
