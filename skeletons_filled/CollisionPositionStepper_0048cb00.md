## CollisionPositionStepper_0048cb00 — CollisionPositionStepper

**Summary:** Steps collision/animation position toward target. Accumulates time delta, computes steps, advances position at rate proportional to distance (0.444 scaling), wraps within range (step * multiplier), and calls vtable[11] update each step.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_48D0A0 (0048d0a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | VTable entry 11 (offset 44) — update callback per step |
| this | 0x0 | R | — | VTable pointer (to read vtable entry at obj+0x2C) |
| this | 0x328 | R | — | Range multiplier (field 202) — multiplied by step for total range |
| this | 0x32C | R | — | Step value (field 203) — base increment size |
| this | 0x334 | RW | — | Current position (field 205) — wrapped mod range |
| this | 0x338 | R | — | Target index/offset (field 206) — destination within range |
| this | 0x33C | R | — | Direction byte flag (field 207) — nonzero=forward, zero=backward |
| this | 0x340 | RW | a2 | Float accumulator (field 208) — accumulates time delta for step rate |

**Written-by note (persistence):**
- this 0x334: updated each step with new wrapped position. Volatile — per-frame state.
- this 0x340: incremented by a2, decremented by 1/15 per step. Volatile — per-frame accumulator.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac108 | flt_5AC108 | R | Step decrement constant 0.06666667 (1/15) — subtracted from accumulator each step |
| 005ac10c | flt_5AC10C | R | AudioPanningStep (not directly used in C) |
| 005ac110 | flt_5AC110 | R | TrackMapScrollSpeed (not directly used in C) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | Float-to-int truncation — converts accumulator to step count and distance to speed |

**Guard conditions:** If range (step * multiplier) <= 0 → BLOCKED (no-op, returns). If accumulator * 14.999999 rounded to int <= 0 → BLOCKED (no steps taken). If byte at this+0x33C (direction) == 0 and step computation wraps distance differently. If computed distance == 0 after direction handling → BLOCKED (vtable[11] skipped). Loop continues until step counter reaches 0.
