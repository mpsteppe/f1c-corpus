## sub_4C8FC0_004c8fc0 — TimedVTableDispatchDecrement

**Summary:** Decrements counter by global delta; when counter <= 0 and secondary condition passes, resets counter from initial value and dispatches vtable callback at offset 12. Timer/countdown pattern.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4C7DE0 (004c7de0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xC | R | — | unknown |
| this | 0x0 | R | — | VTable pointer |
| this | 0x14 | R | — | Reset/initial value for counter |
| this | 0x18 | RW | — | Current counter value (decremented by global delta) |

**Written-by note (persistence):**
- this 0x18: Decremented each call; reset to this+0x14 when <= 0 and condition passes; survives external pokes

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c9000 | ArithmeticComparison_9000 | Performs arithmetic comparison check (secondary gate) |

**Guard conditions:** Counter-this+0x18 after decrement must be <= 0 AND ArithmeticComparison_9000 must return non-zero. Only then does it reset counter and dispatch vtable+12. Otherwise returns 0.
