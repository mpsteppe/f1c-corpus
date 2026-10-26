## ShortComputation_d360_0040d360 — RandomRangeCompute

**Summary:** Generates random value within configurable range. Accepts min/max parameters, clamps/stores them, computes random int in [min, max) via LCG, stores result as float. Returns quotient from random division (side channel of LCG call). Used for randomized timing or parameter selection.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RaceModeSetup (00404890), ConditionalSoundRenderDispatchOnParamCheck (00404970), RandomStateMachineWithTimerAndTrigger (0040c070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2E | RW | 1 | Updated flag byte — set to 1 on each call |
| this | 0x30 | RW | 0 | Min value — clamped from a2 (≥ 0) |
| this | 0x34 | RW | — | Max value — a3 or a2+5 if a3 invalid |
| this | 0x3C | RW | — | Random result stored as float — value in [min, max) |

**Written-by note (persistence):**
- this 0x2E: written every call — external poke does NOT persist
- this 0x30: written every call — external poke does NOT persist
- this 0x34: written every call — external poke does NOT persist
- this 0x3C: written every call — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005884ed | RandLCGRandomNumberGenerator | LCG random integer generator — produces value used for range computation |

**Guard conditions:** a2 ≤ 0 → min clamped to 0. a3 ≤ 0 or a3 ≤ a2 → max set to a2+5. PASS: both valid → min=a2, max=a3.
