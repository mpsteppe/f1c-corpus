## SessionStateByte7CE25FSetter_00464600 — Session flag setter based on object state

**Summary:** Checks init guard byte_7CE260; if zero (not initialized), checks object bytes at +0xC5/+0xC6 and sets global byte_7CE25F=1 when either is nonzero. Also builds track config name and conditionally runs guarded init.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Post (0042da30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xC5 | R | — | First object state byte checked for nonzero |
| obj | 0xC6 | R | — | Second object state byte checked for nonzero |
| obj | 0x3FB8 | R | — | Condition for calling ShortComputation+GuardedInitCall (nonzero = run) |
| obj | 0x3FC4 | R | — | Argument passed to SingleFunctionCallWrapper_a910 |
| this | 0x0 | R | — | Pointer to underlying object |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007ce260 | byte_7CE260 | R | InitGuard_45d500 [DERIVED] (also: ` -- init guard flag) |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045d500 | GuardedInitCall | Runs one-time initialization guarded by init flag |
| 00463140 | ShortComputation_3140 | Short computation before init call |
| 004b16b0 | TrackConfigurationNameBuilder | Builds track configuration name string |
| 0057a910 | SingleFunctionCallWrapper_a910 | Wrapper that calls a single function |

**Guard conditions:** Checks byte_7CE260. If nonzero (already initialized), early return (BLOCKED). If zero, proceeds with full body (PASSES).
