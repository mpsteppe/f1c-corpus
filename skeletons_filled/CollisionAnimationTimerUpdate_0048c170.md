## CollisionAnimationTimerUpdate_0048c170 — CollisionAnimTimerUpdate

**Summary:** Updates collision/animation timer accumulator at this+0x318. Adds external float value (from this+0x40 pointer), applies damping toward 0.75, and dispatches vtable[46] callbacks if non-unit collision computed.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x40 | R | — | Pointer to external float value (force/acceleration input) |
| this | 0x304 | R | — | Enable flag byte — skip update if 0 |
| this | 0x318 | RW | — | Timer accumulator float (collision/animation elapsed time) |

**Written-by note (persistence):**
- this 0x318: updated each tick — accumulates float input, clamped via damping. Volatile — per-frame state.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians conversion factor (not directly used in C) |
| 0059e7fc | flt_59E7FC | R | Bump damping constant (relates to 0.5/0.75 damping formula) |
| 0059e908 | flt_59E908 | R | Collision event threshold (not directly used in C) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486710 | ByteFieldGetterAt100 | Reads flag at this+0x100; returns nonzero to block update |
| 00486720 | ShortComputation_6720 | Returns collision computation result and loop count |
| 00498730 | FloatFieldAccessor | Reads/processes external float value from this+0x40 dereference |
| 00587bdc | CRTFtol | Converts float to integer (truncation) |

**Guard conditions:** If ByteFieldGetterAt100 returns nonzero → BLOCKED (return -1). If byte at this+0x304 == 0 → BLOCKED (return -1). If float addition overflows/underflows (FPU flags C0|C2) → PASSES but returns 0 early without damping or dispatch. Otherwise: applies damping formula `accum = v3 - 0.5*(v3 - 0.75)` then loops ShortComputation_6720 count times, calling vtable[46] with (v9 == 4) as argument.
