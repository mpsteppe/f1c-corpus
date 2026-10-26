## CollisionContactBufferTimestepUpdate_0045c7e0 — ContactBufferTimestepUpdate

**Summary:** Accumulates timestep into contact time accumulator. On overflow, normalizes contact impulse values and resets accumulators. Updates 104 contact pair timers. Part of collision response system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionScoringUpdate (004643c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | Contact accumulated time (float, reset on overflow) |
| this | 0x4 | RW | 0 | First contact impulse accumulator (float, reset on overflow) |
| this | 0x8 | RW | 0 | Second contact impulse accumulator (float, reset on overflow) |
| this | 0xC | RW | — | Scaled first impulse output (float, written on overflow normalization) |
| this | 0x10 | RW | — | Scaled second impulse output (float, written on overflow normalization) |

**Written-by note (persistence):**
- this 0x0: accumulative += a2 each call; reset to 0 on overflow. External poke overwritten on next accumulate.
- this 0x4: accumulative; reset to 0 on overflow. External poke lost on next overflow.
- this 0x8: accumulative; reset to 0 on overflow. External poke lost on next overflow.
- this 0xC: written only on overflow (impulse * 1/accumTime). External poke survives until next overflow.
- this 0x10: written only on overflow. External poke survives until next overflow.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | Overflow threshold constant for contact timer comparison |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Overflow guard: if accumulated time (this+0) does NOT overflow (float comparison against threshold), skip normalization (no reset, no output scaling). Overflow triggers when time exceeds threshold. Loop of 104 iterations always runs unconditionally.
