## CollisionContactSolver_0045c8f0 — ContactSolver

**Summary:** Processes a single collision contact: accumulates time, records impact when threshold exceeded, clamps contact time, and updates global contact counters. Part of collision response pipeline.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TeamRadioNetworkMessageProcessing (0045f710)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | Accumulated contact contribution sum |
| this | 0x8 | RW | — | Contact counter (incremented each call) |

**Written-by note (persistence):**
- this 0x4: additive accumulation each call; external poke survives until overwritten by next addition
- this 0x8: incremented each call; external poke overwritten on each call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] — conversion factor |
| 007d108c | flt_7D108C | R | MinPenetrationLimit [DERIVED] — minimum contact time boundary |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] — current session time, used as contact time ceiling |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045c7a0 | FloatToShortViaFtol | Converts float time-delta to short for ring buffer storage |
| 0045cbf0 | ShortArrayLookupAndZeroCheck | Checks/short array lookup; returns non-zero if adjustment needed |

**Guard conditions:** Contact index (first byte of a2) must be < 0x68 to process. If >= 0x68, skip contact processing entirely (counters still update). Inner guard: accumulated float at v4+109 must exceed 0.5 to trigger impact recording and counter increments.
