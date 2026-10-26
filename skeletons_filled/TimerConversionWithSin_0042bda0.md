## TimerConversionWithSin_0042bda0 — TimerMultiplyAndStore

**Summary:** Multiplies timer input a1 by 400.0, calls sin/computation helper, converts to integer, stores result in TimerOutputInt.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RunCollisionDetectionLoop (0045f390), SessionSynchronizer (0045f950)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e9b0 | dbl_59E9B0 | R | Rad2DegOrTimerMult [DERIVED] (also: ` — conversion multiplier) |
| 007c5694 | dword_7C5694 | W | TimerOutputInt [DERIVED] (also: ` — timer/angle output global) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | Convert double to integer (CRT _ftol equivalent) |
| 005895a2 | sub_5895A2 | Compute sin/cos of scaled timer value (side effect) |

**Guard conditions:** No guard conditions — unconditional computation, store, and return.
