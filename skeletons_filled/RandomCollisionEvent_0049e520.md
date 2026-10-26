## RandomCollisionEvent_0049e520 — Collision audio event dispatch

**Summary:** Triggers collision audio effect based on session time threshold. Calls InterruptDispatch with session time, then enables/disables audio source handle depending on time > 0.5s.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49D4C0 (0049d4c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (= 1.0) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] — 0.5 threshold constant |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] — used for threshold comparison |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049e4e0 | AudioEffectTrigger | triggers audio effect with enable flag (0=stop, 1=start) |
| 0058957a | InterruptDispatch | dispatches interrupt/event with session time |

**Guard conditions:** Compares `dbl_8AFEA0` (SessionTime) against 0.5: if <= 0.5, AudioEffectTrigger with 0 (stop); if > 0.5, AudioEffectTrigger with 1 (start).
