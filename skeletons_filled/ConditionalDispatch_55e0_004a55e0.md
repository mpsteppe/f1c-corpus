## ConditionalDispatch_55e0_004a55e0 — PitstopTransitionSelector

**Summary:** Selects between two pitstop state transition targets using a boolean flag at offset 0x2C. If flag is non-zero, calls PitstopStateTransition on `this[4]`; otherwise calls it on `this[3]`.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ArithmeticComparison_5660 (004a5660), UtilityFunction_5750 (004a5750), IndexDecrementWithBoundsWrap (004a57a0), AIStateMachineWithModeDispatch (004a5d10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | First candidate target pointer (used when flag at 0x2C is 0) |
| this | 0x10 | R | — | Second candidate target pointer (used when flag at 0x2C is non-zero) |
| this | 0x2C | R | — | Boolean selector flag: 0 = use this[3], non-zero = use this[4] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a5600 | PitstopStateTransition | Transitions pitstop operation state machine to next phase |

**Guard conditions:** Checks `this[11]` (offset 0x2C). PASSES both branches (selector always resolves). The selected PitstopStateTransition call is not null-guarded.