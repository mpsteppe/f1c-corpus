## AnimationTimingUpdateWithParamSet_0057a5a0 — TimedAnimationFlagUpdate

**Summary:** Reads a mutex-guarded timer value, dispatches a vtable call at offset 0x58 to get an animation object, sets a flag byte at offset +4 of the animation object's data, stores the timer, and conditionally dispatches further vtable calls. Used for animation timing updates.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UtilityFunction_e570 (0045e570), RunCollisionDetectionLoop (0045f390)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x58 | R | — | vtable entry at offset 0x58 (gets animation/context object from this) |
| obj | 0x0 | R | — | vtable pointer of the context object |
| this | 0x0 | R | — | pointer to context object |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005836e0 | CounterAssignment | stores timer value into local structure v5 |
| 00584f90 | MutexGuardedTimerRead | reads current timer value with mutex protection |
| 00585380 | VTableDispatchWithConditionalCall | conditionally dispatches vtable calls on animation object |
| 00586800 | sub_586800 | debug/telemetry logging call (0, 14, 0, 3, 500) |
| 00586a00 | SingleFunctionCallWrapper_6a00 | sets timer value from v5 structure |

**Guard conditions:** none.
