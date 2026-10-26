## SafeDivisionWithZeroGuard_00408450 — SafeDivisionWithZeroGuard

**Summary:** Computes safe reciprocal (1.0/a2) guarded against zero/negative input; resets timer to 0 and triggers clamp+dispatch on invalid input. Part of physics timing/integration system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MainMenuTransition (00404f30), ShortComputation_d410 (0040d410), sub_4A00A0 (004a00a0), sub_4A0250 (004a0250), LoadingPhase2 (004b8940)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | 0 | Timer/counter reset to 0 on each call |
| this | 0x8 | RW | 1065353216 → 1.0f | Reciprocal value (1.0/a2), or 1.0f safe fallback on invalid input |

**Written-by note (persistence):**
- this 0x4: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004082b0 | FloatClampWithEventDispatch | Clamps float value toward target and dispatches conditional events on invalid reciprocal input |

**Guard conditions:** a2 > 0.0 → compute 1.0/a2 into this[2]. a2 <= 0.0 → set this[2] = 1.0f (safe fallback), reset this[1] = 0, call FloatClampWithEventDispatch (clamp + event dispatch path).
